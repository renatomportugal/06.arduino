/*
Título: Base Bread Board
Autor:  Renato Menezes Portugal

TODO:
Identifica Debounce e escolha de tecla repetida.
O debounce deve utilizar uma variável dentro do tempo estipulado (200ms).
Se a mesma tecla for acionada, aguardar o dobro do valor (400ms).
Passado o tempo de debounce (200ms), caso a mesma tecla for apertada esperar mais 200ms.
Utilizar outra variável para monitorar a repetição.

Em 12OUT25
Notou-se instabilidade no direcional. As teclas selecionar e sair serão substituídas por outras entradas.
O Enter será substituído pela seleção CIMA e a tecla de cima absorverá a tecla de baixo.

00. ESTRUTURA FÍSICA
_____________________________________________
__Botões_____________________________________
_Direcional (Dados Coletados)     LIMIAR
ENTRAR              - 0
----------------------------------15---------
Direita             - 27 a 71
----------------------------------100--------
Equerda             - 118 a 127
----------------------------------150--------
Sair                - 177
----------------------------------200--------
Potenciômetro 1     -
Potenciômetro 2     -
Duplo com Trava     - 
Botão 1             -
Botão 2             -
Led 1               -
Led 2               -
_____________________________________________
__PROBLEMAS__________________________________
Os botões têm problemas de mau contato e deve
ser verificado qual é o valor que aparece
considerando a margem de segurança, pois existe
a possibilidade de um botão entrar na faixa
de valores do outro.

_____________________________________________
__RESULTADOS DAS MEDIÇÕES____________________
O botão para baixo invadiu a faixa do boão para
a esquerda, então deve ser utilizado com menor
responsabilidade. Já o botão para direita e o
enter, são os mais confiáveis.
*/

// 1. INCLUDES
#include <LiquidCrystal.h>

// 2. PINOS
/*
A0 - Potenciômetro 1
A1 - Potenciômetro 2
A2 - Direcional com Enter
A3 - Switch 1
A4 - Switch 2
A5 - 
D2 - Led Amarelo
D3 - Led Verde

LCD
+-----------------------------+
|16  K     o                  |
|15  A     o                  |
| 1  VSS   o---- GND          |
| 2  VDD   o---- +5V          |
| 3  V0    o---- 1K no GND    |
| 4  RS    o---- Arduino 13   |
| 5  RW    o---- GND          |
| 6  E     o---- Arduino 12   |
| 7  DB0   o                  |
| 8  DB1   o                  |
| 9  DB2   o                  |
|10  DB3   o                  |
|11  DB4   o---- Arduino 11   |
|12  DB5   o---- Arduino 10   |
|13  DB6   o---- Arduino 9    |
|14  DB7   o---- Arduino 8    |
+-----------------------------+
*/

// 3. DECLARACAO DE VARIAVEIS
#define Pot_1 A0
#define Pot_2 A1
#define Direcional A2
#define Sw_1 A3
#define Sw_2 A4
#define LedAmarelo 2
#define LedVerde 3

//LCD
int RS = 13;
int E = 12;
int DB4 = 11;
int DB5 = 10;
int DB6 = 9;
int DB7 = 8;
LiquidCrystal lcd(RS, E, DB4, DB5, DB6, DB7);

void setup(){
    Serial.begin(115200);
    pinMode (Pot_1, INPUT);
    pinMode (Pot_2, INPUT);
    pinMode (Sw_1, INPUT);
    pinMode (Sw_2, INPUT);
    pinMode (Direcional, INPUT);
    pinMode(LedAmarelo, OUTPUT);
    pinMode(LedVerde, OUTPUT);
    lcd.begin(16, 2);
    lcd.setCursor(0, 0);
    lcd.print("APERTE UMA TECLA");
}

