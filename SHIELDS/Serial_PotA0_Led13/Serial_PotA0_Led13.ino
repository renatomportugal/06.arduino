//POTENCIOMETRO
#define Pot A0
#define LED_BUILTIN 13

void setup() {
    Serial.begin(9600);
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
  Serial.print("Pot: ");
  Serial.print(mapsensorPot);
  Serial.print(" Volt: ");
  Serial.println(vSensorValue);
  
  digitalWrite(LED_BUILTIN, HIGH);
  delay(1000);

  digitalWrite(LED_BUILTIN, LOW);
  delay(1000);
}
