/*
 * Fire Control Group
 * Team 6
 * Programmer(s): Joel Tanner
 * 
 * Inputs and Outputs
 * Teensy 3.2
 * Ultrasonic Sensor
 * PWM Controlled Motor
 * SERIAL1 to Arduino Mega
 * Relay controled linear solenoid
 * Flywheel Encoder AMT102-V
 * 
 * Pinout:
 * SERIAL1 Port RX Pin 0
 * SERIAL1 Port TX Pin 1
 * Encoder Pins 2 and 3
 * Motor Control Pin 4
 * Ultrasonic Pins 5E and 6T
 * Relay Pin 7
 */

#include <Encoder.h>

void setup() {
  // Pin Setup
  Serial1.begin(112500);
  Encoder knobLeft(5, 6);
  pinMode(4, OUTPUT);
  pinMode(5, INPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  
}

void loop() {
  // put your main code here, to run repeatedly:

}

float rangeSensor(){
  float distance = 0;
  digitalWrite(6, LOW);
  delayMicroseconds(2);
  digitalWrite(6, HIGH);
  delayMicroseconds(10);
  digitalWrite(6, LOW);
  long duration = pulseIn(5, HIGH);
  distance = duration * 0.034 / 2;
  return distance;
}
