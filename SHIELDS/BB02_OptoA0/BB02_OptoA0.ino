//POTENCIOMETRO
#define Opto_A0 A0

void setup() {
  Serial.begin(9600);
  pinMode (Opto_A0, INPUT);
}


void loop () {
  int sensorValue = analogRead(Opto_A0);
  Serial.println(sensorValue);
  delay(200);
}
