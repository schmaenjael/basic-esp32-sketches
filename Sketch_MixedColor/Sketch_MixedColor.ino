/*
 * Author: schmaenjael
 * Language:  C++ using the Arduino Library
 * Github: https://github.com/schmaenjael/ESP32_SketchCollection
 * Date: 26. November 2020
 * Refernce: https://github.com/espressif/arduino-esp32/
 */

/*
*  IMPORTANT NOTE: The instructions for this sketch was to NOT use Pulsewidthmodulation to mix the colors on the color click module, instead we chose 
*  the slumpy way to handle things and just called the digitalWrite() method multiple times to get the same effect. 
*  Please don't avoid this hell if possible!
*/

const byte GREEN_LED = 15; //  initializing the green LED
const byte BLUE_LED = 27;  //  initializing the blue LED
const byte RED_LED = 33;   //  initializing the red LED

const byte MAX_PERCENT = 100;
const byte RED_LED_PERCENT = 25;
const byte BLUE_LED_PERCENT = 16;
const byte GREEN_LED_PERCENT = 0;

/*
* The setup() method configures the pin mode for the light-emitting diodes to OUTPUT and sets the GREEN_LED on startup to LOW.
*/
void setup()
{
  pinMode(RED_LED, OUTPUT);
  pinMode(BLUE_LED, OUTPUT);
  pinMode(GREEN_LED, OUTPUT);

  digitalWrite(GREEN_LED, LOW);
}

int main(void)
{
  setup();
  // calls an endless loop
  for (;;)
  {
    // Control job

    loop();
  }
}
