#include <LiquidCrystal.h>

//LCD
int RS = 13;
int E = 12;
int DB4 = 11;
int DB5 = 10;
int DB6 = 9;
int DB7 = 8;

LiquidCrystal lcd(RS, E, DB4, DB5, DB6, DB7);

//CHAR
byte customChar[] = {
  B11100,
  B01000,
  B01000,
  B00010,
  B00111,
  B10010,
  B10000,
  B11000
};

void setup() {
  // set up the LCD's number of columns and rows: 
  lcd.begin(16, 2);
  
  lcd.createChar(0, customChar);
  lcd.home();
  lcd.write(0);
}

void loop() {
  
}