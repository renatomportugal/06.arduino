/*
LCD Pin Mapping (ASCII Diagram - Front View, Vertical):
Atenção: No meu modelo, o primeiro pino da esquerda é o pino 14.
Da esquerda para a direita ele decresce, e depois do 1 vem os pinos 15 e 16.

PINOS DO LCD_____________________________________________PINOS ARDUINO
__DB7______________________________________________Arduino 8
|   _DB6___________________________________________Arduino 9
|  |   _DB5________________________________________Arduino 10
|  |  |   _DB4_____________________________________Arduino 11
|  |  |  |   _DB3
|  |  |  |  |   _DB2
|  |  |  |  |  |   _DB1
|  |  |  |  |  |  |   _DB0
|  |  |  |  |  |  |  |   _E________________________Arduino 12
|  |  |  |  |  |  |  |  |   _RW____________________GND__________________________
|  |  |  |  |  |  |  |  |  |   _RS_________________Arduino 13                   |
|  |  |  |  |  |  |  |  |  |  |   _V0______________Resistor de Contraste (1K)___|
|  |  |  |  |  |  |  |  |  |  |  |   _VDD__________+5V                          |
|  |  |  |  |  |  |  |  |  |  |  |  |   _VSS_______GND__________________________|
|  |  |  |  |  |  |  |  |  |  |  |  |  |   _A
|  |  |  |  |  |  |  |  |  |  |  |  |  |  |   _k
|  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |
14 13 12 11 10 9  8  7  6  5  4  3  2  1  15 16 
o  o  o  o  o  o  o  o  o  o  o  o  o  o  o  o  
Ligar o resistor de contraste (1K) entre V0 (pino 3) e GND (pino 1).
Ligar o RW (pino 5) no GND.

+-----------------------------+
Outra discposição dos pinos do LCD:
+-----------------------------+
|16  K     o                  |
|15  A     o                  |
| 1  VSS   o---- GND          |
| 2  VDD   o---- +5V          |
| 3  V0    o---- 1K no GND    |
| 4  RS    o---- Arduino 13   |
| 5  RW    o---- GND          |
| 6  E     o---- Arduino 12   |
| 7  DB0   o                  |
| 8  DB1   o                  |
| 9  DB2   o                  |
|10  DB3   o                  |
|11  DB4   o---- Arduino 11   |
|12  DB5   o---- Arduino 10   |
|13  DB6   o---- Arduino 9    |
|14  DB7   o---- Arduino 8    |
+-----------------------------+
Certifique-se de conectar os pinos do display LCD aos pinos digitais correspondentes do Arduino conforme listado acima.
*/
#include <LiquidCrystal.h>



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

void setup() {
    lcd.begin(16, 2); // Set up the LCD's number of columns and rows
    lcd.print("Hello, Arduino!");
}

void loop() {
    // You can add code here to update the display
}