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

String caractere;
String Frase;
int qtdCaractere;
int Codigo;
int pos;

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
 
 //Recebe a frase
 //Frase = "0123456789ACdEFHJLPUocuin .th";

  /* PALAVRAS PARA O PAINEL    _ _ _ _   _ _ _
  Cod
  Join
  HOJE
  FACA
  CAdA
  notA
  hoJE
  teLA
  PULO
  PELA
  PELO
  PELE
  Foi
  CASA
  CAdA
  */
  Frase = "ACdEFH.";
  
 //Verifica a quantidade de caracteres
 //qtdCaractere = ContaCaracteres(Frase);
 qtdCaractere = Frase.length();
 
//int Codigo = MostraQtdCaractere(qtdCaractere);
//caractere = "1";  

//int pos = 23;
//caractere = Frase.substring(pos,pos + 1);

//int Codigo = CodCaractere(caractere);
//ShiftRegEnviaInt(pino_SER,Codigo);

/*
//ENVIA CARACTERES do Fim ao começo
for (int i = qtdCaractere - 1; i > -1; i--){
  pos = i;
  caractere = Frase.substring(pos,pos + 1);
  Codigo = CodCaractere(caractere);
  //ShiftRegEnviaInt(pino_SER,Codigo);
  EnviaCaractere(Codigo);
}
*/

digitalWrite(pino_OE_inv, LOW);

//ENVIA CARACTERES
for (int i = 0; i < qtdCaractere; i++){
  pos = i;
  caractere = Frase.substring(pos,pos + 1);
  Codigo = CodCaractereInverso(caractere);
  //ShiftRegEnviaInt(pino_SER,Codigo);
  EnviaCaractere(Codigo);
  delay(400);
}

//digitalWrite(pino_OE_inv, LOW); 


  /*
  Frase = "0123456789ACdEFHJLPUocuin .th";
  Frase.substring(0,1) mostra 0
  Frase.substring(1,2) mostra 1
  Frase.substring(2,3) mostra 2
  Frase.substring(3,4) mostra 3
  Frase.substring(4,5) mostra 4
  Frase.substring(5,6) mostra 5
  Frase.substring(6,7) mostra 6
  Frase.substring(7,8) mostra 7
  Frase.substring(8,9) mostra 8
  Frase.substring(9,10) mostra 9
  Frase.substring(10,11) mostra A
  Frase.substring(11,12) mostra C
  Frase.substring(12,13) mostra d
  Frase.substring(13,14) mostra E
  Frase.substring(14,15) mostra F
  Frase.substring(15,16) mostra H
  Frase.substring(16,17) mostra J
  Frase.substring(17,18) mostra L
  Frase.substring(18,19) mostra P
  Frase.substring(19,20) mostra U
  Frase.substring(20,21) mostra o
  Frase.substring(21,22) mostra c
  Frase.substring(22,23) mostra u
  Frase.substring(23,24) mostra i
  Frase.substring(24,25) mostra n
  Frase.substring(25,26) mostra "nada"
  Frase.substring(26,27) mostra .
  Frase.substring(27,28) mostra t
  Frase.substring(28,29) mostra h
  
  */
}

void loop(){
//delay(1000);
//Pisca(500);


}

// Verificar o código do caractere
int CodCaractere (String caractere){
 if (caractere == "0"){return 63;}
 if (caractere == "1"){return 6;}
 if (caractere == "2"){return 91;}
 if (caractere == "3"){return 79;}
 if (caractere == "4"){return 102;}
 if (caractere == "5"){return 109;}
 if (caractere == "6"){return 124;}
 if (caractere == "7"){return 7;}
 if (caractere == "8"){return 127;}
 if (caractere == "9"){return 103;}
 if (caractere == "O"){return 63;}
 if (caractere == "A"){return 119;}
 if (caractere == "C"){return 57;}
 if (caractere == "d"){return 94;}
 if (caractere == "E"){return 121;}
 if (caractere == "F"){return 113;}
 if (caractere == "H"){return 118;}
 if (caractere == "J"){return 30;}
 if (caractere == "L"){return 56;}
 if (caractere == "P"){return 115;}
 if (caractere == "U"){return 62;}
 if (caractere == "o"){return 92;}
 if (caractere == "c"){return 88;}
 if (caractere == "u"){return 28;}
 if (caractere == "i"){return 4;}
 if (caractere == "t"){return 120;}
 if (caractere == "n"){return 84;}
 if (caractere == " "){return 0;}
 if (caractere == "."){return 128;}
 if (caractere == "h"){return 116;}
 if (caractere == "S"){return 109;}
}   

int CodCaractereInverso (String caractere){
 if (caractere == "0"){return 63;}
 if (caractere == "1"){return 48;}
 if (caractere == "2"){return 91;}
 if (caractere == "3"){return 120;}
 if (caractere == "4"){return 116;}
 if (caractere == "5"){return 109;}
 if (caractere == "6"){return 103;}
 if (caractere == "7"){return 56;}
 if (caractere == "8"){return 127;}
 if (caractere == "9"){return 124;}
 if (caractere == "O"){return 63;}
 if (caractere == "A"){return 126;}
 if (caractere == "C"){return 15;}
 if (caractere == "d"){return 115;}
 if (caractere == "E"){return 79;}
 if (caractere == "F"){return 78;}
 if (caractere == "H"){return 118;}
 if (caractere == "J"){return 51;}
 if (caractere == "L"){return 7;}
 if (caractere == "P"){return 94;}
 if (caractere == "U"){return 55;}
 if (caractere == "o"){return 99;}
 if (caractere == "c"){return 67;}
 if (caractere == "u"){return 35;}
 if (caractere == "i"){return 32;}
 if (caractere == "t"){return 71;}
 if (caractere == "n"){return 98;}
 if (caractere == " "){return 0;}
 if (caractere == "."){return 128;}
 if (caractere == "h"){return 100;}
 if (caractere == "S"){return 109;}
}

int MostraQtdCaractere (int qtdade){
 if (qtdade == 0){return 63;}
 if (qtdade == 1){return 6;}
 if (qtdade == 2){return 91;}
 if (qtdade == 3){return 79;}
 if (qtdade == 4){return 102;}
 if (qtdade == 5){return 109;}
 if (qtdade == 6){return 124;}
 if (qtdade == 7){return 7;}
 if (qtdade == 8){return 127;}
 if (qtdade == 9){return 103;}
}   
 
 int ContaCaracteres (String Frase){
 return Frase.length();
 
 }
 
 
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

  int Pisca(int tempo){
      digitalWrite(pino_OE_inv, HIGH);
      delay(tempo);
      digitalWrite(pino_OE_inv, LOW);
}

int DDD(){
  int casas = 7;
  caractere = "A";
  Codigo = CodCaractere(caractere);
  EnviaCaractere(Codigo);

  }

  int EnviaCaractere(int dadoInt){
    //CONVERTE PARA CHAR    
    char Dados[8];
    //Preenche o char Dados[8]  
    for(int i=8;i>0;--i){
    int j = i - 1;
    Dados[j] = dadoInt%2;
    dadoInt = dadoInt / 2;
    }
    
    for(int i=0;i<8;i++){
       if (Dados[i] == 1){digitalWrite(pino_SER, HIGH);}else{digitalWrite(pino_SER, LOW);}
        digitalWrite(pino_SRCLK, HIGH);
        digitalWrite(pino_RCLK, LOW);
        digitalWrite(pino_SRCLK, LOW);
        digitalWrite(pino_RCLK, HIGH);
        //delay(2);
    }
  }
