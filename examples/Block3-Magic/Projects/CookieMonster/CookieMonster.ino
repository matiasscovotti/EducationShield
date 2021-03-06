/*
* CookieMonster
* 
* Someone is eating our cookies, let's gather some proof
* about that person and get him/her to confess.
*
* (c) 2013-2016 Arduino LLC. B&D Cuartielles
*
* This code is Free Software, licensed under GPLv3
* Based on code by Paul Badger 2008
*
*/


#include <EducationShield.h>

//Define the capacitive sensor
CapacitiveSwitch sensor=CapacitiveSwitch(2,3);
//Use Tinkerkit LED(or Tinkerkit LED matrix) here.
//Deinfe the LED
int led = 9;

void setup()
{
   // configure the serial port
   Serial.begin(9600);

   //initialize components
   sensor.config(200);
   pinMode(led, OUTPUT);
 }

void loop(){
  //When someone attempts to open the
  //cookie jar, the sensor is activated
  if(sensor.pressed()){
    //Turn on the LED
    digitalWrite(9, HIGH);
    //Sends signal to processing, so a picture
    //will be captured
    Serial.print('p');
    //Wait 2 seconds before turning the LED off
    delay(2000);
    digitalWrite(9, LOW);
  }
}

