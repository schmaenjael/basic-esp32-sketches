const byte red_LED = 33;
const byte blue_LED = 27;
const byte green_LED = 15;
const byte VOUT_PIN = 32;
const int FREQ = 5000;
int led_CHANNEL = 0;
int RES = 8;

const byte m_T1 = 213;
const byte m_T2 = 170;
const byte m_T3 = 128;
const byte m_T4 = 85;
const byte m_T5 = 39;
const byte m_T6 = 1;
int m = 0;

void setup()
{
  pinMode(red_LED, OUTPUT);
  pinMode(blue_LED, OUTPUT);
  pinMode(green_LED, OUTPUT);

  ledcSetup(led_CHANNEL, FREQ, RES);
  ledcAttachPin(red_LED, led_CHANNEL);
  digitalWrite(blue_LED, LOW);
  digitalWrite(green_LED, LOW);
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
    ledcWrite(led_CHANNEL, m);
    ;
  }
  else if (m > m_T3)
  {
    ledcWrite(led_CHANNEL, m);
  }
  else if (m > m_T4)
  {
    ledcWrite(led_CHANNEL, m);
  }
  else if (m > m_T5)
  {
    ledcWrite(led_CHANNEL, m);
  }
  else if (m > m_T6)
  {
    ledcWrite(led_CHANNEL, m);
  }
  else
  {
    ledcWrite(led_CHANNEL, m);
  }
}
