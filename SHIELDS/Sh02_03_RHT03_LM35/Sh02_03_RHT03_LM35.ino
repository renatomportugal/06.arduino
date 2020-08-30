// 1. INCLUDES
#include "DHT22.h" // Biblioteca do sensor

// 2. PINOS
// 2.1. SHIELD 02
// 2.1.1. RHT03
const int pino_RHT03 = 2;
// 2.2. SHIELD 03
// 2.2.1. LM35
const int LM35 = A3;

// 3. DECLARACAO DE VARIAVEIS
// 3.1. RHT03
float humRHT03,tempRHT03;
// 3.2. LM35
float tempLM35;

// 4. 
DHT22 RHT03(pino_RHT03);//define nome da variável do sensor

void setup() {
Serial.begin(9600);
}
 
void loop() {
//LM35
tempLM35 = (float(analogRead(LM35))*5/(1023))/0.01;
//RHT03
RHT03.readData();
tempRHT03=RHT03.getTemperatureC();
humRHT03=RHT03.getHumidity();

Serial.print(tempLM35);
Serial.println(" Temp LM35.");

Serial.print(tempRHT03);
Serial.print(" Temp RHT03, ");
Serial.print(humRHT03);
Serial.println(" %Hum RHT03.");

delay(1000);
}
