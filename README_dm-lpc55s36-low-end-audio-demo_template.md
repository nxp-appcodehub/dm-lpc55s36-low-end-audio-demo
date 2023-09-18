# NXP Application Code Hub
[<img src="https://mcuxpresso.nxp.com/static/icon/nxp-logo-color.svg" width="100"/>](https://www.nxp.com)

## LPC55S36 Low End Audio Demo

This example demo uses DAC output to generate low end audio through an external speaker.


#### Boards: LPCXpresso55S36
#### Categories: Audio, Voice
#### Peripherals: DAC, UART, USB
#### Toolchains: MCUXpresso IDE

## Table of Contents
1. [Software](#step1)
2. [Hardware](#step2)
3. [Setup](#step3)
4. [Results](#step4)
5. [FAQs](#step5) 
6. [Support](#step6)
7. [Release Notes](#step7)

## 1. Software<a name="step1"></a>
Install [MCUXpresso IDE v11.7.1+](https://nxp.com/mcuxpresso)

## 2. Hardware<a name="step2"></a>
Required board
*[LPCXpresso55S36 Development Board](https://www.nxp.com/design/software/development-software/mcuxpresso-software-and-tools-/lpcxpresso-boards/lpcxpresso55s36-development-board:LPCXpresso55S36)
* Mini/Micro USB cable
* LPCXpresso55S36 board
* Personal Computer
* Audio Adapter Cable
* 3.5 mm double sided audio cable
* Amplifier
* Speaker

## 3. Setup<a name="step3"></a>
For information on how to build and run the example please refer to the [LPC55S36 Getting Started Guide](https://www.nxp.com/document/guide/getting-started-with-the-lpc5536-lpc55s36-evaluation-board:GS-LPC55S36-EVK)

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



## 4. Results<a name="step4"></a>
When the demo runs successfully, the log would be seen on the OpenSDA terminal like:

Select a command from the list below to reproduce sound:
0 - Female Greeting\
1 - Happy Monday\
2 - Turn On\
3 - Turn Off\
4 - Play\
5 - Pause\
6 - Fast Forward\
7 - Rewind\
8 - Volume Up\
9 - Volume Down\

Pressing the corresponding key (0-9) will play the given sound.*

## 5. FAQs<a name="step5"></a>
No FAQs have been identified for this project

## 6. Support<a name="step6"></a>
*Provide URLs for help here.*

#### Project Metadata
<!----- Boards ----->
[![Board badge](https://img.shields.io/badge/Board-LPCXPRESSO55S36-blue)](https://github.com/search?q=org%3Anxp-appcodehub+LPCXpresso55S36+in%3Areadme&type=Repositories)

<!----- Categories ----->
[![Category badge](https://img.shields.io/badge/Category-AUDIO-yellowgreen)](https://github.com/search?q=org%3Anxp-appcodehub+audio+in%3Areadme&type=Repositories) [![Category badge](https://img.shields.io/badge/Category-VOICE-yellowgreen)](https://github.com/search?q=org%3Anxp-appcodehub+voice+in%3Areadme&type=Repositories)

<!----- Peripherals ----->
[![Peripheral badge](https://img.shields.io/badge/Peripheral-DAC-yellow)](https://github.com/search?q=org%3Anxp-appcodehub+dac+in%3Areadme&type=Repositories) [![Peripheral badge](https://img.shields.io/badge/Peripheral-UART-yellow)](https://github.com/search?q=org%3Anxp-appcodehub+uart+in%3Areadme&type=Repositories) [![Peripheral badge](https://img.shields.io/badge/Peripheral-USB-yellow)](https://github.com/search?q=org%3Anxp-appcodehub+usb+in%3Areadme&type=Repositories)

<!----- Toolchains ----->
[![Toolchain badge](https://img.shields.io/badge/Toolchain-MCUXPRESSO%20IDE-orange)](https://github.com/search?q=org%3Anxp-appcodehub+mcux+in%3Areadme&type=Repositories)

Questions regarding the content/correctness of this example can be entered as Issues within this GitHub repository.

>**Warning**: For more general technical questions regarding NXP Microcontrollers and the difference in expected funcionality, enter your questions on the [NXP Community Forum](https://community.nxp.com/)

[![Follow us on Youtube](https://img.shields.io/badge/Youtube-Follow%20us%20on%20Youtube-red.svg)](https://www.youtube.com/@NXP_Semiconductors)
[![Follow us on LinkedIn](https://img.shields.io/badge/LinkedIn-Follow%20us%20on%20LinkedIn-blue.svg)](https://www.linkedin.com/company/nxp-semiconductors)
[![Follow us on Facebook](https://img.shields.io/badge/Facebook-Follow%20us%20on%20Facebook-blue.svg)](https://www.facebook.com/nxpsemi/)
[![Follow us on Twitter](https://img.shields.io/badge/Twitter-Follow%20us%20on%20Twitter-white.svg)](https://twitter.com/NXP)

## 7. Release Notes<a name="step7"></a>
| Version | Description / Update                           | Date                        |
|:-------:|------------------------------------------------|----------------------------:|
| 1.0     | Initial release on Application Code Hub        | September 11<sup>th</sup> 2023 |

