

/***** FILE BTN9990_9970_dc_motor_control_example.ino  ***********
*
* Revision: 0.2 Preliminary
* Copyright (c) Infineon Technologies AG
* All rights reserved.
* 
*
* USE      :     BTN9970LV/BTN9990LV Motor Control Shield 
*                Board: BTN99xx NovalithIC+
*                Board version: 1.1 / 1.2
*                Arduino Shield for Evaluation 
*                Arduino UNO µC board  (not included, need to be ordered separately)
*                This code is experimental and for evaluation and demonstration purpose only and not intended for usage in real applications.
*                
* COMPILE  :     with compiler from Arduino
*
* LINK     :     Arduino development environment
*
* DESCRIPTION:     
*                The board is equipped with 1 x BTN9990 and 1 x BTN9970 NovalithIC+ PN half-bridge with integrated Driver IC. 
*                This Demo Software drives a brushed DC Motor in both directions and increases and decreases the motor speed.
*                The DC brush motor need to be connected between the outputs OUT1 and OUT2 of both half bridges of BTN9970 and BTN9990.
*                
*                Diagnostic, Sense current feedback and Slew rate programming not included in this code.
* 
*                For proper connection to power supply and usage of the board, please refer to manual "BTN9970/BTN9990 Motor control Shield".
*                Libraries such as for TimerOne need to be imported by the user.
*                 
* 

***********************************************************************/





#include <TimerOne.h>

/* Sketch to drive Brushed DC-Motor in two directions. */

#define  IS_1   0   // Diagnosis 1. Current sensing, temperature sensing, slew rate setting of device 1.
#define  IS_2   1   // Diagnosis 2. Current sensing, temperature sensing, slew rate setting of device 2.
#define  INH_1  3   // Inhibit 1. When set to low device 1 goes in tristate.
#define  IN_1   10  // Input 1. Defines wheather high- (1) or low-side (0) switch of device 1 is activated.
#define  INH_2  13  // Inhibit 2. When set to low device 2 goes in tristate.
#define  IN_2   9   // Input 2. Defines wheather high- (1) or low-side (0) switch of device 2 is activated.

#define TCONST 20 // Delay time between accelerating/deceleration steps in fade_motor function


int motor_dc     = 0; // Actual duty cycle when fading the motor in % (don't change, will be overwritten in fade_motor function)
int motor_dc_max = 80;  // Max duty cycle in %

int i = 0;

const int period = 50; // Period length of the PWM signal in us, 50us = 20kHz


void setup() 
{
  /* Set up device input and inhibit pins as MCU output */
  pinMode(IN_1,OUTPUT);
  pinMode(IN_2,OUTPUT);
  pinMode(INH_1,OUTPUT);
  pinMode(INH_2,OUTPUT);
  
  /* Set up device diagnosis pins as MCU input (not further used in this example) */
  pinMode(IS_1,INPUT);
  pinMode(IS_2,INPUT);
}  


void reset_pins()
 {
  /*
  Reset all output pins to default state:
  Devices go in tristate (high impedance at devices' power output).
  */
  digitalWrite(INH_1,0);
  digitalWrite(IN_1,0);
  digitalWrite(INH_2,0);
  digitalWrite(IN_2,0);
  delayMicroseconds(300); // Device in sleep mode , device will start with slew rate 0 (SR0) when powered up again
 }


void fade_motor(int pin)
{
  Timer1.initialize(period);
  Timer1.pwm(pin,0,period);
  
  // Accelerate motor by increasing PWM duty cycle:
  for(unsigned int i = 0; i < motor_dc_max; i++)
  {
   motor_dc = map( i , 0 , 100 , 0 , 1023 );  // Translate 0-100% scale to 0-1023 (10 bit) scale (100% = 1023)
   Timer1.pwm(pin,motor_dc,period); // Use Timer1 to enable PWM output at the selected pin
   delay(TCONST);
  }

  // Slow down motor by decreasing PWM duty cycle:
  for(unsigned int i = motor_dc_max; i >= 0; i--)
  {
  motor_dc = map( i , 0 , 100 , 0 , 1023 );
  Timer1.pwm(pin,motor_dc,period);
  delay(TCONST);
  }

  Timer1.disablePwm(pin); // Disable PWM signal on selected pin
  digitalWrite(pin,0); // Set the selected pin back to digital low
 
}
void loop()
{
  reset_pins(); // Put device into sleep mode and pull pins IN and INH to low, SR0 will be active after power up
  
  // Wake up devices:
  digitalWrite(INH_2,1);
  digitalWrite(INH_1,1);

  fade_motor(IN_1); // Accelerate and decelerate motor in forward direction (device 1 high, device 2 low)
  delay(1000);
  
  fade_motor(IN_2); // Accelerate and decelerate motor in backward direction (device 2 high, device 1 low)
  delay(1000);
 }

 
