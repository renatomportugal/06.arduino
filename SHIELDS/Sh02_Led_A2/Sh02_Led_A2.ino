int saidaPWM;
int x, valor;
float seno; 

#define saidaPWM 3 


void setup() {
  pinMode (saidaPWM, OUTPUT);
  
}


void loop () {
  for (x=0; x<255; x++) {
    seno = 100+(100*(sin(x*(6.28/255))));
    valor = int(seno);
    analogWrite(saidaPWM, valor);
    delay(10);
  }
}

/*
const int redPin = 3;
const int sensor = A2;
float sine;
int sine_1;
int x,y;


void setup()
{
  pinMode(redPin, OUTPUT);    
}

void loop() {
x = analogRead(sensor);
y = map(x, 0, 1024, 0, 76);

analogWrite(redPin, y);
 delay(10);
  
}

void fadeRed()
{

  
  subida(76);
}

void subida(int i){
  for(int j = 0; j<i;j++)
  {
    analogWrite(redPin, j);
    delay(10);
  }
  
  
  }
 */ 

  /*
   * 
   * 
   *    for(int i=-76; i<76; i+=1) {
    analogWrite(redPin, i);
    delay(5);
    }


for(int i=-180; i<180; i+=1) {
    sine = sin(i*(3.1415/180));
    sine_1 = 127+int(sine*255.0/2.0);
    analogWrite(redPin, sine_1);
    delay(1);
    }
    
    
   * for(int i=-76; i<76; i+=1) {
    sine = sin(i*(3.1415/180));
    sine_1 = 127+int(sine*255.0/2.0);
    analogWrite(redPin, sine_1);
    delay(1);
   * 
   * 
   * for(byte i=1; i<76; i++) {
    byte on  = i;
    byte off = 76-on;
    for( byte a=0; a<76; a++ ) {
      digitalWrite(redPin, HIGH);
      delay(1);
      digitalWrite(redPin, LOW);
      delay(1);
    }
    
  for(byte i=1; i<76; i++) {
    byte on  = i;
    byte off = 76-on;
    for( byte a=0; a<76; a++ ) {
      digitalWrite(redPin, HIGH);
      delayMicroseconds(on);
      digitalWrite(redPin, LOW);
      delayMicroseconds(off);
    }
  */
