int i = 0;
int MR_inv = 13;
int CP = 12;
int OE_inv = 11;
int LE = 10;
int PortaB1 = 3;
int PortaB2 = 4;
int PortaB3 = 5;
int PortaB4 = 6;
int PortaB5 = 7;
int PortaB6 = 8;
int PortaB7 = 9;

int cont = 0;

void setup() {                
  pinMode(MR_inv, OUTPUT);
  pinMode(CP, OUTPUT);
  pinMode(OE_inv, OUTPUT);
  pinMode(LE, OUTPUT);
  pinMode(PortaB1, OUTPUT);
  pinMode(PortaB2, OUTPUT);
  pinMode(PortaB3, OUTPUT);
  pinMode(PortaB4, OUTPUT);
  pinMode(PortaB5, OUTPUT);
  pinMode(PortaB6, OUTPUT);
  pinMode(PortaB7, OUTPUT);
}

// the loop routine runs over and over again forever:
void loop() {
  //PREPARA O CLOCK (ALTO)
  digitalWrite(CP, HIGH);
  //RESETA O 164
  digitalWrite(MR_inv, LOW);
  //VOLTA O 164 AO ESTADO NORMAL
  digitalWrite(MR_inv, HIGH);
  //SELECIONA OS 573
  digitalWrite(OE_inv, LOW);
  //TRAVA OS 573
  digitalWrite(LE, LOW);
  
  for (i=0;i<5;i++){
  //DADO PARA A PORTA 1
  digitalWrite(PortaB1, HIGH);
  digitalWrite(PortaB2, HIGH);
  digitalWrite(PortaB3, HIGH);
  digitalWrite(PortaB4, HIGH);
  digitalWrite(PortaB5, HIGH);
  digitalWrite(PortaB6, HIGH);
  digitalWrite(PortaB7, HIGH);
  //CLOCK PULSE
  digitalWrite(CP, LOW);
  digitalWrite(CP, HIGH);
  }
    for (i=0;i<2;i++){
  //DADO PARA A PORTA 1
  digitalWrite(PortaB1, LOW);
  digitalWrite(PortaB2, LOW);
  digitalWrite(PortaB3, LOW);
  digitalWrite(PortaB4, LOW);
  digitalWrite(PortaB5, LOW);
  digitalWrite(PortaB6, LOW);
  digitalWrite(PortaB7, LOW);
  //CLOCK PULSE
  digitalWrite(CP, LOW);
  digitalWrite(CP, HIGH);
  }
  
  for (i=0;i<1;i++){
  //DADO PARA A PORTA 1
  digitalWrite(PortaB1, HIGH);
  digitalWrite(PortaB2, HIGH);
  digitalWrite(PortaB3, HIGH);
  digitalWrite(PortaB4, HIGH);
  digitalWrite(PortaB5, HIGH);
  digitalWrite(PortaB6, HIGH);
  digitalWrite(PortaB7, HIGH);
  //CLOCK PULSE
  digitalWrite(CP, LOW);
  digitalWrite(CP, HIGH);
  }
    
  //DESTRAVA OS 573
  digitalWrite(LE, HIGH);  
  for(;;);
}
