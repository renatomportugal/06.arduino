const int LM35 = A3;
float temperatura;
 
void setup() {
Serial.begin(9600);
}
 
void loop() {
temperatura = (float(analogRead(LM35))*5/(1023))/0.01;
Serial.print("Temperatura: ");
Serial.println(temperatura);
delay(1000);
}
