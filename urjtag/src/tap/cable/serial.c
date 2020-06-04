/*
 * (C) Copyright 2010
 * Stefano Babic, DENX Software Engineering, sbabic@denx.de.
 * Serial JTAG Cable Driver
 *
 * Based on TS7800 Serial JTAG Cable Driver
 * Copyright (C) 2008 Catalin Ionescu
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.     See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA
 * 02111-1307, USA.
 *
 */

#include <sysdep.h>

#include <stdlib.h>
#include <string.h>

#include <errno.h>
#include <fcntl.h>
#include <unistd.h>

#include <urjtag/cable.h>
#include <urjtag/parport.h>
#include <urjtag/chain.h>
#include <urjtag/cmd.h>

#include "generic.h"

#define SERIAL_PATH          "/dev/ttyUSB0"

/* pin mapping */
enum {
    SERIAL_UNSET = -1,
    SERIAL_TCK = 0,
    SERIAL_TDI,
    SERIAL_TDO,
    SERIAL_TMS,
    SERIAL_REQUIRED
};

typedef struct {
    int          fd;
    int          signals;
    uint32_t     lastout;
} serial_params_t;

static int fd = -1;
static char serial_value = 0;
static int serial_set_pin (urj_cable_t *cable, int pin, int value)
{
    ssize_t ret;
    serial_params_t *p = cable->params;
    serial_value &= ~(1 << pin);
    serial_value |= value << pin;

    ret = write (p->fd, &serial_value, 1);

    if (ret != 1)
    {
        urj_warning (_("Error setting value of pin %u: %d\n"), pin, ret);
        return URJ_STATUS_FAIL;
    }

    return URJ_STATUS_OK;
}

static int serial_get_pin (urj_cable_t *cable, int pin)
{
    ssize_t ret;
    char value;
    serial_params_t *p = cable->params;

    ret = read (p->fd, &value, 1);
    printf ("%1d", (value & (1 << pin)) != 0);

    if (ret != 1)
    {
        urj_warning (_("Error getting value of pin %u: %d\n"), pin, ret);
        return URJ_STATUS_FAIL;
    }

    return (value & (1 << pin)) != 0;
}

static int
serial_open (urj_cable_t *cable)
{
    serial_params_t *p = cable->params;
    int ret = -1;
    char fname[50];
    strcpy(fname, SERIAL_PATH);
    ret = open(fname, O_RDWR);
    if (ret == -1)
    {
        urj_warning (_("Error opening port %s\n"), fname);
        return URJ_STATUS_FAIL;
    }
    p->fd = ret;
    return URJ_STATUS_OK;
}

static int
serial_close (urj_cable_t *cable)
{
    serial_params_t *p = cable->params;
    close(p->fd);
    return URJ_STATUS_OK;
}

static void
serial_help (urj_log_level_t ll, const char *cablename)
{
    urj_log (ll,
        _("Usage: cable %s tdi=<serial_tdi> tdo=<serial_tdo> "
        "tck=<serial_tck> tms=<serial_tms>\n"
        "\n"), cablename);
}

static int
serial_connect (urj_cable_t *cable, const urj_param_t *params[])
{
    serial_params_t *cable_params;
    int i;

    cable_params = calloc (1, sizeof (*cable_params));
    if (!cable_params)
    {
        urj_error_set (URJ_ERROR_OUT_OF_MEMORY, _("calloc(%zd) fails"),
                       sizeof (*cable_params));
        free (cable);
        return URJ_STATUS_FAIL;
    }

    urj_log (URJ_LOG_LEVEL_NORMAL,
        _("Initializing Serial JTAG Chain\n"));


    cable->params = cable_params;
    cable->chain = NULL;
    cable->delay = 1000;

    return URJ_STATUS_OK;
}

static void
serial_disconnect (urj_cable_t *cable)
{
    urj_tap_chain_disconnect (cable->chain);
    serial_close (cable);
}

