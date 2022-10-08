#include "utils/logging.h"

// Uncomment the line below, corresponding with the used sensors
//#include "ADXL345.h" // 3-axis Accelerometer 
//#include "HCSR04.h" // afstand
//#include "AM2320.h" // temp & humidity
//#include "MAX4466.h" // geluid
//#include "HMC5883.h" // 3-Axis Kompas Magnetometer
//#include "HX711.h" // weight

void setup() {
  setupLogging();
  setupSensors();
}

void loop() {
  loopSensors();
}
