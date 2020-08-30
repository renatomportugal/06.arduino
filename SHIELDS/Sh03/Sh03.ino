/* PINOS DIGITAIS 0 a 4: Ponte H
Utilizaremos os pinos digitais de 0 a 4 para polarizar 
os transistores.

###FUNCIONAMENTOS
===CIRCUITO BC548===
Parts:
Transistor BC548 (NPN) [x2]
Transistor BC558(PNP) [x2]
Diodo 1N4148 [x4]
Resistencia 100 ohm [x4]

Para funcinonar o motor no sentido horário, polarizaremos T1 e T4.
Para funcinonar o motor no sentido anti-horário, polarizaremos T2 e T3.

===CIRCUITO OPTO-ACOPLADOR
Parts:
Transistor TIP122 (NPN) [x2]
Transistor TIP127 (PNP) [x2]
Opto-Acoplador TIL113 (NPN) [x4]
Diodo 1N4148 [x4]
Resistencia 220 ohm (Base TIP) [x4]
Resistencia 330 ohm (Base TIL) [x4]

===CIRCUITO RELES
Parts:
Rele 5v (Máx100mA) [x2]
Diodo 1N4148 [x4]
Transistor BC547 (NPN) [x2]
Resistencia 680 ohms  [x2]

===CIRCUITO DISPLAY DE 7 SEGMENTOS
Display 7 segmentos Anodo Comum
Resistencia 270 ohms [x8]

###CÓDIGOS
===CIRCUITO BC548===
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
  //Sentido Horário
  digitalWrite(T1, LOW);
  digitalWrite(T2, LOW);
  digitalWrite(T3, HIGH);
  digitalWrite(T4, HIGH);
  delay(4500);
  //TEMPO DESCONECTADO PARA O MOTOR PARAR
  digitalWrite(T1, HIGH);
  digitalWrite(T2, HIGH);
  delay(500);
  
  //Sentido Anti-horário
  digitalWrite(T1, HIGH);
  digitalWrite(T2, HIGH);
  digitalWrite(T3, LOW);
  digitalWrite(T4, LOW);
  delay(4500);
  //TEMPO DESCONECTADO PARA O MOTOR PARAR
  digitalWrite(T1, LOW);
  digitalWrite(T2, LOW);
  delay(500);
}
=== FIM DO CIRCUITO BC548===

=== CIRCUITO OPTO-ACOPLADOR
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
===FIM DO CIRCUITO OPTO-ACOPLADOR

===CIRCUITO RELES===
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
===FIM DO CIRCUITO RELES===

===CIRCUITO DISPLAY 7 SEGMENTOS===
//PINOS PARA O DISPLAY DE 7 SEGMENTOS
int DISPLAY_A = 6;
int DISPLAY_B = 7;
int DISPLAY_C = 8;
int DISPLAY_D = 9;
int DISPLAY_E = 10;
int DISPLAY_F = 11;
int DISPLAY_G = 12;
int DISPLAY_H = 13;

void setup() {                
//INICIA AS I/O DIGITAIS COMO SAÍDAS 
  pinMode(DISPLAY_A, OUTPUT);
  pinMode(DISPLAY_B, OUTPUT);
  pinMode(DISPLAY_C, OUTPUT);
  pinMode(DISPLAY_D, OUTPUT);
  pinMode(DISPLAY_E, OUTPUT);
  pinMode(DISPLAY_F, OUTPUT);
  pinMode(DISPLAY_G, OUTPUT);
  pinMode(DISPLAY_H, OUTPUT);
}

// the loop routine runs over and over again forever:
void loop() {
  //TESTE DE FUNCIONAMENTO
  digitalWrite(DISPLAY_A, LOW);
  digitalWrite(DISPLAY_B, LOW);
  digitalWrite(DISPLAY_C, LOW);
  digitalWrite(DISPLAY_D, LOW);
  digitalWrite(DISPLAY_E, LOW);
  digitalWrite(DISPLAY_F, LOW);
  digitalWrite(DISPLAY_G, LOW);
  digitalWrite(DISPLAY_H, LOW);
  delay(1000);
  //DESLIGA TUDO
  digitalWrite(DISPLAY_A, HIGH);
  digitalWrite(DISPLAY_B, HIGH);
  digitalWrite(DISPLAY_C, HIGH);
  digitalWrite(DISPLAY_D, HIGH);
  digitalWrite(DISPLAY_E, HIGH);
  digitalWrite(DISPLAY_F, HIGH);
  digitalWrite(DISPLAY_G, HIGH);
  digitalWrite(DISPLAY_H, HIGH);
  delay(1000);
  //NUMERO 0
  digitalWrite(DISPLAY_A, LOW);
  digitalWrite(DISPLAY_B, LOW);
  digitalWrite(DISPLAY_C, LOW);
  digitalWrite(DISPLAY_D, LOW);
  digitalWrite(DISPLAY_E, LOW);
  digitalWrite(DISPLAY_F, LOW);
  digitalWrite(DISPLAY_G, HIGH);
  digitalWrite(DISPLAY_H, HIGH);
  delay(1000);
  //NUMERO 1
  digitalWrite(DISPLAY_A, HIGH);
  digitalWrite(DISPLAY_B, LOW);
  digitalWrite(DISPLAY_C, LOW);
  digitalWrite(DISPLAY_D, HIGH);
  digitalWrite(DISPLAY_E, HIGH);
  digitalWrite(DISPLAY_F, HIGH);
  digitalWrite(DISPLAY_G, HIGH);
  digitalWrite(DISPLAY_H, HIGH);
  delay(1000);  
  //NUMERO 02
  digitalWrite(DISPLAY_A, LOW);
  digitalWrite(DISPLAY_B, LOW);
  digitalWrite(DISPLAY_C, HIGH);
  digitalWrite(DISPLAY_D, LOW);
  digitalWrite(DISPLAY_E, LOW);
  digitalWrite(DISPLAY_F, HIGH);
  digitalWrite(DISPLAY_G, LOW);
  digitalWrite(DISPLAY_H, HIGH);
  delay(1000);
  //NUMERO 03
  digitalWrite(DISPLAY_A, LOW);
  digitalWrite(DISPLAY_B, LOW);
  digitalWrite(DISPLAY_C, LOW);
  digitalWrite(DISPLAY_D, LOW);
  digitalWrite(DISPLAY_E, HIGH);
  digitalWrite(DISPLAY_F, HIGH);
  digitalWrite(DISPLAY_G, LOW);
  digitalWrite(DISPLAY_H, HIGH);
  delay(1000);
  //NUMERO 04
  digitalWrite(DISPLAY_A, HIGH);
  digitalWrite(DISPLAY_B, LOW);
  digitalWrite(DISPLAY_C, LOW);
  digitalWrite(DISPLAY_D, HIGH);
  digitalWrite(DISPLAY_E, HIGH);
  digitalWrite(DISPLAY_F, LOW);
  digitalWrite(DISPLAY_G, LOW);
  digitalWrite(DISPLAY_H, HIGH);
  delay(1000);
    //NUMERO 05
  digitalWrite(DISPLAY_A, LOW);
  digitalWrite(DISPLAY_B, HIGH);
  digitalWrite(DISPLAY_C, LOW);
  digitalWrite(DISPLAY_D, LOW);
  digitalWrite(DISPLAY_E, HIGH);
  digitalWrite(DISPLAY_F, LOW);
  digitalWrite(DISPLAY_G, LOW);
  digitalWrite(DISPLAY_H, HIGH);
  delay(1000);
    //NUMERO 06
  digitalWrite(DISPLAY_A, LOW);
  digitalWrite(DISPLAY_B, HIGH);
  digitalWrite(DISPLAY_C, LOW);
  digitalWrite(DISPLAY_D, LOW);
  digitalWrite(DISPLAY_E, LOW);
  digitalWrite(DISPLAY_F, LOW);
  digitalWrite(DISPLAY_G, LOW);
  digitalWrite(DISPLAY_H, HIGH);
  delay(1000);
    //NUMERO 07
  digitalWrite(DISPLAY_A, LOW);
  digitalWrite(DISPLAY_B, LOW);
  digitalWrite(DISPLAY_C, LOW);
  digitalWrite(DISPLAY_D, HIGH);
  digitalWrite(DISPLAY_E, HIGH);
  digitalWrite(DISPLAY_F, HIGH);
  digitalWrite(DISPLAY_G, HIGH);
  digitalWrite(DISPLAY_H, HIGH);
  delay(1000);
    //NUMERO 08
  digitalWrite(DISPLAY_A, LOW);
  digitalWrite(DISPLAY_B, LOW);
  digitalWrite(DISPLAY_C, LOW);
  digitalWrite(DISPLAY_D, LOW);
  digitalWrite(DISPLAY_E, LOW);
  digitalWrite(DISPLAY_F, LOW);
  digitalWrite(DISPLAY_G, LOW);
  digitalWrite(DISPLAY_H, HIGH);
  delay(1000);
    //NUMERO 09
  digitalWrite(DISPLAY_A, LOW);
  digitalWrite(DISPLAY_B, LOW);
  digitalWrite(DISPLAY_C, LOW);
  digitalWrite(DISPLAY_D, HIGH);
  digitalWrite(DISPLAY_E, HIGH);
  digitalWrite(DISPLAY_F, LOW);
  digitalWrite(DISPLAY_G, LOW);
  digitalWrite(DISPLAY_H, HIGH);
  delay(1000);
    //LETRA A
  digitalWrite(DISPLAY_A, LOW);
  digitalWrite(DISPLAY_B, LOW);
  digitalWrite(DISPLAY_C, LOW);
  digitalWrite(DISPLAY_D, HIGH);
  digitalWrite(DISPLAY_E, LOW);
  digitalWrite(DISPLAY_F, LOW);
  digitalWrite(DISPLAY_G, LOW);
  digitalWrite(DISPLAY_H, HIGH);
  delay(1000);
    //LETRA B
  digitalWrite(DISPLAY_A, HIGH);
  digitalWrite(DISPLAY_B, HIGH);
  digitalWrite(DISPLAY_C, LOW);
  digitalWrite(DISPLAY_D, LOW);
  digitalWrite(DISPLAY_E, LOW);
  digitalWrite(DISPLAY_F, LOW);
  digitalWrite(DISPLAY_G, LOW);
  digitalWrite(DISPLAY_H, HIGH);
  delay(1000);
    //LETRA C
  digitalWrite(DISPLAY_A, LOW);
  digitalWrite(DISPLAY_B, HIGH);
  digitalWrite(DISPLAY_C, HIGH);
  digitalWrite(DISPLAY_D, LOW);
  digitalWrite(DISPLAY_E, LOW);
  digitalWrite(DISPLAY_F, LOW);
  digitalWrite(DISPLAY_G, HIGH);
  digitalWrite(DISPLAY_H, HIGH);
  delay(1000);
    //LETRA D
  digitalWrite(DISPLAY_A, HIGH);
  digitalWrite(DISPLAY_B, LOW);
  digitalWrite(DISPLAY_C, LOW);
  digitalWrite(DISPLAY_D, LOW);
  digitalWrite(DISPLAY_E, LOW);
  digitalWrite(DISPLAY_F, HIGH);
  digitalWrite(DISPLAY_G, LOW);
  digitalWrite(DISPLAY_H, HIGH);
  delay(1000);
    //LETRA E
  digitalWrite(DISPLAY_A, LOW);
  digitalWrite(DISPLAY_B, HIGH);
  digitalWrite(DISPLAY_C, HIGH);
  digitalWrite(DISPLAY_D, LOW);
  digitalWrite(DISPLAY_E, LOW);
  digitalWrite(DISPLAY_F, LOW);
  digitalWrite(DISPLAY_G, LOW);
  digitalWrite(DISPLAY_H, HIGH);
  delay(1000);
    //LETRA F
  digitalWrite(DISPLAY_A, LOW);
  digitalWrite(DISPLAY_B, HIGH);
  digitalWrite(DISPLAY_C, HIGH);
  digitalWrite(DISPLAY_D, HIGH);
  digitalWrite(DISPLAY_E, LOW);
  digitalWrite(DISPLAY_F, LOW);
  digitalWrite(DISPLAY_G, LOW);
  digitalWrite(DISPLAY_H, HIGH);
  delay(1000);
    //LETRA H
  digitalWrite(DISPLAY_A, HIGH);
  digitalWrite(DISPLAY_B, LOW);
  digitalWrite(DISPLAY_C, LOW);
  digitalWrite(DISPLAY_D, HIGH);
  digitalWrite(DISPLAY_E, LOW);
  digitalWrite(DISPLAY_F, LOW);
  digitalWrite(DISPLAY_G, LOW);
  digitalWrite(DISPLAY_H, HIGH);
  delay(1000);
    //LETRA L
  digitalWrite(DISPLAY_A, HIGH);
  digitalWrite(DISPLAY_B, HIGH);
  digitalWrite(DISPLAY_C, HIGH);
  digitalWrite(DISPLAY_D, LOW);
  digitalWrite(DISPLAY_E, LOW);
  digitalWrite(DISPLAY_F, LOW);
  digitalWrite(DISPLAY_G, HIGH);
  digitalWrite(DISPLAY_H, HIGH);
  delay(1000);
    //LETRA P
  digitalWrite(DISPLAY_A, LOW);
  digitalWrite(DISPLAY_B, LOW);
  digitalWrite(DISPLAY_C, HIGH);
  digitalWrite(DISPLAY_D, HIGH);
  digitalWrite(DISPLAY_E, LOW);
  digitalWrite(DISPLAY_F, LOW);
  digitalWrite(DISPLAY_G, LOW);
  digitalWrite(DISPLAY_H, HIGH);
  delay(1000);
    //LETRA U
  digitalWrite(DISPLAY_A, HIGH);
  digitalWrite(DISPLAY_B, LOW);
  digitalWrite(DISPLAY_C, LOW);
  digitalWrite(DISPLAY_D, LOW);
  digitalWrite(DISPLAY_E, LOW);
  digitalWrite(DISPLAY_F, LOW);
  digitalWrite(DISPLAY_G, HIGH);
  digitalWrite(DISPLAY_H, HIGH);
  delay(1000);
}
===FIM DO CIRCUITO DO DISPLAY DE 7 SEGMENTOS===

===LEITURA ANALÓGICA DE TENSÃO===
void setup() {
  Serial.begin(9600);
}

void loop() {
  // read the input on analog pin 0:
  int sensorValue = analogRead(A0);
  // Convert the analog reading (which goes from 0 - 1023) to a voltage (0 - 5V):
  float voltage = sensorValue * (5.0 / 1023.0);
  // print out the value you read:
  Serial.println(voltage);
}
===FIM DA LEITURA ANALÓGICA DE TENSÃO
*/



