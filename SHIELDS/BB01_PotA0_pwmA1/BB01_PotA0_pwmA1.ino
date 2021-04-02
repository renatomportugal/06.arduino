//POTENCIOMETRO
#define Pot_A0 A0

#define saidaPWM 3


void setup() {
  Serial.begin(9600);
  pinMode (saidaPWM, OUTPUT);
  pinMode (Pot_A0, INPUT);
}


void loop () {
  int sensorValue = analogRead(Pot_A0);
  int mapSensorValue = map(sensorValue,0,1023,0,255);
  analogWrite(saidaPWM, mapSensorValue);
  Serial.println(mapSensorValue);
  delay(200);
}
