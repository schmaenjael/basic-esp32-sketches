const char green_LED = 15;
const char blue_LED = 27;
const char red_LED = 33;

const char red_percent = 25;
const char blue_percent = 16;
const char green_percent = 0;

void setup()
{
  pinMode(red_LED, OUTPUT);
  pinMode(blue_LED, OUTPUT);
  pinMode(green_LED, OUTPUT);

  digitalWrite(green_LED, LOW);
}

void loop()
{
  for (char i = 0; i <= 100; i++)
  {
    if (i % blue_percent == 0)
    {
      digitalWrite(blue_LED, HIGH);
    }
    else
    {
      digitalWrite(blue_LED, LOW);
    }
    if (i % red_percent == 0)
    {
      digitalWrite(red_LED, HIGH);
    }
    else
    {
      digitalWrite(red_LED, LOW);
    }
    if (i % green_percent == 0)
    {
      digitalWrite(green_LED, HIGH);
    }
    else
    {
      digitalWrite(green_LED, LOW);
    }

    delayMicroseconds(1);
  }
}
int main(void)
{
  setup();

  for (;;)
  {
    // Control job

    loop();
  }
}
