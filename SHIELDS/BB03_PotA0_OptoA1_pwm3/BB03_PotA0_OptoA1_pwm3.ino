//POTENCIOMETRO
#define Pot_A0 A0
#define Opto_A1 A1
#define saidaPWM 3


void setup() {
  Serial.begin(9600);
  pinMode (saidaPWM, OUTPUT);
  pinMode (Pot_A0, INPUT);
  pinMode (Opto_A1, INPUT);
}


void loop () {
  //Leitura Sensores
  int sensorPot = analogRead(Pot_A0);
  int sensorBat = analogRead(Opto_A1);

  //Mapeamento
  int mapsensorPot = map(sensorPot,0,1023,0,255);

  float vSensorValue = sensorPot * (5.0 / 1023.0);
  
  //Saída
  analogWrite(saidaPWM, mapsensorPot);
  Serial.print("Pot: ");
  Serial.print(mapsensorPot);
  Serial.print(" Volt: ");
  Serial.print(vSensorValue);
  Serial.print(" - Bateria: ");
  Serial.println(sensorBat);
  delay(200);
}
