# Intensity correlator with Cyclone2 FPGAs

#### This repository contains code for an intensity correlator with the Cyclone II
###### The board we suggest is the cheap Cyclone 2 dev board:

![alt text](https://github.com/iliaplatone/correlator/raw/master/pictures/devboard.jpg "Devboard")

###### This is the Verilog code to be built with Quartus II.
###### The generated SVF file can be downloaded to the device using urJTAG http://urjtag.org/
###### To use the correlator use INDI/KStars: https://indilib.org

###### This interferometer needs external hardware:
+ External PCB as amplifier boards of radio antennas
+ External PCB for APD or PMT connectors and power supply
+ External PCB for delay lines

###### The project runs at 50MHz and uses 230400 baud/second UART communication with the host
###### There is a set of commands to start integrations:
+ 0x1c: Start integration by enabling UART transmission
+ 0x01: 4 most significant bits used to sequentially update the integration time in nanoseconds
+ 0x02: 4 most significant bits used to sequentially update the switch array stored in active_line
+ 0x0d: Commit changes (end of line) or start integration

###### The count of pulses and correlation comes with a 328-byte packet ended with a 0x0d character
###### Each packet starts with a header with payload length indication, it is possible to change some parameters from the code
+ byte 0-1: '00' ASCII characters (header start)
+ byte 2-3: hexadecimal sample size value
+ byte 4-5: hexadecimal inputs quantity
+ byte 6-7: hexadecimal delay lines quantity
+ byte 8-15: hexadecimal value of the active switch lines
+ 16-63: pulses from inputs 12-1 in descending order in 4-byte big-endian hexadecimal ASCII text
+ byte 63-327: correlation between each input with others in 4-byte big-endian hexadecimal ASCII text

###### The sampling rate is the same as the packet rate
