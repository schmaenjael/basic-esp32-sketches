#include <seg7.h>

#define serialMonitor 115200
#define initialSegmentState HIGH

Seg7 segDisplay;

void setup() {
  Serial.begin(serialMonitor);
  segDisplay.begin();
  segDisplay.toggle(initialSegmentState);
}

void loop() {
  segDisplay.display(15);
  delay(2000);
}
