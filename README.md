# AHP Intensity correlator with Cyclone2 FPGAs

#### This repository contains code for an intensity correlator for the Cyclone II
###### The board we suggest is the cheap Cyclone 2 dev board:

![alt text](https://github.com/iliaplatone/correlator/raw/master/pictures/devboard.jpg "Devboard")

###### This is the Verilog code to be built with Quartus II.
###### The generated SVF file can be downloaded to the device using urJTAG http://urjtag.org/
###### To use the correlator use INDI/KStars: https://indilib.org

###### This interferometer needs external hardware:
+ External PCB as amplifier boards of radio antennas
+ External PCB for APD or PMT connectors and power supply
+ External PCB for delay lines

###### The project runs at 50MHz and uses 2Mbaud/second UART communication with the host
###### There is a set of commands to start integrations:
+ 0x1c: Start UART communication leaving correlation unchanged
+ 0x2c: Start correlation without UART communication
+ 0x3c: Start integration by enabling both UART and correlator
+ 0x01: Upper 4 bits used to sequentially update the sampling time
+ 0x0d: Commit changes (end of line)

###### The count of pulses and correlation comes with a 315-byte packet ended with a 0x0d character
+ byte 0-39: pulses from inputs 14-1 in descending order in 3-byte hexadecimal numbers
+ byte 39-315: correlation between each input with others in 3-byte hexadecimal numbers

###### The integration rate is the same as the packet rate

