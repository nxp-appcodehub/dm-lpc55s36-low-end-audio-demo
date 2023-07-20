Overview
========

This application code is designed to demonstrate low end audio application for the LPCXpresso55S36 Evaluation Kit.

Toolchain supported
===================
- IAR embedded Workbench  9.10.2
- Keil MDK  5.34
- GCC ARM Embedded  10.2.1
- MCUXpresso  11.4.0

Hardware requirements
=====================
- Mini/Micro USB cable
- LPCXpresso55S36 board
- Personal Computer
- Audio Adapter Cable
- 3.5 mm double sided audio cable
- Amplifier
- Speaker

Board settings
==============
DAC output pin: J12-4

Prepare the Demo
================
1.  Connect a USB cable between the PC host and the OpenSDA USB port on the board.
2.	Connect the right channel wire of the audio jack adapter to the DAC out receptacle on the board (note that left channel can also be used)
3.	Connect the ground wire to the GND receptacle on the board
4.	The pins for DAC out and GND are on the front side of the board, and the receptacles match on the back side of the board.
5.	Connect 3.5 mm double sided audio cable to the amplifier / speaker

2.  Open a serial terminal on PC for OpenSDA serial device with these settings:
    - 115200 baud rate
    - 8 data bits
    - No parity
    - One stop bit
    - No flow control
3.  Download the program to the target board.
4.  Either press the reset button on your board or launch the debugger in your IDE to begin running the demo.

Running the demo
================
When the demo runs successfully, the log would be seen on the OpenSDA terminal like:

Select a command from the list below to reproduce sound:
0 - Female Greeting
1 - Happy Monday
2 - Turn On
3 - Turn Off
4 - Play
5 - Pause
6 - Fast Forward
7 - Rewind
8 - Volume Up
9 - Volume Down

Pressing the corresponding key (0-9) will play the given sound.

