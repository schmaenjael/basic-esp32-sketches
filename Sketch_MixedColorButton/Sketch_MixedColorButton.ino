
/*
   Author: schmaenjael
   Language:  C++ using the Arduino Library
   Github: https://github.com/schmaenjael/ESP32_SketchCollection
   Date: 11. March 2021
   Refernce: https://github.com/espressif/arduino-esp32/
*/

const byte red_LED = 33;   // initializing the red LED
const byte blue_LED = 27;  // initializing the blue LED
const byte green_LED = 15; // initializing the green LED
const byte VOUT_PIN = 32;  // initializing the VOUT Pin
const int FREQ = 5000;     // setting the frequence to 5000
const byte GREEN_LED_CHANNEL = 0;       // setting the LED_Channel to 0
const byte BLUE_LED_CHANNEL = 1;       // setting the LED_Channel to 0
const byte RED_LED_CHANNEL = 2;       // setting the LED_Channel to 0
int RES = 8;                         // setting the resolution to 8

const byte m_T1 = 255; // sets the key T1 to a specific value
const byte m_T2 = 207; // sets the key T2 to a specific value
const byte m_T3 = 165; // sets the key T3 to a specific value
const byte m_T4 = 103; // sets the key T4 to a specific value
const byte m_T5 = 55;  // sets the key T5 to a specific value
const byte m_T6 = 30;  // sets the key T6 to a specific value
unsigned int m = 0;    // sets the value of m to 0

int red_Color = 0;
int green_Color = 0;
int blue_Color = 0;

// init setup function. This method will be called once on start
void setup()
{
  Serial.begin(115200);
  pinMode(red_LED, OUTPUT);
  pinMode(blue_LED, OUTPUT);
  pinMode(green_LED, OUTPUT);

  digitalWrite(red_LED, LOW);
  digitalWrite(blue_LED, LOW);
  digitalWrite(green_LED, LOW);

  ledcSetup(RED_LED_CHANNEL, FREQ, RES);
  ledcAttachPin(red_LED, RED_LED_CHANNEL);
  ledcSetup(BLUE_LED_CHANNEL, FREQ, RES);
  ledcAttachPin(blue_LED, BLUE_LED_CHANNEL);
  ledcSetup(GREEN_LED_CHANNEL, FREQ, RES);
  ledcAttachPin(green_LED, GREEN_LED_CHANNEL);
}

void loop()
{
  m = analogRead(VOUT_PIN) / 16;
  if (m == m_T1)
  {
    green_Color = 0;
    red_Color = 0;
    blue_Color = 0;
  }
  else if (m > m_T2 && m < m_T1)
  {
    red_Color = 125;
  }
  else if (m > m_T3 && m < m_T2)
  {
    blue_Color = 125;
  }
  else if (m > m_T4 && m < m_T3)
  {
    blue_Color = 125;
  }
  else if (m > m_T5 && m < m_T4)
  {
    green_Color = 85;
  }
  else if (m < m_T6 && m > 0)
  {
    red_Color = 255;
  }
    ledcWrite(GREEN_LED_CHANNEL, green_Color);
    ledcWrite(BLUE_LED_CHANNEL, blue_Color);
    ledcWrite(RED_LED_CHANNEL, red_Color);
    delay(200);
}
