# DC Motor Control Shield with BTN9970LV and BTN9970LV Arduino examples

This repository contains application examples for the following Infineon DC Motor Control Shield compatible with Arduino UNO form factor microcontroller boards:

* DC Motor Control Shield with BTN9970LV and BTN9970LV [DC-SHIELD_BTN9970LV](https://www.infineon.com/cms/de/product/evaluation-boards/dc-shield_btn9970lv/)

<img src="https://www.infineon.com/export/sites/default/_images/product/evaluation-boards/BTN99xxNovalithIC-.png_1304862384.png" width=400>

The following example applications are provided:

* DC Motor Control Example - [BTN9990_9970_dc_motor_control_example](BTN9990_9970_dc_motor_control_example)

## :warning: Important notice :warning:

Working with power applications involving high currents and batteries can be hazardous in many ways when handled incorrectly.
Before getting your hands on the hardware be sure that you know the necessary safety rules to deal with power electronic applications, and that you have carefully read the product [user guide](docs/Infineon-BTN9990_9970_Motor_control_shield-UM-v1_1-EN.pdf).

## Hardware requirements

* DC Motor Control Shield with BTN9970LV and BTN9970LV [DC-SHIELD_BTN9970LV](https://www.infineon.com/cms/de/product/evaluation-boards/dc-shield_btn9970lv/)
* Arduino UNO board
* External power supply
* DC motor

## Software requirements

* Arduino IDE 1.8.13 (or higher)

All the supporting libraries required by the example sketches (other then the Arduino AVR core) are included within the example project folder. 

## Getting started

* Download and install the Arduino IDE from [here](https://www.arduino.cc/en/software).
* Open your Arduino IDE and go to Sketch > Include Library > Manage Libraries... and install the TimerOne library.
* Download one of the application examples from this repository and open it in your Arduino IDE.
* Stack your DC Motor Control Shield onto your Arduino Uno and connect it to your power supply and motor. Make sure to read the [user guide](docs/Infineon-BTN9990_9970_Motor_control_shield-UM-v1_1-EN.pdf) first.
* Connect your Arduino Uno to your computer and upload the example code to it.

## Useful links

* [DC-SHIELD_BTN9970LV Product Page](https://www.infineon.com/cms/de/product/evaluation-boards/dc-shield_btn9970lv/)
* [BTN9970LV Product Page](https://www.infineon.com/cms/en/product/power/motor-control-ics/brushed-dc-motor-driver-ics/single-half-bridge-ics/btn9970lv/)
* [BTN9990LV Product Page](https://www.infineon.com/cms/en/product/power/motor-control-ics/brushed-dc-motor-driver-ics/single-half-bridge-ics/btn9990lv/)
* [Infineon Single Half-Bridge ICs](https://www.infineon.com/cms/en/product/power/motor-control-ics/brushed-dc-motor-driver-ics/single-half-bridge-ics/)