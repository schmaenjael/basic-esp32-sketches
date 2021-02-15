/*
 * Author: schmaenjael
 * Language:  C++ using the Arduino Library
 * Github: https://github.com/schmaenjael/ESP32_SketchCollection
 * Date: 26. November 2020
 * Refernce: https://github.com/espressif/arduino-esp32/
 */

const int freq = 5000;    // Sets the frequency of the PWM-Channel
const int resolution = 8; // Setting the resolution

// Declaring informations for the blue LED and the PWM-Channel that controls the LED
const byte blue_LED = 27;       // Pin for the LED on the Color-Clicker Module
const int blue_dutyCycle = 255; // Configures the width of the signal
const int blue_ledChannel = 0;  // Creates the PWM-Channel for the blue LED

// Declaring informations for the red LED and the PWM-Channel that controls the LED
const byte red_LED = 33;       // Pin for the LED on the Color-Clicker Module
const int red_dutyCycle = 150; // Pin for the LED on the Color-Clicker Module
const int red_ledChannel = 1;  // Creates the PWM-Channel for the red LED

// Declaring informations for the green LED and the PWM-Channel that controls the LED
const byte green_LED = 15;      // Pin for the LED on the Color-Clicker Module
const int green_dutyCycle = 55; // Pin for the LED on the Color-Clicker Module
const int green_ledChannel = 2; // Creates the PWM-Channel for the green LED

// This code is executed once
void setup()
{
  // Configures the BLUE_LED
  ledcSetup(blue_ledChannel, freq, resolution); // Configures the PWM-Channel
  ledcAttachPin(blue_LED, blue_ledChannel);     // Attaches LED to the PWM-Channel
  ledcWrite(blue_ledChannel, blue_dutyCycle);   // enlightens the LED our preconfigured dutyCycle

  //Configures the RED_LED
  ledcSetup(red_ledChannel, freq, resolution); // Configures the PWM-Channel
  ledcAttachPin(red_LED, red_ledChannel);      // Attaches LED to the PWM-Channel
  ledcWrite(red_ledChannel, red_dutyCycle);    // enlightens the LED our preconfigured dutyCycle

  //Configures the GREEN_LED
  ledcSetup(green_ledChannel, freq, resolution); // Configures the PWM-Channel
  ledcAttachPin(green_LED, green_ledChannel);    // Attaches LED to the PWM-Channel
  ledcWrite(green_ledChannel, green_dutyCycle);  // enlightens the LED our preconfigured dutyCycle
}

void loop()
{
  // There is no loop required
}