void loop(){
  //Leitura Sensores
  int sensorPot_1 = analogRead(Pot_1);
  int sensorPot_2 = analogRead(Pot_2);
  int sensorSw_1 = analogRead(Sw_1);
  int sensorSw_2 = analogRead(Sw_2);
  int sensorDirecional = analogRead(Direcional);
  
  //Mapeamento
  int mapsensorPot_1 = map(sensorPot_1,0,1023,0,255);
  int mapsensorPot_2 = map(sensorPot_2,0,1023,0,255);
  int mapsensorSw_1 = map(sensorSw_1,0,1023,0,255);
  int mapsensorSw_2 = map(sensorSw_2,0,1023,0,255);
  int mapsensorDirecional = map(sensorDirecional,0,1023,0,255);
    

  float VsensorPot_1 = sensorPot_1 * (5.0 / 1023.0);
  float VsensorPot_2 = sensorPot_2 * (5.0 / 1023.0);
  float VsensorSw_1 = sensorSw_1 * (5.0 / 1023.0);
  float VsensorSw_2 = sensorSw_2 * (5.0 / 1023.0);
  float VsensorDirecional = sensorDirecional * (5.0 / 1023.0);
  

/*
Serial.print(sensorDirecional);
Serial.print(";");
Serial.print(sensorPot_1);
Serial.print(";");
Serial.println(sensorPot_2);
*/

/*
  //Saída
  Serial.print("POT_1");
  Serial.print(";");
  Serial.print(mapsensorPot_1);
  Serial.print(";");
  Serial.print(VsensorPot_1);
  Serial.print(";");

  Serial.print("POT_2");
  Serial.print(";");
  Serial.print(mapsensorPot_2);
  Serial.print(";");
  Serial.print(VsensorPot_2);
  Serial.print(";");

  Serial.print("SW_1");
  Serial.print(";");
  Serial.print(mapsensorSw_1);
  Serial.print(";");
  Serial.print(VsensorSw_1);
  Serial.print(";");

  Serial.print("SW_2");
  Serial.print(";");
  Serial.print(mapsensorSw_2);
  Serial.print(";");
  Serial.print(VsensorSw_2);
  Serial.println(";");

  Serial.print("DIR");
  Serial.print(";");
  Serial.print(mapsensorDirecional);
  Serial.print(";");
  Serial.print(VsensorDirecional);
  Serial.print(";");
*/

//__ BOTOES____________________________________________________________________
  if((mapsensorPot_1 < 127)||(sensorSw_1 < 2)){
    digitalWrite(LedAmarelo, HIGH);
  }else{
    digitalWrite(LedAmarelo, LOW);
  }

  if((mapsensorPot_2 < 127)||(sensorSw_2 < 2)){
    digitalWrite(LedVerde, HIGH);
  }else{
    digitalWrite(LedVerde, LOW);
  }

 if (mapsensorDirecional < 15){
  // Serial.print(mapsensorDirecional);
  // Serial.print(": ");
  // Serial.println("DIREITA");
  lcd.setCursor(0, 0);
  lcd.print("ENTRAR          ");
  lcd.setCursor(0, 1);
  lcd.print("                ");
  lcd.setCursor(0, 1);
  lcd.print(mapsensorDirecional);
 }
 else if ((mapsensorDirecional > 15) && (mapsensorDirecional < 101)){
  // Serial.print(mapsensorDirecional);
  // Serial.print(": ");
  // Serial.println("CIMA");
  lcd.setCursor(0, 0);
  lcd.print("DIREITA           ");
  lcd.setCursor(0, 1);
  lcd.print("                ");
  lcd.setCursor(0, 1);
  lcd.print(mapsensorDirecional);
 }
 else if ((mapsensorDirecional > 100) && (mapsensorDirecional < 151)){
  // Serial.print(mapsensorDirecional);
  // Serial.print(": ");
  // Serial.println("ESQUERDA");
  lcd.setCursor(0, 0);
  lcd.print("ESQUERDA        ");
  lcd.setCursor(0, 1);
  lcd.print("                ");
  lcd.setCursor(0, 1);
  lcd.print(mapsensorDirecional);
 }
 else if ((mapsensorDirecional > 150) && (mapsensorDirecional < 201)){
  // Serial.print(mapsensorDirecional);
  // Serial.print(": ");
  // Serial.println("ENTER");
  lcd.setCursor(0, 0);
  lcd.print("SAIR            ");
  lcd.setCursor(0, 1);
  lcd.print("                ");
  lcd.setCursor(0, 1);
  lcd.print(mapsensorDirecional);
 }
 else {
  
 }
//__ BOTOES____________________________________________________________________

//__LED________________________________________________________________________

if ((mapsensorPot_1 > 126) || (sensorSw_1 < 10)){
  digitalWrite(LedAmarelo, HIGH);
 }else{
  digitalWrite(LedAmarelo, LOW);
 }

 if ((mapsensorPot_2 > 126) || (sensorSw_2 < 10)){
  digitalWrite(LedVerde, HIGH);
 }else{
  digitalWrite(LedVerde, LOW);
 }
 
/*
Serial.print(sensorSw_1);
Serial.print(" - ");
Serial.println(sensorSw_2);
*/

}
