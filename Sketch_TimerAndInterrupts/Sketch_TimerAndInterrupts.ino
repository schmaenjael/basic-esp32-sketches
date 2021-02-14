const byte red_LED = 33;
const int awaitTime = 1000000;
const bool countUp = true;
const bool isEdge = true;
const bool autoReload = true;
const byte prescaler = 100;
const byte hw_Timer_Pos = 0;
int flag = 0;

void IRAM_ATTR onTimer()
{
  if (flag % 2 == 0)
  {
    digitalWrite(red_LED, HIGH);
  }
  else
  {
    digitalWrite(red_LED, LOW);
  }
  flag++;
}

void setup()
{
  pinMode(red_LED, OUTPUT);

  hw_timer_t *timer = timerBegin(hw_Timer_Pos, prescaler, countUp);
  timerAttachInterrupt(timer, &onTimer, isEdge);
  timerAlarmWrite(timer, awaitTime, autoReload);
  timerAlarmEnable(timer);
}

void loop()
{
  // No main loop required to perform this action
}
