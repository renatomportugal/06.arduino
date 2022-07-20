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
