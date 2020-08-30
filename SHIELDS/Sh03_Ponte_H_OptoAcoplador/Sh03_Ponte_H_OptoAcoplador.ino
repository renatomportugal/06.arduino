//PINOS PARA A BASE DOS TRANSISTORES
//Transistor 1
int T1 = 0;
//Transistor 2
int T2 = 1;
//Transistor 3
int T3 = 2;
//Transistor 4
int T4 = 3;

void setup() {                
//INICIA AS I/O DIGITAIS COMO SAÍDAS 
  pinMode(T1, OUTPUT);     
  pinMode(T2, OUTPUT);
  pinMode(T3, OUTPUT);
  pinMode(T4, OUTPUT);
}

// the loop routine runs over and over again forever:
void loop() {
  //ABRIR - T1 e T4 conectados
  digitalWrite(T1, HIGH);
  digitalWrite(T2, LOW);
  digitalWrite(T3, LOW);
  digitalWrite(T4, HIGH);
  delay(3000);
  //TEMPO DESCONECTADO PARA O MOTOR PARAR
  digitalWrite(T1, LOW);
  delay(1000);
 
  //FECHAR - T2 e T3 conectados
  digitalWrite(T1, LOW);
  digitalWrite(T2, HIGH);
  digitalWrite(T3, HIGH);
  digitalWrite(T4, LOW);
  delay(3000);
  //TEMPO DESCONECTADO PARA O MOTOR PARAR
  digitalWrite(T2, LOW);
  delay(1000);
}
