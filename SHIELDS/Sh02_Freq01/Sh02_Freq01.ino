#include <LiquidCrystal.h>

LiquidCrystal lcd(13,12,11,10,9,8);

//GERADOR DE FREQUENCIA
#define Q 30000
//Faixa: 31Hz a 7200Hz
#define F3 160
#define PinoGerador 6
#define PinoFreq 0

long freq, tempo;
int pulsos;
boolean pulso;
void setup() {
  pulso=HIGH;
  pinMode(PinoFreq,INPUT);
  lcd.begin(16, 2);
  lcd.setCursor(1,0);
  lcd.print("FREQUENCIMETRO");
  
  //GERADOR DE FREQUENCIA  
  pinMode(PinoGerador, OUTPUT);
  tone(PinoGerador,F3,Q);
}

void loop() {
  tempo = millis();
  if(digitalRead(PinoFreq)==HIGH)
  {
    if(pulso==HIGH)
    {
      pulsos = pulsos + 1;
    }

    pulso=LOW; 

  }
  else{
    pulso=HIGH;
  }

  if(tempo%2000==0){
    freq = pulsos/2;
    lcd.setCursor(7,1);
    lcd.print(freq);
    lcd.print("Hz");
    pulsos=0;  
  }
}
