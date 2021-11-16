const int redPin = 3; 
const int grnPin = 5; 
const int bluPin = 6;
const int sensor = A2;

void setup()
{
  pinMode(redPin, OUTPUT);    
  pinMode(grnPin, OUTPUT);    
  pinMode(bluPin, OUTPUT);
  pinMode(sensor, INPUT);
}

void loop() {
  if (analogRead(sensor) <= 150)
  {
    ToRed();
    ToGreen();
    ToBlue();

  }
  else if (analogRead(sensor) >= 201)
  {
    digitalWrite(redPin, LOW);
    digitalWrite(grnPin, LOW);
    digitalWrite(bluPin, LOW);
  }
}

void ToGreen()
{
  int x, valor;
  float seno; 
  digitalWrite(redPin, LOW);
  digitalWrite(bluPin, LOW);
  digitalWrite(grnPin, LOW);

  for (x=0; x<255; x++) {
    seno = 100+(100*(sin(x*(6.28/255))));
    valor = int(seno);
    analogWrite(grnPin, valor);
    delay(10);
  }
}


void ToBlue()
{
  int x, valor;
  float seno;
  digitalWrite(redPin, LOW);
  digitalWrite(bluPin, LOW);
  digitalWrite(grnPin, LOW);

  for (x=0; x<255; x++) {
    seno = 100+(100*(sin(x*(6.28/255))));
    valor = int(seno);
    analogWrite(bluPin, valor);
    delay(10);
  }
}

void ToRed()
{
  int x, valor;
  float seno;
  digitalWrite(redPin, LOW);
  digitalWrite(bluPin, LOW);
  digitalWrite(grnPin, LOW);

  for (x=0; x<255; x++) {
    seno = 100+(100*(sin(x*(6.28/255))));
    valor = int(seno);
    analogWrite(redPin, valor);
    delay(10);
  }
}
