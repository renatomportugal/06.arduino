#include <LiquidCrystal.h>

//LCD
int RS = 13;
int E = 12;
int DB4 = 11;
int DB5 = 10;
int DB6 = 9;
int DB7 = 8;

LiquidCrystal lcd(RS, E, DB4, DB5, DB6, DB7);

//BATERIA
byte BatPos2[] = { B01111, B01111, B11111, B11111, B11111, B11111, B01111, B01111};
byte BatPos1[] = { B01111, B01001, B11001, B11001, B11001, B11001, B01001, B01111};
byte BatPos0[] = { B01111, B01000, B11000, B11000, B11000, B11000, B01000, B01111};
//byte BatMeio2[] = { B11111, B00000, B00000, B00000, B00000, B00000, B00000, B11111};
byte BatMeio2[] = { B11111, B00000, B00000, B00100, B00100, B00000, B00000, B11111};
byte BatMeio3[] = { B11111, B11111, B11111, B11111, B11111, B11111, B11111, B11111};
byte BatMeio4[] = { B11111, B00111, B00111, B00111, B00111, B00111, B00111, B11111};
byte BatNeg0[] = { B11111, B00001, B00001, B00001, B00001, B00001, B00001, B11111};

//CHAR
byte customChar[] = { B11100, B01000, B01000, B00010, B00111, B10010, B10000, B11000};

void setup() {
  // set up the LCD's number of columns and rows: 
  lcd.begin(16, 2);

  lcd.createChar(1, BatPos2);
  lcd.createChar(2, BatPos1);
  lcd.createChar(3, BatPos0);
  lcd.createChar(4, BatMeio2);
  lcd.createChar(5, BatMeio3);
  lcd.createChar(6, BatMeio4);
  lcd.createChar(7, BatNeg0);

  //Bat100(12,0);
  //lcd.setCursor(12,1);
  //lcd.write("100%");

  //Bat80(12,0);
  //lcd.setCursor(13,1);
  //lcd.write("80%");

  //Bat75(12,0);
  //lcd.setCursor(13,1);
  //lcd.write("75%");

  //Bat60(12,0);
  //lcd.setCursor(13,1);
  //lcd.write("60%");

  //Bat55(12,0);
  //lcd.setCursor(13,1);
  //lcd.write("55%");

  //Bat50(12,0);
  //lcd.setCursor(13,1);
  //lcd.write("50%");

  //Bat40(12,0);
  //lcd.setCursor(13,1);
  //lcd.write("40%");

  //Bat30(12,0);
  //lcd.setCursor(13,1);
  //lcd.write("30%");

  Bat25(12,0);
  lcd.setCursor(13,1);
  lcd.write("25%");

  //Bat10(12,0);
  //lcd.setCursor(13,1);
  //lcd.write("10%");

  //Bat5(12,0);
  //lcd.setCursor(14,1);
  //lcd.write("5%");

  //Bat0(12,0);
  //lcd.setCursor(14,1);
  //lcd.write("0%");


}

void loop() {
  
}

void Bat100(int coluna, int linha){
  lcd.home();
  lcd.setCursor(coluna,linha);
  lcd.write(byte(1));

  lcd.setCursor(coluna+1,linha);
  lcd.write(byte(5));

  lcd.setCursor(coluna+2,linha);
  lcd.write(byte(5));

  lcd.setCursor(coluna+3,linha);
  lcd.write(byte(5));
}

void Bat80(int coluna, int linha){
  lcd.home();
  lcd.setCursor(coluna,linha);
  lcd.write(byte(2));

  lcd.setCursor(coluna+1,linha);
  lcd.write(byte(5));

  lcd.setCursor(coluna+2,linha);
  lcd.write(byte(5));

  lcd.setCursor(coluna+3,linha);
  lcd.write(byte(5));
}

void Bat75(int coluna, int linha){
  lcd.home();
  lcd.setCursor(coluna,linha);
  lcd.write(byte(3));

  lcd.setCursor(coluna+1,linha);
  lcd.write(byte(5));

  lcd.setCursor(coluna+2,linha);
  lcd.write(byte(5));

  lcd.setCursor(coluna+3,linha);
  lcd.write(byte(5));
}

void Bat60(int coluna, int linha){
  lcd.home();
  lcd.setCursor(coluna,linha);
  lcd.write(byte(3));

  lcd.setCursor(coluna+1,linha);
  lcd.write(byte(6));

  lcd.setCursor(coluna+2,linha);
  lcd.write(byte(5));

  lcd.setCursor(coluna+3,linha);
  lcd.write(byte(5));
}

void Bat55(int coluna, int linha){
  lcd.home();
  lcd.setCursor(coluna,linha);
  lcd.write(byte(3));

  lcd.setCursor(coluna+1,linha);
  lcd.write(byte(7));

  lcd.setCursor(coluna+2,linha);
  lcd.write(byte(5));

  lcd.setCursor(coluna+3,linha);
  lcd.write(byte(5));
}

void Bat50(int coluna, int linha){
  lcd.home();
  lcd.setCursor(coluna,linha);
  lcd.write(byte(3));

  lcd.setCursor(coluna+1,linha);
  lcd.write(byte(4));

  lcd.setCursor(coluna+2,linha);
  lcd.write(byte(5));

  lcd.setCursor(coluna+3,linha);
  lcd.write(byte(5));
}

void Bat40(int coluna, int linha){
  lcd.home();
  lcd.setCursor(coluna,linha);
  lcd.write(byte(3));

  lcd.setCursor(coluna+1,linha);
  lcd.write(byte(4));

  lcd.setCursor(coluna+2,linha);
  lcd.write(byte(6));

  lcd.setCursor(coluna+3,linha);
  lcd.write(byte(5));
}

void Bat30(int coluna, int linha){
  lcd.home();
  lcd.setCursor(coluna,linha);
  lcd.write(byte(3));

  lcd.setCursor(coluna+1,linha);
  lcd.write(byte(4));

  lcd.setCursor(coluna+2,linha);
  lcd.write(byte(7));

  lcd.setCursor(coluna+3,linha);
  lcd.write(byte(5));
}

void Bat25(int coluna, int linha){
  lcd.home();
  lcd.setCursor(coluna,linha);
  lcd.write(byte(3));

  lcd.setCursor(coluna+1,linha);
  lcd.write(byte(4));

  lcd.setCursor(coluna+2,linha);
  lcd.write(byte(4));

  lcd.setCursor(coluna+3,linha);
  lcd.write(byte(5));
}

void Bat10(int coluna, int linha){
  lcd.home();
  lcd.setCursor(coluna,linha);
  lcd.write(byte(3));

  lcd.setCursor(coluna+1,linha);
  lcd.write(byte(4));

  lcd.setCursor(coluna+2,linha);
  lcd.write(byte(4));

  lcd.setCursor(coluna+3,linha);
  lcd.write(byte(6));
}

void Bat5(int coluna, int linha){
  lcd.home();
  lcd.setCursor(coluna,linha);
  lcd.write(byte(3));

  lcd.setCursor(coluna+1,linha);
  lcd.write(byte(4));

  lcd.setCursor(coluna+2,linha);
  lcd.write(byte(4));

  lcd.setCursor(coluna+3,linha);
  lcd.write(byte(7));
}

void Bat0(int coluna, int linha){
  lcd.home();
  lcd.setCursor(coluna,linha);
  lcd.write(byte(3));

  lcd.setCursor(coluna+1,linha);
  lcd.write(byte(4));

  lcd.setCursor(coluna+2,linha);
  lcd.write(byte(4));

  lcd.setCursor(coluna+3,linha);
  lcd.write(byte(4));
}