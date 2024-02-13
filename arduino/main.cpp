#include <Arduino.h>
#include <MazeWriter>
#include "RTC.h"

// add time tracking

int led1 = 9;
int led2 = 7;
int led3 = 2;

void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);

  Serial.begin(9600);

  RTC.begin();
  // change time
  RTCTime mytime(30, Month::JUNE, 2023, 13, 37, 00, DayOfWeek::WEDNESDAY, SaveLight::SAVING_TIME_ACTIVE);
  RTC.setTime(mytime);
}

// the loop function runs over and over again forever
void loop() {

  myCustomLED(led1);
  myCustomLED(led2);
  myCustomLED(led3);

  RTCTime currenttime;

 // Get current time from RTC
  RTC.getTime(currenttime);

  // Print time (MM/SS)
  Serial.print(currenttime.getMinutes());
  Serial.print(":");
  Serial.println(currenttime.getSeconds());

  delay(1000);

}

void myCustomLED( int pin){
  digitalWrite(pin, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(1000);                       // wait for a second
  digitalWrite(pin, LOW);    // turn the LED off by making the voltage LOW
  delay(1000);

  
}