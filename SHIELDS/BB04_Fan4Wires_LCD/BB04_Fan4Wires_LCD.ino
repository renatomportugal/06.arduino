//Incluindo a Biblioteca
#include <LiquidCrystal.h>
//Fio Amarelo
float fanPWM = A2;
//Fio Azul
int   fanTach = A1;
//Potenciômetro
float fanPot = A3;
int fanPot_leitura;
int map_fanPot_leitura = 0;

//Precisa ser feito uma ligação com TIL117 e TIP122 ou TIP127
int Ventilador = 6;

//Botão VentMax
int VentMax = 2;
int VentMaxStatus = 0;

//LedVentMax
int LedVentMax = 1;

unsigned long SensorPulsTijd;

//LCD
int RS = 13;
int E = 12;
int DB4 = 11;
int DB5 = 10;
int DB6 = 9;
int DB7 = 8;
LiquidCrystal lcd(RS, E, DB4, DB5, DB6, DB7);

void setup()
 {
    pinMode(fanPWM, OUTPUT);
    pinMode(fanTach, INPUT);
    pinMode(fanPot, INPUT);

    pinMode(VentMax, INPUT);

    pinMode(Ventilador, OUTPUT);
    digitalWrite(fanTach,HIGH);
    
    pinMode(LedVentMax, OUTPUT);

    //LIGA O VENTILADOR NA VELOCIDADE MAXIMA
    digitalWrite(Ventilador, HIGH);

    lcd.begin(16, 2);
 }

void loop()
 {

    VentMaxStatus = digitalRead(VentMax);

    fanPot_leitura = analogRead(fanPot);
    map_fanPot_leitura = map(fanPot_leitura,0,1023,0,255);

    if((VentMaxStatus) || (map_fanPot_leitura > 127)){
        digitalWrite(LedVentMax, HIGH);
        analogWrite(A2, 255);
    }else{
        digitalWrite(LedVentMax, LOW);
        analogWrite(A2, 0);
    }

    

    
    // analogWrite(A2, map_fanPot_leitura);

 SensorPulsTijd = pulseIn(fanTach, LOW);
 double frequency = 1000000/SensorPulsTijd;


    lcd.setCursor(0, 0);
    lcd.print("MAP: ");
    lcd.print(map_fanPot_leitura);
    lcd.print("   ");
    lcd.setCursor(0, 1);
    lcd.print("RPM: ");
    lcd.print(1000*frequency/60,0);
    lcd.print("   ");    

 delay(500);
 }
