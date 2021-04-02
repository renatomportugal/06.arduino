// 1. INCLUDES
#include "DHT22.h" // Biblioteca do sensor

// 2. PINOS
// 2.1. SHIELD 02
// 2.1.1. RHT03
int pino_RHT03 = 2;

// 3. DECLARACAO DE VARIAVEIS
// 3.1. RHT03
float hum,temp;

// 4.
DHT22 RHT03(pino_RHT03);//define nome da variável do sensor

void setup()
{
Serial.begin(9600);
}

void loop()
{
//RHT03 - APRESENTACAO DOS RESULTADOS
RHT03.readData();
temp=RHT03.getTemperatureC();
hum=RHT03.getHumidity();
Serial.print(temp);
Serial.print(" Grau C, ");
Serial.print(hum);
Serial.println(" %Hum");

delay(1000);
}
