/*
 * Author: schmaenjael
 * Language:  C++ using the Arduino Library
 * Github: https://github.com/schmaenjael/ESP32_SketchCollection
 * Date: 05. May 2021
 * Refernce: https://github.com/espressif/arduino-esp32/
 */

#include <SPI.h>

#define slaveSelect 1
#define delayTime 50

void setup() {
    pinMode(slaveSelect, OUTPUT);
    SPI.begin();
    SPI.setBitOrder(LSBFIRST);
    Serial.begin(11200)
}

void loop() {
    for (int i; i < 256; i++) {
        digitalWrite(slaveSelect, LOW);
        SPI.transfer(i);
        digitalWrite(slaveSelect, HIGH);
        delay(delayTime);
    }
}