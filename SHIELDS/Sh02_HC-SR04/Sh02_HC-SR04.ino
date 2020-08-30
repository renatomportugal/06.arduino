#define trigPin 7
#define echoPin 6


void setup() {
  Serial.begin (9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

}

void loop() {
  long duration, distance;  // http://arduino.cc/en/Reference/Long
  digitalWrite(trigPin, LOW);  // Configura o pino 12 com um pulso baixo "LOW" ou desligado ou ainda 0
  delayMicroseconds(2);  // Aguarda 2 microssegundos

  digitalWrite(trigPin, HIGH);  // Configura o pino 12 com pulso alto "HIGH" ou ligado ou ainda 1
  delayMicroseconds(10);  // Aguarda 10 microssegundos
  digitalWrite(trigPin, LOW);  // Configura o pino 12 com pulso baixo novamente
  duration = pulseIn(echoPin, HIGH);  // PulseIn lê o tempo entre a chamada e o pino entrar em High
 
  // Esse calculo é baseado em s = v . t, lembrando que o tempo vem dobrado
  // porque é o tempo de ida e volta do ultrassom
 
    distance = ((duration/2) / 29.1);
   
    Serial.print(distance);
    Serial.println(" Cm");

  delay(500);
}

