#include <DFRobot_QMC5883.h>

DFRobot_QMC5883 compass(&Wire, /*I2C addr*/HMC5883L_ADDRESS);

void setupSensors() {

  while (!compass.begin())
  {
    Serial.println("Could not find a valid 5883 sensor, check wiring!");
    delay(500);
  }

  if (compass.isHMC())
  {
    Serial.println("Initialize HMC5883");

    //Set/get the compass signal gain range, default to be 1.3 Ga
    // compass.setRange(HMC5883L_RANGE_1_3GA);
    // Serial.print("compass range is:");
    // Serial.println(compass.getRange());

    //Set/get measurement mode
    // compass.setMeasurementMode(HMC5883L_CONTINOUS);
    // Serial.print("compass measurement mode is:");
    // Serial.println(compass.getMeasurementMode());

    //Set/get the data collection frequency of the sensor
    // compass.setDataRate(HMC5883L_DATARATE_15HZ);
    // Serial.print("compass data rate is:");
    // Serial.println(compass.getDataRate());

    //Get/get sensor status
    // compass.setSamples(HMC5883L_SAMPLES_8);
    // Serial.print("compass samples is:");
    // Serial.println(compass.getSamples());
  }
}

/**
   @brief  Set declination angle on your location and fix heading
   @n      You can find your declination on: http://magnetic-declination.com/
   @n      (+) Positive or (-) for negative
   @n      For Bytom / Poland declination angle is 4'26E (positive)
   @n      Formula: (deg + (min / 60.0)) / (180 / PI);
*/
void loopSensors() {
  float declinationAngle = (4.0 + (26.0 / 60.0)) / (180 / PI);
  compass.setDeclinationAngle(declinationAngle);
  sVector_t mag = compass.readRaw();
  compass.getHeadingDegrees();

  Serial.print("X:");
  Serial.print(mag.XAxis / 100.f);
  Serial.print(" uT\tY:");
  Serial.print(mag.YAxis / 100.f);
  Serial.print(" uT\tZ:");
  Serial.print(mag.ZAxis / 100.f);
  Serial.print(" uT,\tDegrees = ");
  Serial.println(mag.HeadingDegress);

  delay(100);
}
