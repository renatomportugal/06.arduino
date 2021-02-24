const int redPin = 3;
const int sensor = A2;


void setup()
{
  pinMode(redPin, OUTPUT);    
}

void loop() {
  if (analogRead(sensor) <= 150)
  {
    fadeRed();
  }
  else if (analogRead(sensor) >= 201)
  {
    digitalWrite(redPin, LOW);
  }
}

void fadeRed()
{

  // fade up green
  for(byte i=1; i<150; i++) {
    byte on  = i;
    byte off = 150-on;
    for( byte a=0; a<150; a++ ) {
      digitalWrite(redPin, HIGH);
      delayMicroseconds(on);
      digitalWrite(redPin, LOW);
      delayMicroseconds(off);
    }
  }
}
