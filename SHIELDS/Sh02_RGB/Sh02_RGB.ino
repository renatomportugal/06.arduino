#define pwmRed 3
#define pwmGreen 5
#define pwmBlue 6

void setup()
{
  pinMode(pwmRed, OUTPUT);    
  pinMode(pwmGreen, OUTPUT);    
  pinMode(pwmBlue, OUTPUT);
}

void loop() {
  digitalWrite(pwmRed, LOW);
  digitalWrite(pwmGreen, LOW);
  digitalWrite(pwmBlue, LOW);
  analogWrite(pwmRed, 82);
  delay(1000);

  digitalWrite(pwmRed, LOW);
  digitalWrite(pwmGreen, LOW);
  digitalWrite(pwmBlue, LOW);
  analogWrite(pwmGreen, 9);
  delay(1000);

  digitalWrite(pwmRed, LOW);
  digitalWrite(pwmGreen, LOW);
  digitalWrite(pwmBlue, LOW);
  analogWrite(pwmBlue, 1);
  delay(1000);
}
