// number of analog samples to take per reading, per channel
#define NUM_SAMPLES 10

// Valor do Resistor de Carga (Em ohms)
#define rRef_1    1039000
// Valor do Resistor PullDown (Em ohms)
#define rRef_2    99000

// Fator Corretor
#define fatCorretor 1.157

// Insira o Valor medido na entrada do Arduino
#define V_REF    4.4

int sum = {0};                // sums of samples taken
unsigned char sample_count = 0;  // current sample number
float voltage = {0.0};        // calculated voltages
char l_cnt = 0;                  // used in 'for' loops

void setup()
{
  Serial.begin(9600);
}

void loop()
{
/*
 char leitura = Serial.read();
 if (leitura == 'r')
 { 
*/
  // take a number of analog samples and add them up
    while (sample_count < NUM_SAMPLES) {
        // sample channel A0
        sum += analogRead(5);
        sample_count++;
        delay(20);
    }
    
    // calculate the voltage for each channel
        voltage = ((float)sum / (float)NUM_SAMPLES * V_REF) / 1024.0;

    //IMPRIME NA TELA
    Serial.print(voltage * (rRef_1/rRef_2) * fatCorretor);   
    Serial.println(" Volt(s)");   
    
    // reset count and sums
    sample_count = 0;
    sum = 0;
 //}
 delay(200);
}
