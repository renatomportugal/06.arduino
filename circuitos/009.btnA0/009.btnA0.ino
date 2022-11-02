#include <LiquidCrystal.h>

//LCD
int RS = 13;
int E = 12;
int DB4 = 11;
int DB5 = 10;
int DB6 = 9;
int DB7 = 8;

/*
Neste simulador não está funcionando.
      VCC
       |
       R (2k)
 __/___|______________A0
|RIGHT |
|      R (330R)
|__/__ |
| UP   |
|      R (620R) 
|__/__ |
| DOWN |
|      R (1K)
|__/__ |
| LEFT |
|      R (3K3)
|__/__ |
|SELECT
|
GND

*/


LiquidCrystal lcd(RS, E, DB4, DB5, DB6, DB7);

void setup() {
 lcd.begin(16, 2);  
 lcd.setCursor(0,0);  
 lcd.print("Teclado A0");  
 lcd.setCursor(0,1);  
 lcd.print("Tecla:");  
}

void loop() {
  int botao;  
 botao = analogRead (0);  //Leitura do valor da porta analógica A0
 lcd.setCursor(8,1);
 //lcd.print (botao);
 if (botao < 100) {  
  lcd.print ("Direita ");
 }  
 else if (botao < 200) {  
  lcd.print ("Cima    ");
 }  
 else if (botao < 400){  
  lcd.print ("Baixo   ");
 }  
 else if (botao < 600){  
  lcd.print ("Esquerda");
 }  
 else if (botao < 800){  
  lcd.print ("Select  ");
 }
}
