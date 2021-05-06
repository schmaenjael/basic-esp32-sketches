/*
 * Author: schmaenjael
 * Language:  C++ using the Arduino Library
 * Github: https://github.com/schmaenjael/ESP32_SketchCollection
 * Date: 21. January 2021
 * Refernce: https://github.com/espressif/arduino-esp32/
 */

const byte red_LED = 33;       // Pin for the LED on the Color-Clicker Module
const byte green_LED = 15;     // Pin for the LED on the Color-Clicker Module
const int awaitTime = 166666;  // time it waits until it triggeres the alarm
const bool countUp = true;     // sets the count direction --> counting upwards
const bool isEdge = true;      // to set the interrupt type to 'edge'
const bool autoReload = true;  // used to let the alarm reload and generate it periodically
const byte prescaler = 80;     // sets the prescaler to 80 -> it reduces the usually written timer by 100
const byte hw_Timer_Pos = 0;   
hw_timer_t *timer = NULL;     // used to set the position of the timer to 0. Valid options vary between 0 and 3. if hw_Timer_Pos > 3 --> return NULL;
volatile int flag = 0;         // the flag variable is used in the method below that is pointed to on timerAttachInterrupt()

class TimerService {
  private: hw_timer_t *timer = NULL;
  public: 
    int prescaler, hw_Timer_Pos;
    bool isEdge;
    void (*fn)(void);
  
  public:
    TimerService(int, int, bool, void);
    void createTimer() {
      timer = timerBegin(hw_Timer_Pos, prescaler, countUp);
      timerAttachInterrupt(timer, (*fn), isEdge);
    }
    void writeAlarm(int awaitTime, bool autoReload) {
      timerAlarmWrite(timer, awaitTime, autoReload);
    }
    void enableAlarm() {
      timerAlarmEnable(timer);
    }
};


TimerService::TimerService(int a, int b, bool c, void (*fn)) {
  prescaler = a;
  hw_Timer_Pos = b;
  isEdge = c;
  &onTimer = (*fn);
}

void IRAM_ATTR onTimer()
{
  if (flag % 2 == 0)
  {
    digitalWrite(red_LED, HIGH); // sets the current voltage state to HIGH (1)
  }
  else
  {
    digitalWrite(red_LED, LOW); // sets the current voltage state to LOW (0)
  }
  flag++; // increments flag by one, is equal to flag += 1;
}

void setup()
{
  pinMode(red_LED, OUTPUT);
  pinMode(green_LED, OUTPUT);
  
  digitalWrite(green_LED, LOW);
  
  TimerService redTimer(prescaler, hw_Timer_Pos, isEdge, &onTimer);
  
  redTimer.writeAlarm(awaitTime, autoReload);
  redTimer.enableAlarm();
}

void loop() {}
