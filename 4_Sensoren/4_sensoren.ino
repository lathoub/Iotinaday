#include "utils/logging.h"

// Uncomment the line below, corresponding with the used sensors
//#include "ADXL345.h"
//#include "HCSR04.h"
//#include "AM2320.h"
//#include "MAX4466.h"
//#include "HMC5883.h"
//#include "HX711.h"

void setup() {
  setupLogging();
  setupSensors();
}

void loop() {
  loopSensors();
}
