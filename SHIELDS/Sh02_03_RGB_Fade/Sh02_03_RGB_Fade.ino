#define Pot_A0 A0
#define Pot_A1 A1
#define Pot_A2 A2

const int pwmRed = 3; 
const int pwmGreen = 5; 
const int pwmBlue = 6;

void setup()
{
  Serial.begin(9600);
  pinMode(pwmRed, OUTPUT);    
  pinMode(pwmGreen, OUTPUT);    
  pinMode(pwmBlue, OUTPUT);
  pinMode(Pot_A0, INPUT);
  pinMode(Pot_A1, INPUT);
  pinMode(Pot_A2, INPUT);
}

void loop() {
  int sensorA0 = analogRead(Pot_A0);
  int sensorA1 = analogRead(Pot_A1);
  int sensorA2 = analogRead(Pot_A2);

  int mapSensorA0 = map(sensorA0,0,1023,0,255);
  analogWrite(pwmRed, mapSensorA0);
  Serial.print("Red: ");
  Serial.println(mapSensorA0);
  delay(200);

  int mapSensorA1 = map(sensorA1,0,1023,0,255);
  analogWrite(pwmGreen, mapSensorA1);
  Serial.print("Green: ");
  Serial.println(mapSensorA1);
  delay(200);

  int mapSensorA2 = map(sensorA2,0,1023,0,255);
  analogWrite(pwmBlue, mapSensorA2);
  Serial.print("Blue: ");
  Serial.println(mapSensorA2);
  delay(200);

}
