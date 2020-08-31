//Incluindo a Biblioteca
#include <LiquidCrystal.h>

//LCD
int RS = 13;
int E = 12;
int DB4 = 11;
int DB5 = 10;
int DB6 = 9;
int DB7 = 8;

long tempo;

float analog, calculo;
int amostra1, amostra2, amostra3, amostra4, amostra5, resultado, mediaTotal;

 //Meça com um multímetro confiável e coloque aqui o valor em Ohms.
 int rRef = 216;

LiquidCrystal lcd(RS, E, DB4, DB5, DB6, DB7);

void setup(){
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  // Print a message to the LCD.
  lcd.print("ohms");
  
  // set the cursor to column 0, line 1
  // (note: line 1 is the second row, since counting begins with 0):
  lcd.setCursor(0, 1);
  // print the number of seconds since reset:
  lcd.print(millis()/1000);
  
 


 analog = analogRead(5);

if (analog != 0){
   //PRIMEIRA LEITURA
   
   calculo = float(analog*5/1024);
   amostra1 = float(rRef *(5-calculo)/calculo);
   delay(50);
   
   //SEGUNDA LEITURA
   calculo = float(analog*5/1024);
   amostra2 = float(rRef *(5-calculo)/calculo);
   delay(50);
   
   //TERCEIRA LEITURA
   calculo = float(analog*5/1024);
   amostra3 = float(rRef *(5-calculo)/calculo);
   delay(50);
   
   //QUARTA LEITURA
   calculo = float(analog*5/1024);
   amostra4 = float(rRef *(5-calculo)/calculo);
   delay(50);
   
   //QUINTA LEITURA
   calculo = float(analog*5/1024);
   amostra5 = float(rRef *(5-calculo)/calculo);
   delay(50);
   
   //MEDIA DAS LEITURAS
   mediaTotal = ((amostra1+amostra2+amostra3+amostra4+amostra5)/5);
  
   //IMPRIME NO LCD
  lcd.setCursor(0, 1);
  lcd.print(mediaTotal);
  lcd.print("      ");
}else{
  lcd.setCursor(0, 1);
  lcd.print("aberto");
  lcd.print("      ");
  }
}

void loop(){
  tempo = millis();
  analog = analogRead(5);
  if(tempo%400==0){
    lcd.setCursor(12, 1);
    //lcd.print(5*analog/1024);
    lcd.print(int(analog));
    lcd.print("   ");

    if (analog != 0){
   //PRIMEIRA LEITURA
   
   calculo = float(analog*5/1024);
   amostra1 = float(rRef *(5-calculo)/calculo);
   delay(50);
   
   //SEGUNDA LEITURA
   calculo = float(analog*5/1024);
   amostra2 = float(rRef *(5-calculo)/calculo);
   delay(50);
   
   //TERCEIRA LEITURA
   calculo = float(analog*5/1024);
   amostra3 = float(rRef *(5-calculo)/calculo);
   delay(50);
   
   //QUARTA LEITURA
   calculo = float(analog*5/1024);
   amostra4 = float(rRef *(5-calculo)/calculo);
   delay(50);
   
   //QUINTA LEITURA
   calculo = float(analog*5/1024);
   amostra5 = float(rRef *(5-calculo)/calculo);
   delay(50);
   
   //MEDIA DAS LEITURAS
   mediaTotal = ((amostra1+amostra2+amostra3+amostra4+amostra5)/5);
  
   //IMPRIME NO LCD
  lcd.setCursor(0, 1);
  lcd.print(mediaTotal);
  lcd.print("      ");
}else{
  lcd.setCursor(0, 1);
  lcd.print("aberto");
  lcd.print("      ");
  }
  
  }
}
