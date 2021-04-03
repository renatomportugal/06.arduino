//Modbus
#include <SimpleModbusSlave.h>

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

//Registradores Holding
enum 
{     
  ModbusVoltage,
  HOLDING_REGS_SIZE
};

unsigned int holdingRegs[HOLDING_REGS_SIZE]; 

void setup() {
  //Modbus Setup
  modbus_configure(9600, 1, 2, HOLDING_REGS_SIZE, 0);
  //modbus_configure(&Serial, 9600, SERIAL_8N1, 1, 2, HOLDING_REGS_SIZE, holdingRegs);
  //modbus_update_comms(9600, SERIAL_8N1, 1);
  
  //Serial
  //Serial.begin(9600);
  
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

void loop() {
  int sensorValue = analogRead(Pot_A0);
  float voltage = sensorValue * (5.0 / 1023.0);
  
  modbus_update(holdingRegs);

  //holdingRegs[TOTAL_ERRORS] = modbus_update(holdingRegs);
  holdingRegs[ModbusVoltage] = voltage;

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
  
    //LIGAR RELE 01
  digitalWrite(Rele_01, HIGH);
  digitalWrite(Rele_02, LOW);
  
  delay(100);
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
  
    //LIGAR RELE 02 E DESLIGA O RELE 01
  digitalWrite(Rele_01, LOW);
  digitalWrite(Rele_02, HIGH);  
  
  delay(100);
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
  
    //LIGAR OS DOIS RELES
  digitalWrite(Rele_01, HIGH);
  digitalWrite(Rele_02, HIGH);
  
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
  
    //DESLIGAR OS DOIS RELES
  digitalWrite(Rele_01, LOW);
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
  
    //DESLIGAR OS DOIS RELES
  digitalWrite(Rele_01, LOW);
  digitalWrite(Rele_02, LOW);
  
  delay(100);
  }
  
  //Serial
  //Serial.println(voltage);
}
