//__CONFIGURAÇÃO____________________________
// Shield 01
  #include "morse.h"

// Shield 02
// LCD
#include <LiquidCrystal.h>
//LCD
int RS = 13;
int E = 12;
int DB4 = 11;
int DB5 = 10;
int DB6 = 9;
int DB7 = 8;
LiquidCrystal lcd(RS, E, DB4, DB5, DB6, DB7);

// Ohmímetro
//Meça com um multímetro confiável e coloque aqui o valor em Ohms.
int rRef = 216;

// Shield 03
//Rele 01
int Rele_01 = 4;
//Rele 02
int Rele_02 = 5;

//__________________________________________
//___Regras de Operação_____________________

//__________________________________________
long tempo;

float analog, calculo;
int intAnalog, amostra1, amostra2, amostra3, amostra4, amostra5, resultado, mediaTotal;
bool hold;

int Medir(){
  //PRIMEIRA LEITURA
  calculo = float(analog*5/1024);
  amostra1 = float(rRef *(5-calculo)/calculo);
  delay(25);
    
  //SEGUNDA LEITURA
  calculo = float(analog*5/1024);
  amostra2 = float(rRef *(5-calculo)/calculo);
  delay(25);
    
  //TERCEIRA LEITURA
  calculo = float(analog*5/1024);
  amostra3 = float(rRef *(5-calculo)/calculo);
  delay(25);
    
  //QUARTA LEITURA
  calculo = float(analog*5/1024);
  amostra4 = float(rRef *(5-calculo)/calculo);
  delay(25);
    
  //QUINTA LEITURA
  calculo = float(analog*5/1024);
  amostra5 = float(rRef *(5-calculo)/calculo);
  delay(25);
    
  //MEDIA DAS LEITURAS
  mediaTotal = ((amostra1+amostra2+amostra3+amostra4+amostra5)/5);

  //IMPRIME NO LCD
  lcd.setCursor(0, 1);
  lcd.print(mediaTotal);
  lcd.print("      ");

  return mediaTotal;
}

int InverterLeitura(){
  digitalWrite(Rele_01, HIGH);
  digitalWrite(Rele_02, HIGH);
}

void setup()
{

  // Shield 02
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  // Print a message to the LCD.
  lcd.setCursor(0, 0);
  lcd.print("      ");
  teclarFrase("sos");
  //playDah();
  
  // Shield 03
  pinMode(Rele_01, OUTPUT);
  pinMode(Rele_02, OUTPUT);
  //LIGAR RELE 01
  //digitalWrite(Rele_01, HIGH);
  //digitalWrite(Rele_02, HIGH);
}

void loop()
{
  tempo = millis();
  
  if(tempo%500==0){
    analog = analogRead(5);
    intAnalog = analog;
    lcd.setCursor(12, 1);
    //lcd.print(5*analog/1024);
    lcd.print(intAnalog);
    lcd.print("   ");

    if (hold == false){
      if (intAnalog == 0){
        lcd.setCursor(0, 1);
        lcd.print("aberto");
        lcd.print("      ");
        hold == false;
      }else{
        lcd.setCursor(0, 0);
        lcd.print("      ");

        int qtdLeituras = 20;
        int leiturasRestantes = qtdLeituras;
        int cont = 0;
        bool leituraEstavel = false;
        int leitura, leituraAnterior, valorDireto, valorInverso;

        for(int i = 0; i <= qtdLeituras; i++){
          if(leiturasRestantes >= (5 - cont)){
            leitura = Medir();
            if(i < 1){
              leituraAnterior = leitura;
            }
            if(leitura == leituraAnterior){
              cont++;
              if(cont == 5){
                leituraEstavel = true;
                leiturasRestantes = 0;
                valorDireto = leitura;
              }
            }else{
              leituraAnterior = leitura;
              cont = 0;
            }
          }

          leiturasRestantes--;
          lcd.setCursor(0, 0);
          lcd.print(i);
        } 
        if (leituraEstavel == true){
          playDit();
          playDit();
          playDit();
          hold = true;

          InverterLeitura();
        }

      }
    }else{
      if (intAnalog == 0){
        lcd.setCursor(0, 1);
        lcd.print("aberto");
        lcd.print("      ");
        hold = false;
      }
      
    }
  }
}
