/*--------------------------------------------------------------
  Program:      voltmeter_LCD

  Description:  4 channel DC voltmeter with voltages displayed
                on LCD to 1 decimal place
  
  Hardware:     Arduino Uno with voltage dividers on A2 to A5.
                2 x 16 LCD connected to standard pins used in
                Arduino example sketches from IDE.
                
  Software:     Developed using Arduino 1.0.5 software
                Should be compatible with Arduino 1.0 +

  Date:         27 May 2013
 
  Author:       W.A. Smith, http://startingelectronics.org
--------------------------------------------------------------*/
#include <LiquidCrystal.h>

// number of analog samples to take per reading, per channel
#define NUM_SAMPLES 10
// voltage divider calibration values
#define DIV_1    11.1346
#define DIV_2    11.1969
#define DIV_3    11.0718
#define DIV_4    11.0718
// ADC reference voltage / calibration value
#define V_REF    4.991

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
int sum[4] = {0};                // sums of samples taken
unsigned char sample_count = 0;  // current sample number
float voltage[4] = {0.0};        // calculated voltages
char l_cnt = 0;                  // used in 'for' loops

void setup()
{
    lcd.begin(16, 2);
}

void loop()
{
    // take a number of analog samples and add them up
    while (sample_count < NUM_SAMPLES) {
        // sample each channel A2 to A5
        for (l_cnt = 0; l_cnt < 4; l_cnt++) {
            sum[l_cnt] += analogRead(A2 + l_cnt);
        }
        sample_count++;
        delay(10);
    }
    // calculate the voltage for each channel
    for (l_cnt = 0; l_cnt < 4; l_cnt++) {
        voltage[l_cnt] = ((float)sum[l_cnt] / (float)NUM_SAMPLES * V_REF) / 1024.0;
    }
    // display voltages on LCD
    // each voltage is multiplied by the resistor network
    // division factor to calculate the actual voltage
    // voltage 1 - A (pin A2)
    lcd.setCursor(0, 0);
    lcd.print("A ");
    lcd.print(voltage[0] * DIV_1, 1);
    lcd.print("V ");
    // voltage 2 - B (pin A3)
    lcd.setCursor(8, 0);
    lcd.print("B ");
    lcd.print(voltage[1] * DIV_2, 1);
    lcd.print("V ");
    // voltge 3 - C (pin A4)
    lcd.setCursor(0, 1);
    lcd.print("C ");
    lcd.print(voltage[2] * DIV_3, 1);
    lcd.print("V ");
    // voltage 4 - D (pin A5)
    lcd.setCursor(8, 1);
    lcd.print("D ");
    lcd.print(voltage[3] * DIV_4, 1);
    lcd.print("V ");
    // reset count and sums
    sample_count = 0;
    for (l_cnt = 0; l_cnt < 4; l_cnt++) {
        sum[l_cnt] = 0;
    }
}
