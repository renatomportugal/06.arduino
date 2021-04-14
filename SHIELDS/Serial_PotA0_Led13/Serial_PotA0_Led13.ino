//POTENCIOMETRO
#define Pot A0
#define LED_BUILTIN 13

void setup() {
    //Serial.begin(9600);
    Serial.begin(115200);
    pinMode (Pot, INPUT);
    pinMode(LED_BUILTIN, OUTPUT);
}

void loop () {
  //Leitura Sensores
  int sensorPot = analogRead(Pot);

  //Mapeamento
  int mapsensorPot = map(sensorPot,0,1023,0,255);

  float vSensorValue = sensorPot * (5.0 / 1023.0);
  
  //Saída
  //Teste de quantidade de caracteres
  //0
  Serial.print("xxxxx");
  Serial.print(";");
  Serial.print("Po1:");
  Serial.print(mapsensorPot);
  Serial.print(";");
  Serial.print("Volt:");
  Serial.print(vSensorValue);
  Serial.print(";");
  //24
  Serial.print("xxxxx");
  Serial.print(";");
  Serial.print("Po2:");
  Serial.print(mapsensorPot);
  Serial.print(";");
  Serial.print("Volt:");
  Serial.print(vSensorValue);
  Serial.print(";");
  //48
  Serial.print("xxxxx");
  Serial.print(";");
  Serial.print("Po3:");
  Serial.print(mapsensorPot);
  Serial.print(";");
  Serial.print("Volt:");
  Serial.print(vSensorValue);
  Serial.print(";");
  //72
  Serial.print("xxxxx");
  Serial.print(";");
  Serial.print("Po4:");
  Serial.print(mapsensorPot);
  Serial.print(";");
  Serial.print("Volt:");
  Serial.print(vSensorValue);
  Serial.print(";");
  //96
  Serial.print("xxxxx");
  Serial.print(";");
  Serial.print("Po5:");
  Serial.print(mapsensorPot);
  Serial.print(";");
  Serial.print("Volt:");
  Serial.print(vSensorValue);
  Serial.print(";");
  //120
  Serial.print("xxxxx");
  Serial.print(";");
  Serial.print("Po6:");
  Serial.print(mapsensorPot);
  Serial.print(";");
  Serial.print("Volt:");
  Serial.print(vSensorValue);
  Serial.print(";");
  //144
  Serial.print("xxxxx");
  Serial.print(";");
  Serial.print("Po7:");
  Serial.print(mapsensorPot);
  Serial.print(";");
  Serial.print("Volt:");
  Serial.print(vSensorValue);
  Serial.print(";");
  //168
  Serial.print("xxxxx");
  Serial.print(";");
  Serial.print("Po8:");
  Serial.print(mapsensorPot);
  Serial.print(";");
  Serial.print("Volt:");
  Serial.print(vSensorValue);
  Serial.print(";");
  //192
  Serial.print("xxxxx");
  Serial.print(";");
  Serial.print("Po9:");
  Serial.print(mapsensorPot);
  Serial.print(";");
  Serial.print("Volt:");
  Serial.print(vSensorValue);
  Serial.print(";");
  //216
  Serial.print("xxxxx");
  Serial.print(";");
  Serial.print("P10:");
  Serial.print(mapsensorPot);
  Serial.print(";");
  Serial.print("Volt:");
  Serial.print(vSensorValue);
  Serial.print(";");
  //240
  Serial.print("xxxxx");
  Serial.print(";");
  Serial.print("P11:");
  Serial.print(mapsensorPot);
  Serial.print(";");
  Serial.print("Volt:");
  Serial.print(vSensorValue);
  Serial.print(";");
  //264
  Serial.print("xxxxx");
  Serial.print(";");
  Serial.print("P12:");
  Serial.print(mapsensorPot);
  Serial.print(";");
  Serial.print("Volt:");
  Serial.print(vSensorValue);
  Serial.print(";");
  //288
  Serial.print("xxxxx");
  Serial.print(";");
  Serial.print("P13:");
  Serial.print(mapsensorPot);
  Serial.print(";");
  Serial.print("Volt:");
  Serial.print(vSensorValue);
  Serial.print(";");
  //312
  Serial.print("xxxxx");
  Serial.print(";");
  Serial.print("P14:");
  Serial.print(mapsensorPot);
  Serial.print(";");
  Serial.print("Volt:");
  Serial.print(vSensorValue);
  Serial.print(";");
  //336
  Serial.print("xxxxx");
  Serial.print(";");
  Serial.print("P15:");
  Serial.print(mapsensorPot);
  Serial.print(";");
  Serial.print("Volt:");
  Serial.print(vSensorValue);
  Serial.print(";");
  //360
  Serial.println("yyyyy");
  digitalWrite(LED_BUILTIN, HIGH);
  delay(100);

  digitalWrite(LED_BUILTIN, LOW);
  delay(100);
}
