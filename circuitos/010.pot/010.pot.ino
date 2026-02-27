#include <LiquidCrystal.h>

//LCD
int RS = 13;
int E = 12;
int DB4 = 11;
int DB5 = 10;
int DB6 = 9;
int DB7 = 8;

//Botão
# define Pot_A0 A0

LiquidCrystal lcd(RS, E, DB4, DB5, DB6, DB7);

void setup() {
 lcd.begin(16, 2);
 lcd.setCursor(0,0);
 lcd.print("Valor do POT");
}

void loop() {
  int sensorA0 = analogRead(Pot_A0);
  lcd.print ("                ");
  lcd.setCursor(0,1);
  lcd.print (sensorA0);
  delay(200);
}