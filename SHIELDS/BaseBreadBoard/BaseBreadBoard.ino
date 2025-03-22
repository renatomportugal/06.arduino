/*
Título: Base Bread Board
Autor:  Renato Menezes Portugal

00. ESTRUTURA FÍSICA
_____________________________________________
__Botões_____________________________________
_Direcional (Dados Coletados)     LIMIAR
Direita             - 0
----------------------------------15---------
Cima                - 27
----------------------------------40---------
Baixo               - 68 a 77
----------------------------------100--------
Equerda             - 118 a 127
----------------------------------150--------
Confirma (Enter)    - 177
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

// 2. PINOS
/*
A0 - Potenciômetro 1
A1 - Potenciômetro 2
A2 - Direcionai com Enter
A3 - Switch 1
A4 - Switch 2
A5 - 
D3 - Led Amarelo
D4 - Led Verde
D13 - Built in Led
*/

// 3. DECLARACAO DE VARIAVEIS
#define Pot_1 A0
#define Pot_2 A1
#define Direcional A2
#define Sw_1 A3
#define Sw_2 A4
#define LedAmarelo 2
#define LedVerde 3
#define LED_BUILTIN 13

void setup(){
    Serial.begin(115200);
    pinMode (Pot_1, INPUT);
    pinMode (Pot_2, INPUT);
    pinMode (Sw_1, INPUT);
    pinMode (Sw_2, INPUT);
    pinMode (Direcional, INPUT);
    pinMode(LedAmarelo, OUTPUT);
    pinMode(LedVerde, OUTPUT);
    pinMode(LED_BUILTIN, OUTPUT);
    
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
  Serial.println("DIREITA");
 }
 else if ((mapsensorDirecional > 14) && (mapsensorDirecional < 40)){
  Serial.println("CIMA");
 }
 else if ((mapsensorDirecional > 40) && (mapsensorDirecional < 100)){
  Serial.println("BAIXO");
 }
 else if ((mapsensorDirecional > 100) && (mapsensorDirecional < 150)){
  Serial.println("ESQUERDA");
 }
 else if ((mapsensorDirecional > 150) && (mapsensorDirecional < 200)){
  Serial.println("ENTER");
 }
 else {
  
 }
  
  
  
  //Serial.println("yyyyy");
  digitalWrite(LED_BUILTIN, HIGH);
  delay(200);

  digitalWrite(LED_BUILTIN, LOW);
  delay(200);
}
