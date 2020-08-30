//PINOS PARA OS TRANSISTORES DOS RELES
//Rele 01
int Rele_01 = 4;
//Rele 02
int Rele_02 = 5;

void setup() {                
//INICIA AS I/O DIGITAIS COMO SAÍDAS 
  pinMode(Rele_01, OUTPUT);     
  pinMode(Rele_02, OUTPUT);
}

// the loop routine runs over and over again forever:
void loop() {
  //LIGAR RELE 01
  digitalWrite(Rele_01, HIGH);
  digitalWrite(Rele_02, LOW);
  delay(1000);
  //LIGAR RELE 02 E DESLIGA O RELE 01
  digitalWrite(Rele_01, LOW);
  digitalWrite(Rele_02, HIGH);  
  delay(1000);
  //DESLIGAR RELE 02
  digitalWrite(Rele_02, LOW);
  delay(1000);
  //LIGAR OS DOIS RELES
  digitalWrite(Rele_01, HIGH);
  digitalWrite(Rele_02, HIGH);
  delay(1000);  
  //DESLIGAR OS DOIS RELES
  digitalWrite(Rele_01, LOW);
  digitalWrite(Rele_02, LOW);
  delay(1000);    
}
