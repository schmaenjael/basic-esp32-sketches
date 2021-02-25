
/*
   Author: schmaenjael
   Language:  C++ using the Arduino Library
   Github: https://github.com/schmaenjael/ESP32_SketchCollection
   Date: 14. January 2021
   Refernce: https://github.com/espressif/arduino-esp32/
*/

const byte red_LED = 33;   // initializing the red LED
const byte blue_LED = 27;  // initializing the blue LED
const byte green_LED = 15; // initializing the green LED
const byte VOUT_PIN = 32;  // initializing the VOUT Pin
const int FREQ = 5000;     // setting the frequence to 5000
int led_CHANNEL = 0;       // setting the LED_Channel to 0
int RES = 8;               // setting the resolution to 8

const byte m_T1 = 213; // sets the key T1 to a specific value
const byte m_T2 = 170; // sets the key T2 to a specific value
const byte m_T3 = 128; // sets the key T3 to a specific value
const byte m_T4 = 85;  // sets the key T4 to a specific value
const byte m_T5 = 39;  // sets the key T5 to a specific value
const byte m_T6 = 1;   // sets the key T6 to a specific value
unsigned int m = 0;    // sets the value of m to 0

void setup()
{
  pinMode(red_LED, OUTPUT);
  pinMode(blue_LED, OUTPUT);
  pinMode(green_LED, OUTPUT);

  digitalWrite(blue_LED, LOW);
  digitalWrite(green_LED, LOW);
  ledcSetup(led_CHANNEL, FREQ, RES);
  ledcAttachPin(red_LED, led_CHANNEL);
}

void loop()
{
  m = analogRead(VOUT_PIN) / 16;
  if (m > m_T1)
  {
    ledcWrite(led_CHANNEL, m - 1);
  }
  else if (m > m_T2)
  {
    ledcWrite(led_CHANNEL, m / 2);
  }
  else if (m > m_T3)
  {
    ledcWrite(led_CHANNEL, m / 3);
  }
  else if (m > m_T4)
  {
    ledcWrite(led_CHANNEL, m / 4);
  }
  else if (m > m_T5)
  {
    ledcWrite(led_CHANNEL, m / 5);
  }
  else if (m > m_T6)
  {
    ledcWrite(led_CHANNEL, m / 6);
  }
  else
  {
    ledcWrite(led_CHANNEL, m);
  }
}
