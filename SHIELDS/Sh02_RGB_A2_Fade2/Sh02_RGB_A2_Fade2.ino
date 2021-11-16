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
  digitalWrite(redPin, LOW);
  digitalWrite(bluPin, LOW);
  digitalWrite(grnPin, LOW);

  // fade up green
  for(byte i=1; i<160; i++) {
    byte on  = i;
    byte off = 160-on;
    for( byte a=0; a<160; a++ ) {
      digitalWrite(grnPin, HIGH);
      delayMicroseconds(on);
      digitalWrite(grnPin, LOW);
      delayMicroseconds(off);
    }
  }
}


void ToBlue()
{
  digitalWrite(redPin, LOW);
  digitalWrite(bluPin, LOW);
  digitalWrite(grnPin, LOW);

  // fade up blue
  for(byte i=1; i<160; i++) {
    byte on  = i;
    byte off = 160-on;
    for( byte a=0; a<160; a++ ) {
      digitalWrite(bluPin, HIGH);
      delayMicroseconds(on);
      digitalWrite(bluPin, LOW);
      delayMicroseconds(off);
    }
  }
}

void ToRed()
{
  digitalWrite(redPin, LOW);
  digitalWrite(bluPin, LOW);
  digitalWrite(grnPin, LOW);

  // fade up green
  for(byte i=1; i<160; i++) {
    byte on  = i;
    byte off = 160-on;
    for( byte a=0; a<160; a++ ) {
      digitalWrite(redPin, HIGH);
      delayMicroseconds(on);
      digitalWrite(redPin, LOW);
      delayMicroseconds(off);
    }
  }
}
