#include <LiquidCrystal.h>

//LCD
int RS = 13;
int E = 12;
int DB4 = 11;
int DB5 = 10;
int DB6 = 9;
int DB7 = 8;
LiquidCrystal lcd(RS, E, DB4, DB5, DB6, DB7);

int Col_1 = 1;
int Col_2 = 2;
int Col_3 = 3;
int Linha_1 = 4;
int Linha_2 = 5;
int Linha_3 = 6;
int Linha_4 = 7;

void setup() {
  pinMode(Col_1, OUTPUT);
  pinMode(Col_2, OUTPUT);
  pinMode(Col_3, OUTPUT);
  pinMode(Linha_1, INPUT);
  pinMode(Linha_2, INPUT);
  pinMode(Linha_3, INPUT);
  pinMode(Linha_4, INPUT);
  // set up the LCD's number of columns and rows: 
  lcd.begin(16, 2);
  // Print a message to the LCD.
  lcd.print("Digite uma tecla.");
}

void loop() {
  
  //MAPEIA COLUNA 1
  digitalWrite(Col_1, HIGH);
  digitalWrite(Col_2, LOW);
  digitalWrite(Col_3, LOW);
  int Bontao_1 = digitalRead(Linha_1);
  if (Bontao_1){
    lcd.setCursor(0, 1);
    lcd.print("Botao 1.");
  }
  int Bontao_4 = digitalRead(Linha_2);
  if (Bontao_4){
    lcd.setCursor(0, 1);
    lcd.print("Botao 4.");
  }
  int Bontao_7 = digitalRead(Linha_3);
  if (Bontao_7){
    lcd.setCursor(0, 1);
    lcd.print("Botao 7.");
  }
  int Bontao_asterisco = digitalRead(Linha_4);
  if (Bontao_asterisco){
    lcd.setCursor(0, 1);
    lcd.print("Botao asterisco.");
  }
  
  //MAPEIA COLUNA 2
  digitalWrite(Col_1, LOW);
  digitalWrite(Col_2, HIGH);
  digitalWrite(Col_3, LOW);
  int Bontao_2 = digitalRead(Linha_1);
  if (Bontao_2){
    lcd.setCursor(0, 1);
    lcd.print("Botao 2.");
  }
  int Bontao_5 = digitalRead(Linha_2);
  if (Bontao_5){
    lcd.setCursor(0, 1);
    lcd.print("Botao 5.");
  }
  int Bontao_8 = digitalRead(Linha_3);
  if (Bontao_8){
    lcd.setCursor(0, 1);
    lcd.print("Botao 8.");
  }
  int Bontao_0 = digitalRead(Linha_4);
  if (Bontao_0){
    lcd.setCursor(0, 1);
    lcd.print("Botao 0.");
  }
  
  //MAPEIA COLUNA 3
  digitalWrite(Col_1, LOW);
  digitalWrite(Col_2, LOW);
  digitalWrite(Col_3, HIGH);
  int Bontao_3 = digitalRead(Linha_1);
  if (Bontao_3){
    lcd.setCursor(0, 1);
    lcd.print("Botao 3.");
  }
  int Bontao_6 = digitalRead(Linha_2);
  if (Bontao_6){
    lcd.setCursor(0, 1);
    lcd.print("Botao 6.");
  }
  int Bontao_9 = digitalRead(Linha_3);
  if (Bontao_9){
    lcd.setCursor(0, 1);
    lcd.print("Botao 9.");
  }
  int Bontao_cerquilha = digitalRead(Linha_4);
  if (Bontao_cerquilha){
    lcd.setCursor(0, 1);
    lcd.print("cerquilha.");
  }  
}

