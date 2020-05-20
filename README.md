# Intensity correlator for Cyclone2 FPGAs

#### This repository contains code of an intensity correlator for the Cyclone II
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
+ 0x1d: Start integration by enabling UART transmission
+ 0x0d: Start integration by disabling UART transmission
+ 0x01: select active line in the upper nibble
+ 0x02: activate leds using 4th and 5th bits

###### The count of pulses and correlation comes with a 328-byte packet ended with a 0x0d character
###### Each packet starts with a header with payload length indication, it is possible to change some parameters from the code
+ byte 0-1: '00' ASCII characters (header start)
+ byte 2-3: hexadecimal sample size value
+ byte 4-5: hexadecimal inputs quantity
+ byte 6-7: hexadecimal delay lines quantity
+ byte 8-15: hexadecimal value of the active led lines
+ byte 16-63: pulses from inputs 12-1 in descending order in 4-byte big-endian hexadecimal ASCII text
+ byte 63-327: correlation between each input with others in 4-byte big-endian hexadecimal ASCII text

###### The sampling rate is the same as the packet rate
