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

void loop() {
  int sensorValue = analogRead(Pot_A0);
  float voltage = sensorValue * (5.0 / 1023.0);

  if (voltage < 0.22) {

  //DESLIGA TUDO
  digitalWrite(DISPLAY_A, HIGH);
  digitalWrite(DISPLAY_B, HIGH);
  digitalWrite(DISPLAY_C, HIGH);
  digitalWrite(DISPLAY_D, HIGH);
  digitalWrite(DISPLAY_E, HIGH);
  digitalWrite(DISPLAY_F, HIGH);
  digitalWrite(DISPLAY_G, HIGH);
  digitalWrite(DISPLAY_H, HIGH);
  }

if ((voltage > 0.22)&&(voltage < 0.44)) {
  //LIGA TUDO
  digitalWrite(DISPLAY_A, LOW);
  digitalWrite(DISPLAY_B, LOW);
  digitalWrite(DISPLAY_C, LOW);
  digitalWrite(DISPLAY_D, LOW);
  digitalWrite(DISPLAY_E, LOW);
  digitalWrite(DISPLAY_F, LOW);
  digitalWrite(DISPLAY_G, LOW);
  digitalWrite(DISPLAY_H, LOW);
}
  
  if ((voltage > 0.44)&&(voltage < 0.66)) {
      //NUMERO 0
  digitalWrite(DISPLAY_A, LOW);
  digitalWrite(DISPLAY_B, LOW);
  digitalWrite(DISPLAY_C, LOW);
  digitalWrite(DISPLAY_D, LOW);
  digitalWrite(DISPLAY_E, LOW);
  digitalWrite(DISPLAY_F, LOW);
  digitalWrite(DISPLAY_G, HIGH);
  digitalWrite(DISPLAY_H, HIGH);
  }

  if ((voltage > 0.66)&&(voltage < 0.88)) {
      //NUMERO 1
  digitalWrite(DISPLAY_A, HIGH);
  digitalWrite(DISPLAY_B, LOW);
  digitalWrite(DISPLAY_C, LOW);
  digitalWrite(DISPLAY_D, HIGH);
  digitalWrite(DISPLAY_E, HIGH);
  digitalWrite(DISPLAY_F, HIGH);
  digitalWrite(DISPLAY_G, HIGH);
  digitalWrite(DISPLAY_H, HIGH);
  }

  if ((voltage > 0.88)&&(voltage < 1.10)) {
      //NUMERO 2
  digitalWrite(DISPLAY_A, LOW);
  digitalWrite(DISPLAY_B, LOW);
  digitalWrite(DISPLAY_C, HIGH);
  digitalWrite(DISPLAY_D, LOW);
  digitalWrite(DISPLAY_E, LOW);
  digitalWrite(DISPLAY_F, HIGH);
  digitalWrite(DISPLAY_G, LOW);
  digitalWrite(DISPLAY_H, HIGH);
  }

   if ((voltage > 1.10)&&(voltage < 1.32)) {
      //NUMERO 3
  digitalWrite(DISPLAY_A, LOW);
  digitalWrite(DISPLAY_B, LOW);
  digitalWrite(DISPLAY_C, LOW);
  digitalWrite(DISPLAY_D, LOW);
  digitalWrite(DISPLAY_E, HIGH);
  digitalWrite(DISPLAY_F, HIGH);
  digitalWrite(DISPLAY_G, LOW);
  digitalWrite(DISPLAY_H, HIGH);
   }

   if ((voltage > 1.32)&&(voltage < 1.54)) {
      //NUMERO 4
  digitalWrite(DISPLAY_A, HIGH);
  digitalWrite(DISPLAY_B, LOW);
  digitalWrite(DISPLAY_C, LOW);
  digitalWrite(DISPLAY_D, HIGH);
  digitalWrite(DISPLAY_E, HIGH);
  digitalWrite(DISPLAY_F, LOW);
  digitalWrite(DISPLAY_G, LOW);
  digitalWrite(DISPLAY_H, HIGH);
   }

if ((voltage > 1.54)&&(voltage < 1.76)) {
//NUMERO 5
  digitalWrite(DISPLAY_A, LOW);
  digitalWrite(DISPLAY_B, HIGH);
  digitalWrite(DISPLAY_C, LOW);
  digitalWrite(DISPLAY_D, LOW);
  digitalWrite(DISPLAY_E, HIGH);
  digitalWrite(DISPLAY_F, LOW);
  digitalWrite(DISPLAY_G, LOW);
  digitalWrite(DISPLAY_H, HIGH);
}

if ((voltage > 1.76)&&(voltage < 1.98)) {
    //NUMERO 06
  digitalWrite(DISPLAY_A, LOW);
  digitalWrite(DISPLAY_B, HIGH);
  digitalWrite(DISPLAY_C, LOW);
  digitalWrite(DISPLAY_D, LOW);
  digitalWrite(DISPLAY_E, LOW);
  digitalWrite(DISPLAY_F, LOW);
  digitalWrite(DISPLAY_G, LOW);
  digitalWrite(DISPLAY_H, HIGH);
}

if ((voltage > 1.98)&&(voltage < 2.20)) {
    //NUMERO 07
  digitalWrite(DISPLAY_A, LOW);
  digitalWrite(DISPLAY_B, LOW);
  digitalWrite(DISPLAY_C, LOW);
  digitalWrite(DISPLAY_D, HIGH);
  digitalWrite(DISPLAY_E, HIGH);
  digitalWrite(DISPLAY_F, HIGH);
  digitalWrite(DISPLAY_G, HIGH);
  digitalWrite(DISPLAY_H, HIGH);
}

if ((voltage > 2.20)&&(voltage < 2.42)) {
    //NUMERO 08
  digitalWrite(DISPLAY_A, LOW);
  digitalWrite(DISPLAY_B, LOW);
  digitalWrite(DISPLAY_C, LOW);
  digitalWrite(DISPLAY_D, LOW);
  digitalWrite(DISPLAY_E, LOW);
  digitalWrite(DISPLAY_F, LOW);
  digitalWrite(DISPLAY_G, LOW);
  digitalWrite(DISPLAY_H, HIGH);
}

if ((voltage > 2.42)&&(voltage < 2.64)) {
    //NUMERO 09
  digitalWrite(DISPLAY_A, LOW);
  digitalWrite(DISPLAY_B, LOW);
  digitalWrite(DISPLAY_C, LOW);
  digitalWrite(DISPLAY_D, HIGH);
  digitalWrite(DISPLAY_E, HIGH);
  digitalWrite(DISPLAY_F, LOW);
  digitalWrite(DISPLAY_G, LOW);
  digitalWrite(DISPLAY_H, HIGH);
}

if ((voltage > 2.64)&&(voltage < 2.86)) {
    //LETRA A
  digitalWrite(DISPLAY_A, LOW);
  digitalWrite(DISPLAY_B, LOW);
  digitalWrite(DISPLAY_C, LOW);
  digitalWrite(DISPLAY_D, HIGH);
  digitalWrite(DISPLAY_E, LOW);
  digitalWrite(DISPLAY_F, LOW);
  digitalWrite(DISPLAY_G, LOW);
  digitalWrite(DISPLAY_H, HIGH);
}

if ((voltage > 2.86)&&(voltage < 3.08)) {
    //LETRA B
  digitalWrite(DISPLAY_A, HIGH);
  digitalWrite(DISPLAY_B, HIGH);
  digitalWrite(DISPLAY_C, LOW);
  digitalWrite(DISPLAY_D, LOW);
  digitalWrite(DISPLAY_E, LOW);
  digitalWrite(DISPLAY_F, LOW);
  digitalWrite(DISPLAY_G, LOW);
  digitalWrite(DISPLAY_H, HIGH);
}

if ((voltage > 3.08)&&(voltage < 3.30)) {
    //LETRA C
  digitalWrite(DISPLAY_A, LOW);
  digitalWrite(DISPLAY_B, HIGH);
  digitalWrite(DISPLAY_C, HIGH);
  digitalWrite(DISPLAY_D, LOW);
  digitalWrite(DISPLAY_E, LOW);
  digitalWrite(DISPLAY_F, LOW);
  digitalWrite(DISPLAY_G, HIGH);
  digitalWrite(DISPLAY_H, HIGH);
}

if ((voltage > 3.30)&&(voltage < 3.52)) {
    //LETRA D
  digitalWrite(DISPLAY_A, HIGH);
  digitalWrite(DISPLAY_B, LOW);
  digitalWrite(DISPLAY_C, LOW);
  digitalWrite(DISPLAY_D, LOW);
  digitalWrite(DISPLAY_E, LOW);
  digitalWrite(DISPLAY_F, HIGH);
  digitalWrite(DISPLAY_G, LOW);
  digitalWrite(DISPLAY_H, HIGH);
}

if ((voltage > 3.52)&&(voltage < 3.74)) {
    //LETRA E
  digitalWrite(DISPLAY_A, LOW);
  digitalWrite(DISPLAY_B, HIGH);
  digitalWrite(DISPLAY_C, HIGH);
  digitalWrite(DISPLAY_D, LOW);
  digitalWrite(DISPLAY_E, LOW);
  digitalWrite(DISPLAY_F, LOW);
  digitalWrite(DISPLAY_G, LOW);
  digitalWrite(DISPLAY_H, HIGH);
}

if ((voltage > 3.74)&&(voltage < 3.96)) {
    //LETRA F
  digitalWrite(DISPLAY_A, LOW);
  digitalWrite(DISPLAY_B, HIGH);
  digitalWrite(DISPLAY_C, HIGH);
  digitalWrite(DISPLAY_D, HIGH);
  digitalWrite(DISPLAY_E, LOW);
  digitalWrite(DISPLAY_F, LOW);
  digitalWrite(DISPLAY_G, LOW);
  digitalWrite(DISPLAY_H, HIGH);
}

if ((voltage > 3.96)&&(voltage < 4.18)) {
    //LETRA H
  digitalWrite(DISPLAY_A, HIGH);
  digitalWrite(DISPLAY_B, LOW);
  digitalWrite(DISPLAY_C, LOW);
  digitalWrite(DISPLAY_D, HIGH);
  digitalWrite(DISPLAY_E, LOW);
  digitalWrite(DISPLAY_F, LOW);
  digitalWrite(DISPLAY_G, LOW);
  digitalWrite(DISPLAY_H, HIGH);
}

if ((voltage > 4.18)&&(voltage < 4.40)) {
    //LETRA L
  digitalWrite(DISPLAY_A, HIGH);
  digitalWrite(DISPLAY_B, HIGH);
  digitalWrite(DISPLAY_C, HIGH);
  digitalWrite(DISPLAY_D, LOW);
  digitalWrite(DISPLAY_E, LOW);
  digitalWrite(DISPLAY_F, LOW);
  digitalWrite(DISPLAY_G, HIGH);
  digitalWrite(DISPLAY_H, HIGH);
}

if ((voltage > 4.40)&&(voltage < 4.62)) {
    //LETRA P
  digitalWrite(DISPLAY_A, LOW);
  digitalWrite(DISPLAY_B, LOW);
  digitalWrite(DISPLAY_C, HIGH);
  digitalWrite(DISPLAY_D, HIGH);
  digitalWrite(DISPLAY_E, LOW);
  digitalWrite(DISPLAY_F, LOW);
  digitalWrite(DISPLAY_G, LOW);
  digitalWrite(DISPLAY_H, HIGH);
}

if (voltage > 4.62) {
    //LETRA U
  digitalWrite(DISPLAY_A, HIGH);
  digitalWrite(DISPLAY_B, LOW);
  digitalWrite(DISPLAY_C, LOW);
  digitalWrite(DISPLAY_D, LOW);
  digitalWrite(DISPLAY_E, LOW);
  digitalWrite(DISPLAY_F, LOW);
  digitalWrite(DISPLAY_G, HIGH);
  digitalWrite(DISPLAY_H, HIGH);
}
}
   
