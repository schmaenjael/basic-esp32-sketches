# 1 "d:\\Informatik_Dateien\\IT\\Programmiersprachen_Runtime\\Arduino\\ESP32_SketchCollection\\Sketch_Project\\src\\Sketch_Project.ino"
# 2 "d:\\Informatik_Dateien\\IT\\Programmiersprachen_Runtime\\Arduino\\ESP32_SketchCollection\\Sketch_Project\\src\\Sketch_Project.ino" 2
# 3 "d:\\Informatik_Dateien\\IT\\Programmiersprachen_Runtime\\Arduino\\ESP32_SketchCollection\\Sketch_Project\\src\\Sketch_Project.ino" 2
# 4 "d:\\Informatik_Dateien\\IT\\Programmiersprachen_Runtime\\Arduino\\ESP32_SketchCollection\\Sketch_Project\\src\\Sketch_Project.ino" 2
# 5 "d:\\Informatik_Dateien\\IT\\Programmiersprachen_Runtime\\Arduino\\ESP32_SketchCollection\\Sketch_Project\\src\\Sketch_Project.ino" 2

Adafruit_BME280 bme; // use I2C interface
Adafruit_Sensor *bme_temp = bme.getTemperatureSensor();
Adafruit_Sensor *bme_pressure = bme.getPressureSensor();
Adafruit_Sensor *bme_humidity = bme.getHumiditySensor();

void setup()
{
  Serial.begin(115200);
  Serial.println(((reinterpret_cast<const __FlashStringHelper *>(("BME280 Sensor event test")))));

  if (!bme.begin())
  {
    Serial.println(((reinterpret_cast<const __FlashStringHelper *>(("Could not find a valid BME280 sensor, check wiring!")))));
    while (1)
      delay(10);
  }

  bme_temp->printSensorDetails();
  bme_pressure->printSensorDetails();
  bme_humidity->printSensorDetails();
}

void loop()
{
  sensors_event_t temp_event, pressure_event, humidity_event;
  bme_temp->getEvent(&temp_event);
  bme_pressure->getEvent(&pressure_event);
  bme_humidity->getEvent(&humidity_event);

  Serial.print(((reinterpret_cast<const __FlashStringHelper *>(("Temperature = ")))));
  Serial.print(temp_event.temperature);
  Serial.println(" *C");

  Serial.print(((reinterpret_cast<const __FlashStringHelper *>(("Humidity = ")))));
  Serial.print(humidity_event.relative_humidity);
  Serial.println(" %");

  Serial.print(((reinterpret_cast<const __FlashStringHelper *>(("Pressure = ")))));
  Serial.print(pressure_event.pressure);
  Serial.println(" hPa");

  Serial.println();
  delay(1000);
}
