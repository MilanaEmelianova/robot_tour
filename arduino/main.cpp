#include <Arduino.h>
#include <MazeWriter>

int led1 = 9;
int led2 = 7;
int led3 = 2;

void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
}

// the loop function runs over and over again forever
void loop() {

  myCustomLED(led1);
  myCustomLED(led2);
  myCustomLED(led3);

}

void myCustomLED( int pin){
  digitalWrite(pin, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(1000);                       // wait for a second
  digitalWrite(pin, LOW);    // turn the LED off by making the voltage LOW
  delay(1000);

  
}