# Multiplo N6 Core
An Arduino core for the MutiploN6 robot from [RobotGroup](www.robotgroup.com.ar), all running [Optiboot 6](https://github.com/Optiboot/optiboot). Major libraries such as SD, Servo, SPI and Wire are modified to work with this core. Still, a large amount of third-party libraries often works without any modifications. 
<br/> <br/>
This core requires at least Arduino IDE v1.6, where v1.6.5+ is recommended. 
<br/>

<br/> <br/>

##Supported microcontrollers
* ATmega1284*

(* all variants - P. Select the correct version in the 'Variant' menu)

##Supported clock frequencies
* 20 MHz external oscillator
* 16 MHz external oscillator (default)
* 8 MHz external oscillator
* 8 MHz internal oscillator
* 1 MHz internal oscillator 
 
Select your microcontroller in the boards menu, then select the clock frequency. You'll have to hit "Burn bootloader" in order to set the correct fuses and upload the correct bootloader. <br/>
Make sure you connect an ISP programmer, and select the correct one in the "Programmers" menu. For time critical operations an external oscillator is recommended.

##BOD option
Brown out detection, or BOD for short lets the microcontroller sense the input voltage and shut down if the voltage goes below the brown out setting. For microcontrollers with an extended fuse like the 1284p, there is a separate BOD option. To change the BOD settings you'll have to connect an ISP programmer and hit "Burn bootloader".

##Pinout
This core got two different pinout option. The default one is named "Standard", and is based on the original AVR pinout. The other one is named "Bobuino" and is basically an Arduino UNO pinout setting. This pinout version is great for using with shields or code that's written for the Arduino UNO, as the pin functions stays the same (MOSI on D11, MISO on D12, SCK on D13). Please have a look at the (`pins_arduino.h`) files for more info. Pick your favorite!</br> </br>
<b>Click to enlarge:</b> 
</br> </br>
<img src="http://i.imgur.com/hZGMRwH.png" width="375"> <img src="http://i.imgur.com/9cpfTGl.png" width="430">
</br> </br>
<img src="http://i.imgur.com/PF1HWho.png" width="375"> <img src="http://i.imgur.com/fHC5LQK.png" width="430">

##How to install
#### Boards Manager Installation
This installation method requires Arduino IDE version 1.6.4 or greater.
* Open the Arduino IDE.
* Open the **File > Preferences** menu item.
* Enter the following URL in **Additional Boards Manager URLs**: `https://raw.githubusercontent.com/Robots-Linti/Multiplo/master/package_SoporteLihuen_MultiploN6Max_index.json`
* Open the **Tools > Board > Boards Manager...** menu item.
* Wait for the platform indexes to finish downloading.
* Scroll down until you see the **MultiploN6-Max** entry and click on it.
  * **Note**: If you are using Arduino IDE 1.6.6 then you may need to close **Boards Manager** and then reopen it before the **MultiploN6-Max** entry will appear.
* Click **Install**.
* After installation is complete close the **Boards Manager** window.
