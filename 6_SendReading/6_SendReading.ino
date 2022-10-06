#include <ESP8266WiFi.h>

float lat = 51.9, lng = 4.5, height = 4; // default value, overwrite

#include "utils/logging.h"
#include "utils/credentials.h"
#include "utils/dbSettings.h"
#include "utils/wifi.h"
#include "utils/dateTime.h"
#include "utils/gps.h"

#include <MySQL_Generic.h>

void transmitValue(float value);

// Uncomment the line below, corresponding with the used sensors
#include "ADXL345.h"
//#include "AGS02MA.h"
//#include "AM2320.h"
//#include "BMP085.h"
//#include "BMP180.h"
//#include "HCSR04.h"
//#include "HMC5883.h"
//#include "HX711.h"
//#include "MAX4466.h"
//#include "MB060.h"

MySQL_Connection conn((Client *)&client);
auto query_mem = MySQL_Query(&conn);

void setup()
{
  setupLogging();
  setupGPS();
  setupSensors();

  connect2Wifi(ssid, pass);
}

void transmitValue(float value)
{
  Serial.print("Connecting to SQL Server @");
  Serial.print(server);
  Serial.print(", Port =");
  Serial.println(server_port);

  if (conn.connectNonBlocking(server, server_port, user, password) != RESULT_FAIL)
  {
    char idHex[20];
    itoa(ESP.getChipId(), hexString, 16); // HEX ID of chip (last 3 digits of MAC)

    auto INSERT_SQL = String("INSERT INTO iotinaday.observaties")
                      + " (id, wanneer, waar, waarde) VALUES ('"
                      + idHex + "', '"
                      + getISO8601localDateTime()
                      + "', PointFromText('POINT(" + lng + " " + lat + ")'), "
                      + value + " )";
    Serial.println(INSERT_SQL);

    if ( !query_mem.execute(INSERT_SQL.c_str()) )
      Serial.println("Insert error");
    else
      Serial.println("Data Inserted.");

    Serial.println("Closing connection.");
    conn.close();
  }
  else
    Serial.println("nConnect failed. Trying again on next iteration.");
}

void loop()
{
  loopGPS();
  loopSensors();
}
