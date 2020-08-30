//Gera frequencia no Falante
//Mostra no LCD a frequencia Lida pela Pot A2

/* LCD 16x2 - INÍCIO */
#include <LiquidCrystal.h>
#define RS 13
#define E 12
#define DB4 11
#define DB5 10
#define DB6 9
#define DB7 8
LiquidCrystal lcd(RS, E, DB4, DB5, DB6, DB7);
/* LCD 16x2 - FIM */

/* GERADOR DE FREQUENCIA - INÍCIO */
//Faixa: 31Hz a 7200Hz
int LerFreq, Freq;
int PinoGerador = 3;
long tempo;

/* GERADOR DE FREQUENCIA - FIM */

void setup() {
/* LCD 16x2 - INICIO */
  lcd.begin(16, 2);
  lcd.print("Frequencia:");
/* LCD 16x2 - FIM */  
}

void loop() {
  tempo = millis();
/* GERADOR DE FREQUENCIA - INÍCIO */  
  LerFreq = analogRead(A2);
  Freq = map(LerFreq,0,1023,31,7200);  
  tone(PinoGerador,Freq);
  
  if(tempo%400==0){
  lcd.setCursor(0, 1);
  lcd.print(Freq);
  lcd.print("      ");
  }  
/* GERADOR DE FREQUENCIA - FIM */  
}
