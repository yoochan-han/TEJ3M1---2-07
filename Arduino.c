/*
  created on Mar 2025
  by yoochan Han
  This program print distance in serial with SONAR
*/
#include <Servo.h>

Servo servoNumber1;
const int TRIG_PIN = 3;
const int ECHO_PIN = 2;
const float SPEED_OF_SOUND = 0.0343;

float duration;
float distance;

void setup() {
// setup servo pins
  servoNumber1.attach(4);
  servoNumber1.write(0);
// setup the SONAR
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  Serial.begin(9600);
}

void loop() {
  digitalWrite(TRIG_PIN, LOW);
    delayMicroseconds(2);
    digitalWrite(TRIG_PIN, HIGH);
    delayMicroseconds(10);
    digitalWrite(TRIG_PIN, LOW);

    duration = pulseIn(ECHO_PIN, HIGH);
    distance = (duration * SPEED_OF_SOUND)/2; //get distance in cm
    Serial.print("Distance : ");
    Serial.print(String(distance) + " cm\n");
    if(distance <= 50) {
  	// servo
    servoNumber1.write(180);
    delay(2000);
    servoNumber1.write(0);
    delay(2000);
    } else {
    delay(100);
    }
}
