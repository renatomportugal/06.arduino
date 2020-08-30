// 1. INCLUDES
#include "stdio.h"

// 2. PINOS
// 2.1. SHIELD 04
// 2.1.1. DISPLAY 7 SEG
int pino_SRCLK = 13;
int pino_SER = 12;
int pino_RCLK = 11;
int pino_SRCLR_inv = 10;
int pino_OE_inv = 9;

// 4. DECLARACAO DE VARIAVEIS
// 4.1.
int digito_1,digito_2,digito_3,digito_4,digito_5,digito_6,digito_7;
int dadoInt1,dadoInt2,dadoInt3,dadoInt4,dadoInt5,dadoInt6,dadoInt7;

void setup(){
// 1. DISPLAY 7 SEG
  pinMode(pino_SRCLK, OUTPUT);
  pinMode(pino_SER, OUTPUT);
  pinMode(pino_RCLK, OUTPUT);
  pinMode(pino_SRCLR_inv, OUTPUT);
  pinMode(pino_OE_inv, OUTPUT);
 
// 3. PREPARA O SHIFT REGISTER
 digitalWrite(pino_SRCLK, LOW);
 digitalWrite(pino_SER, LOW);
 digitalWrite(pino_RCLK, HIGH);
 digitalWrite(pino_SRCLR_inv, LOW);
 digitalWrite(pino_SRCLR_inv, HIGH);
 digitalWrite(pino_OE_inv, HIGH);

 digito_1 = 1;
 digito_2 = 2;
 digito_3 = 3;
 digito_4 = 4;
 digito_5 = 5;
 digito_6 = 6;
 digito_7 = 7;
 
 dadoInt7 = dadoIntSemPonto(digito_7);
 dadoInt6 = dadoIntSemPonto(digito_6);
 dadoInt5 = dadoIntSemPonto(digito_5);
 dadoInt4 = dadoIntSemPonto(digito_4);
 dadoInt3 = dadoIntSemPonto(digito_3);
 dadoInt2 = dadoIntSemPonto(digito_2);
 dadoInt1 = dadoIntSemPonto(digito_1);
 
 ShiftRegEnviaInt(pino_SER,dadoInt7);
 ShiftRegEnviaInt(pino_SER,dadoInt6);
 ShiftRegEnviaInt(pino_SER,dadoInt5);
 ShiftRegEnviaInt(pino_SER,dadoInt4);
 ShiftRegEnviaInt(pino_SER,dadoInt3);
 ShiftRegEnviaInt(pino_SER,dadoInt2);
 ShiftRegEnviaInt(pino_SER,dadoInt1);
 
 digitalWrite(pino_OE_inv, LOW); 
}

void loop(){
 Pisca(50);
 delay(500);
 Pisca(100);
 delay(500);
 Pisca(200);
 delay(500);
 Pisca(500);
 delay(500);
}
//FIM DO PROGRAMA

/*--------------------------FUNCOES------------------------------------*/
// 1. FUNCAO QUE TRANSFORMA VALOR EM CODIGO PARA DISPLAY 7 SEG
int dadoIntSemPonto(int dadoCode){
  switch(dadoCode){
    case 0:
    return 63;
    break;
    case 1:
    return 6;
    break;
    case 2:
    return 91;
    break;
    case 3:
    return 79;
    break;
    case 4:
    return 102;
    break;
    case 5:
    return 109;
    break;
    case 6:
    return 124;
    break;
    case 7:
    return 7;
    break;
    case 8:
    return 127;
    break;
    case 9:
    return 103;
    break;
  }
}

// 2. FUNCAO QUE TRANSFORMA VALOR EM CODIGO PARA DISPLAY 7 SEG
int dadoIntComPonto(int dadoCode){
  switch(dadoCode){
    case 0:
    return 191;
    break;
    case 1:
    return 134;
    break;
    case 2:
    return 219;
    break;
    case 3:
    return 207;
    break;
    case 4:
    return 230;
    break;
    case 5:
    return 237;
    break;
    case 6:
    return 252;
    break;
    case 7:
    return 135;
    break;
    case 8:
    return 255;
    break;
    case 9:
    return 231;
    break;
  }
}

// 3. FUNCAO QUE ENVIA DADOS CHAR
  int ShiftRegEnviaChar(int PortaDados, char Dados[8]){
    for(int i=0;i<8;i++){
       if (Dados[i] == 1){digitalWrite(PortaDados, 1);}else{digitalWrite(PortaDados, LOW);}
       digitalWrite(pino_SRCLK, HIGH);
       digitalWrite(pino_RCLK, LOW);
       digitalWrite(pino_SRCLK, LOW);
       digitalWrite(pino_RCLK, HIGH);
    }  
    
  }

// 4. FUNCAO QUE ENVIA DADOS INT
  int ShiftRegEnviaInt(int PortaDados, int dadoInt){

    //CONVERTE PARA CHAR    
    char Dados[8];
    //Preenche o char Dados[8]  
    for(int i=8;i>0;--i){
    int j = i - 1;
    Dados[j] = dadoInt%2;
    dadoInt = dadoInt / 2;
    }
    
    for(int i=0;i<8;i++){
       if (Dados[i] == 1){digitalWrite(PortaDados, HIGH);}else{digitalWrite(PortaDados, LOW);}
        digitalWrite(pino_SRCLK, HIGH);
        digitalWrite(pino_RCLK, LOW);
        digitalWrite(pino_SRCLK, LOW);
        digitalWrite(pino_RCLK, HIGH);
        //delay(2);
    }
  }

// 5. FUNCAO QUE FAZ PISCAR
int Pisca(int tempo){
      digitalWrite(pino_OE_inv, HIGH);
      delay(tempo);
      digitalWrite(pino_OE_inv, LOW);
}
