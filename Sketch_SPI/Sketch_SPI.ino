/*
   Author: schmaenjael
   Language:  C++ using the Arduino Library
   Github: https://github.com/schmaenjael/ESP32_SketchCollection
   Date: 05. May 2021
   Refernce: https://github.com/espressif/arduino-esp32/
*/

#define PWM 27
#define MR 4
#define MOSI 23
#define SHCP 18
#define STCP 15
#define DELAY 1000


void setup() {
  Serial.begin(115200);

  pinMode(MOSI, OUTPUT);
  pinMode(MR, OUTPUT);
  pinMode(PWM, OUTPUT);
  pinMode(SHCP, OUTPUT);
  pinMode(STCP, OUTPUT);

  digitalWrite(PWM, HIGH);
  digitalWrite(MR, HIGH);
}

const int EIGHT[18] = { HIGH, HIGH, HIGH, HIGH, HIGH, HIGH, HIGH, HIGH, HIGH, HIGH, HIGH, HIGH, HIGH, HIGH, HIGH, HIGH, HIGH, HIGH };

void loop() {
  for (int i = 0; i < 18; i++) {
    digitalWrite(SHCP, LOW);
    digitalWrite(MOSI, EIGHT[i]);
    digitalWrite(SHCP, HIGH);
  }
  digitalWrite(STCP, HIGH);
  delay(DELAY);
}
