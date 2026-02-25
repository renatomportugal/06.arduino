
#include <dht.h>
dht DHT01;
dht DHT02;

#define RHT03_01 4
#define RHT03_02 5
void setup()
{
Serial.begin(9600);
Serial.println("DHT TEST PROGRAM ");
Serial.print("LIBRARY VERSION: ");
Serial.println(DHT_LIB_VERSION);
Serial.println();
Serial.println("Type,\tstatus,\tHumidity (%),\tTemperature (C)");
}
void loop()
{
// READ DATA
Serial.print("RHT03_01, \t");
int chk01 = DHT01.read22(RHT03_01);
switch (chk01)
{
case DHTLIB_OK: 
Serial.print("OK,\t"); 
break;
case DHTLIB_ERROR_CHECKSUM: 
Serial.print("Checksum error,\t"); 
break;
case DHTLIB_ERROR_TIMEOUT: 
Serial.print("Time out error,\t"); 
break;
default: 
Serial.print("Unknown error,\t"); 
break;
}
// DISPLAY DATA
Serial.print(DHT01.humidity, 1);
Serial.print(",\t");
Serial.println(DHT01.temperature, 1);
delay(500);

Serial.print("RHT03_02, \t");
int chk02 = DHT02.read22(RHT03_02);
switch (chk02)
{
case DHTLIB_OK: 
Serial.print("OK,\t"); 
break;
case DHTLIB_ERROR_CHECKSUM: 
Serial.print("Checksum error,\t"); 
break;
case DHTLIB_ERROR_TIMEOUT: 
Serial.print("Time out error,\t"); 
break;
default: 
Serial.print("Unknown error,\t"); 
break;
}
// DISPLAY DATA
Serial.print(DHT02.humidity, 1);
Serial.print(",\t");
Serial.println(DHT02.temperature, 1);
delay(500);
}