static void
serial_cable_free (urj_cable_t *cable)
{
    free (cable->params);
    free (cable);
}

static int
serial_init (urj_cable_t *cable)
{
    serial_params_t *p = cable->params;

    if (serial_open (cable) != URJ_STATUS_OK)
        return URJ_STATUS_FAIL;

    p->signals = URJ_POD_CS_TRST;

    return URJ_STATUS_OK;
}

static void
serial_done (urj_cable_t *cable)
{
    serial_close (cable);
}

static void
serial_clock (urj_cable_t *cable, int tms, int tdi, int n)
{
    serial_params_t *p = cable->params;
    int i;

    tms = tms ? 1 : 0;
    tdi = tdi ? 1 : 0;

    serial_set_pin (cable, SERIAL_TMS, tms);
    serial_set_pin (cable, SERIAL_TDI, tdi);

    for (i = 0; i < n; i++)
    {
        serial_set_pin (cable, SERIAL_TCK, 0);
        serial_set_pin (cable, SERIAL_TCK, 1);
        serial_set_pin (cable, SERIAL_TCK, 0);
    }
}

static int
serial_get_tdo ( urj_cable_t *cable )
{
    serial_params_t *p = cable->params;

    serial_set_pin (cable, SERIAL_TCK, 0);
    serial_set_pin (cable, SERIAL_TDI, 0);
    serial_set_pin (cable, SERIAL_TMS, 0);
    p->lastout &= ~(URJ_POD_CS_TMS | URJ_POD_CS_TDI | URJ_POD_CS_TCK);

    urj_tap_cable_wait (cable);

    return serial_get_pin (cable, SERIAL_TDO);
}

static int
serial_current_signals (urj_cable_t *cable)
{
    serial_params_t *p = cable->params;

    int sigs = p->signals & ~(URJ_POD_CS_TMS | URJ_POD_CS_TDI | URJ_POD_CS_TCK);

    if (p->lastout & URJ_POD_CS_TCK) sigs |= URJ_POD_CS_TCK;
    if (p->lastout & URJ_POD_CS_TDI) sigs |= URJ_POD_CS_TDI;
    if (p->lastout & URJ_POD_CS_TMS) sigs |= URJ_POD_CS_TMS;

    return sigs;
}

static int
serial_set_signal (urj_cable_t *cable, int mask, int val)
{
    int prev_sigs = serial_current_signals (cable);
    serial_params_t *p = cable->params;

    mask &= (URJ_POD_CS_TDI | URJ_POD_CS_TCK | URJ_POD_CS_TMS); // only these can be modified

    if (mask != 0)
    {
        if (mask & URJ_POD_CS_TMS)
            serial_set_pin (cable, SERIAL_TMS, val & URJ_POD_CS_TMS);
        if (mask & URJ_POD_CS_TDI)
            serial_set_pin (cable, SERIAL_TDI, val & URJ_POD_CS_TDI);
        if (mask & URJ_POD_CS_TCK)
            serial_set_pin (cable, SERIAL_TCK, val & URJ_POD_CS_TCK);
    }

    p->lastout = val & mask;

    return prev_sigs;
}

static int
serial_get_signal (urj_cable_t *cable, urj_pod_sigsel_t sig)
{
    return (serial_current_signals (cable) & sig) ? 1 : 0;
}

const urj_cable_driver_t urj_tap_cable_serial_driver = {
    "serial",
    N_("Serial port JTAG Chain"),
    URJ_CABLE_DEVICE_OTHER,
    { .other = serial_connect, },
    serial_disconnect,
    serial_cable_free,
    serial_init,
    serial_done,
    urj_tap_cable_generic_set_frequency,
    serial_clock,
    serial_get_tdo,
    urj_tap_cable_generic_transfer,
    serial_set_signal,
    serial_get_signal,
    urj_tap_cable_generic_flush_one_by_one,
    serial_help
};
