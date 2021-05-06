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

TimerService::TimerService(int a, int b, bool c, void fn) {
  prescaler = a;
  hw_Timer_Pos = b;
  isEdge = c;
  &onTimer = fn;
}
