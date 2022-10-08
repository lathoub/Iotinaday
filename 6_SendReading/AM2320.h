//    FILE: AM2320.ino
//  AUTHOR: Rob Tillaart
// PURPOSE: AM2320 demo sketch for AM2320 I2C humidity & temperature sensor
//
//  AM232X PIN layout             AM2315 COLOR   PIN
//  ==================================================
//   bottom view  DESCRIPTION     COLOR
//       +---+
//       |o  |       VDD          RED
//       |o  |       SDA          YELLOW          D2
//       |o  |       GND          BLACK
//       |o  |       SCL          GREY            D1
//       +---+
//
// do not forget pull up resistors between SDA, SCL and VDD..


#include "AM232X.h" // via library manager Rob Tillaar

AM232X AM2320;

void setupSensors() {
  Serial.println("Looking for AM2320");
  if (! AM2320.begin() )
  {
    Serial.println("Sensor not found");
    return;
  }
  Serial.println("AM2320 found and waking up");

  AM2320.wakeUp();
  delay(2000);
}

void loopSensors() {
  delay(500);

  int status = AM2320.read();
  if (status != AM232X_OK)
    return;

  auto humidity = AM2320.getHumidity();
  auto temperature = AM2320.getTemperature();

  Serial.print(humidity, 1);
  Serial.print("%,\t");
  Serial.print(temperature, 1);
  Serial.println(" graden");

  transmitValue(humidity);
  transmitValue(temperature);
}
