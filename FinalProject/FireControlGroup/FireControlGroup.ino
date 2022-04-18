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

Encoder flywheelEnc(2, 3);

void setup() {
  // Pin Setup
  Serial1.begin(112500);
  Serial.begin(112500);
  pinMode(4, OUTPUT);
  pinMode(5, INPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);

  pinMode(12, INPUT);
  pinMode(13, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(13, digitalRead(12));
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

float kP = 0.0;
float kI = 0.0;
float kD = 0.0;
float integral = 0.0;
long lastEncoderValue = 0;
float lastError = 0.0;

float speedCalculate(){
  int ticksPerRev = 1000;
  int calcFreq = 1000;
  long encoderValue = flywheelEnc.read();
  long tickChange = encoderValue - lastEncoderValue;
  lastEncoderValue = encoderValue;
  float flywheelSpeed = (float)(tickChange / ticksPerRev) * (float)(calcFreq);
  return flywheelSpeed;
}

int pidCalculate(float targetRPS){
  int motorPWM = 0;
  //Calc Error
  float error = targetRPS - speedCalculate();

  //Calc Proportional
  float P = error * kP;

  //Calc Integral
  integral += error;
  float I = integral * kI;

  //Calc Derivative
  float derivative = error - lastError;
  float D = derivative * kD;

  //Sum PID Terms
  motorPWM = P + I + D;

  //Limit motor output
  motorPWM = motorPWM > 255 ? 255 : motorPWM < 0 ? 0 : motorPWM;

  //Update last error and return pwm value
  lastError = error;
  return motorPWM;
}
