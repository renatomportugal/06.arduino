/**************************************************************/
/* POT controlled software PWM                                */
/*                                                            */
/* Code written by William Hart, 2011                         */
/* http://www.williamhart.info                                */
/*                                                            */
/* This is a very simple circuit which uses a potentiometer   */
/* to set an analog input and then uses this input to drive a */
/* PWM signal using a standard (non-PWM) port on the Arduino. */
/**************************************************************/
/*
//Serial.println(microsecondsToClockCycles(1)); // gives a result of 16 clock cycles per microsecond

// define pins
#define ADJ_PIN A0 // Adjustment pin is analog 0

//PINOS PARA A BASE DOS TRANSISTORES
//Transistor 1
#define PWM_T1 0
//Transistor 2
#define PWM_T2 1
//Transistor 3
#define PWM_T3 2
//Transistor 4
#define PWM_T4 3

// setup PWM values
#define PWM_FREQ 300 // PWM Hz, must be greater than 60Hz to avoid delayMicroseconds issues
#define MAX_V 5.00 // the maximum voltage we can output

long cycle_length;
float v_out;
float duty_cycle;
int on_time;
int off_time;

void setup()
{
  // start up serial for debugging
  Serial.begin(9600);

  // set pin states
  pinMode(ADJ_PIN, INPUT);
  pinMode(PWM_T1, OUTPUT);
  pinMode(PWM_T2, OUTPUT);
  pinMode(PWM_T3, OUTPUT);
  pinMode(PWM_T4, OUTPUT);
  digitalWrite(PWM_T1, HIGH);
  digitalWrite(PWM_T2, HIGH);
  digitalWrite(PWM_T3, HIGH);
  digitalWrite(PWM_T4, HIGH);

  // calculate the cycle length
  cycle_length = 1000000/PWM_FREQ; // the length of a single cycle of the PWM signal
}

void loop()
{
  // read in the potentiometer value
  int val = analogRead(ADJ_PIN);

  // map the pot value to the PWM value - 0-5V, to two decimal places
  v_out = map(val, 0,1024, 0, 500);
  duty_cycle = (v_out/100) / MAX_V; // work out what percentage of the PWM cycle we should set high
  on_time = duty_cycle * cycle_length;
  off_time = cycle_length - on_time;

  // now set high, then delay for the duty_cycle percentage * cycle_length
  if(on_time > 0)
  {
    //Sentido Horário
  digitalWrite(PWM_T1, LOW);
  digitalWrite(PWM_T2, LOW);
  
    delayMicroseconds(on_time);
  }

  digitalWrite(PWM_T1, HIGH);
  digitalWrite(PWM_T2, HIGH);

  delayMicroseconds(off_time);
}
*/
float v_out;
float duty_cycle;

#define MAX_V 5.00

int on_time;
int off_time;

//PINOS PARA A BASE DOS TRANSISTORES
//Transistor 1
int T1 = 0;
//Transistor 2
int T2 = 1;
//Transistor 3
int T3 = 2;
//Transistor 4
int T4 = 3;

#define PWM_FREQ 300
long cycle_length;

//POTENCIOMETRO
#define Pot_A0 A0

//PINOS PARA O DISPLAY DE 7 SEGMENTOS
int DISPLAY_A = 6;
int DISPLAY_B = 7;

void setup() {     
  //INICIA AS I/O DIGITAIS COMO SAÍDAS 
  pinMode(T1, OUTPUT);     
  pinMode(T2, OUTPUT);
  pinMode(T3, OUTPUT);
  pinMode(T4, OUTPUT);
             
  pinMode(DISPLAY_A, OUTPUT);
  pinMode(DISPLAY_B, OUTPUT);  
  // calculate the cycle length
  cycle_length = 1000000/PWM_FREQ;
  Serial.begin(9600);
  
}
void loop() {

  
  digitalWrite(DISPLAY_B, LOW);
  int sensorValue = analogRead(Pot_A0);
  float voltage = sensorValue * (5.0 / 1023.0);


 v_out = map(sensorValue, 0,1024, 0, 500);
  duty_cycle = (v_out/100) / MAX_V;
  
  int duty = map(sensorValue,0,1022,0,100);
  int duty_inv = 100 - duty;

on_time = duty_cycle * cycle_length;
  off_time = cycle_length - on_time;

  digitalWrite(DISPLAY_A, LOW);

//Sentido Horário
  digitalWrite(T1, LOW);
  digitalWrite(T2, LOW);
  digitalWrite(T3, HIGH);
  digitalWrite(T4, HIGH);
  
  delayMicroseconds(on_time);

  //delay(duty);
  digitalWrite(DISPLAY_A, HIGH);

//Sentido Horário
  digitalWrite(T1, HIGH);
  digitalWrite(T2, HIGH);
  digitalWrite(T3, HIGH);
  digitalWrite(T4, HIGH);
  
  delayMicroseconds(off_time);
  //delay(duty_inv * 10);
  
  //Serial.println(microsecondsToClockCycles(1));
  Serial.println(duty);
}
