//POTENCIOMETRO
#define Pot_A0 A0

//PINOS PARA O DISPLAY DE 7 SEGMENTOS
int DISPLAY_A = 6;
int DISPLAY_B = 7;
int DISPLAY_C = 8;
int DISPLAY_D = 9;
int DISPLAY_E = 10;
int DISPLAY_F = 11;
int DISPLAY_G = 12;
int DISPLAY_H = 13;

//PINOS PARA OS TRANSISTORES DOS RELES
//Rele 01
int Rele_01 = 4;
//Rele 02
int Rele_02 = 5;

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

  pinMode(DISPLAY_A, OUTPUT);
  pinMode(DISPLAY_B, OUTPUT);
  pinMode(DISPLAY_C, OUTPUT);
  pinMode(DISPLAY_D, OUTPUT);
  pinMode(DISPLAY_E, OUTPUT);
  pinMode(DISPLAY_F, OUTPUT);
  pinMode(DISPLAY_G, OUTPUT);
  pinMode(DISPLAY_H, OUTPUT);
  
  pinMode(Rele_01, OUTPUT);     
  pinMode(Rele_02, OUTPUT);
}

// the loop routine runs over and over again forever:
void loop() {
  int sensorValue = analogRead(Pot_A0);
  float voltage = sensorValue * (5.0 / 1023.0);

  if (voltage < 1.00) {
      //NUMERO 0
  digitalWrite(DISPLAY_A, LOW);
  digitalWrite(DISPLAY_B, LOW);
  digitalWrite(DISPLAY_C, LOW);
  digitalWrite(DISPLAY_D, LOW);
  digitalWrite(DISPLAY_E, LOW);
  digitalWrite(DISPLAY_F, LOW);
  digitalWrite(DISPLAY_G, HIGH);
  digitalWrite(DISPLAY_H, HIGH);
  
    //DESLIGAR OS DOIS RELES
  digitalWrite(Rele_01, LOW);
  digitalWrite(Rele_02, LOW);
  
  delay(100);
  }

      if ((voltage > 1.00)&&(voltage < 2.00)) {
      //NUMERO 1
  digitalWrite(DISPLAY_A, HIGH);
  digitalWrite(DISPLAY_B, LOW);
  digitalWrite(DISPLAY_C, LOW);
  digitalWrite(DISPLAY_D, HIGH);
  digitalWrite(DISPLAY_E, HIGH);
  digitalWrite(DISPLAY_F, HIGH);
  digitalWrite(DISPLAY_G, HIGH);
  digitalWrite(DISPLAY_H, HIGH);

  //DESLIGAR OS DOIS RELES
  digitalWrite(Rele_01, LOW);
  digitalWrite(Rele_02, LOW);
  
//Sentido Horário
  digitalWrite(T1, HIGH);
  digitalWrite(T2, LOW);
  digitalWrite(T3, LOW);
  digitalWrite(T4, HIGH);
  delay(500);
  
  //TEMPO DESCONECTADO PARA O MOTOR PARAR
  digitalWrite(T1, LOW);
  delay(200);
  }


      if ((voltage > 2.00)&&(voltage < 3.00)) {
      //NUMERO 2
  digitalWrite(DISPLAY_A, LOW);
  digitalWrite(DISPLAY_B, LOW);
  digitalWrite(DISPLAY_C, HIGH);
  digitalWrite(DISPLAY_D, LOW);
  digitalWrite(DISPLAY_E, LOW);
  digitalWrite(DISPLAY_F, HIGH);
  digitalWrite(DISPLAY_G, LOW);
  digitalWrite(DISPLAY_H, HIGH);

  //DESLIGAR OS DOIS RELES
  digitalWrite(Rele_01, LOW);
  digitalWrite(Rele_02, LOW);
  
  //Sentido Anti-horário
  digitalWrite(T1, LOW);
  digitalWrite(T2, HIGH);
  digitalWrite(T3, HIGH);
  digitalWrite(T4, LOW);
  delay(500);
  
  //TEMPO DESCONECTADO PARA O MOTOR PARAR
  digitalWrite(T2, LOW);
  delay(200);
  }

  if ((voltage > 3.00)&&(voltage < 4.00)) {
      //NUMERO 3
  digitalWrite(DISPLAY_A, LOW);
  digitalWrite(DISPLAY_B, LOW);
  digitalWrite(DISPLAY_C, LOW);
  digitalWrite(DISPLAY_D, LOW);
  digitalWrite(DISPLAY_E, HIGH);
  digitalWrite(DISPLAY_F, HIGH);
  digitalWrite(DISPLAY_G, LOW);
  digitalWrite(DISPLAY_H, HIGH);

    //DESLIGAR OS DOIS RELES
  digitalWrite(Rele_01, LOW);
  digitalWrite(Rele_02, LOW);
  
  delay(100);
  }

  if ((voltage > 4.00)&&(voltage < 4.99)) {
      //NUMERO 4
  digitalWrite(DISPLAY_A, HIGH);
  digitalWrite(DISPLAY_B, LOW);
  digitalWrite(DISPLAY_C, LOW);
  digitalWrite(DISPLAY_D, HIGH);
  digitalWrite(DISPLAY_E, HIGH);
  digitalWrite(DISPLAY_F, LOW);
  digitalWrite(DISPLAY_G, LOW);
  digitalWrite(DISPLAY_H, HIGH);

        //LIGAR O RELE 4
  digitalWrite(Rele_01, HIGH);
  digitalWrite(Rele_02, LOW);
  
  delay(100);
  }

if (voltage > 4.99) {
      //NUMERO 5
  digitalWrite(DISPLAY_A, LOW);
  digitalWrite(DISPLAY_B, HIGH);
  digitalWrite(DISPLAY_C, LOW);
  digitalWrite(DISPLAY_D, LOW);
  digitalWrite(DISPLAY_E, HIGH);
  digitalWrite(DISPLAY_F, LOW);
  digitalWrite(DISPLAY_G, LOW);
  digitalWrite(DISPLAY_H, HIGH);
  
  //LIGA O RELE 5
  digitalWrite(Rele_01, LOW);
  digitalWrite(Rele_02, HIGH);
  
  delay(100);
  }
}
