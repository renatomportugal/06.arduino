// ERROS
// ESTÁ TRAVANDO EM ALGUM MOMENTO, COM AS CARGAS LIGADAS.
// Só pode desligar o ventilador quando a carga estiver desligada, pois fica travado durante alguns segundos.

//Incluindo a Biblioteca
#include <LiquidCrystal.h>

/*
Título:  PLANTA DIDÁTICA DE TEMPERATURA
Autor:  Renato Menezes Portugal
*/

/* 00. ESTRUTURA FÍSICA
----------------------------------------
|            Led01 [Ligado]            |
|----------  Led02 [Auto]              |
||B4|B2|B5|  Led03 [Resistência]       |
||B3|B1|B6|  Led04 [Ventilador Ligado] |
|----------  Led05 [Ventilador Máximo] |
|            Led06 [Alarme]            |
----------------------------------------

---Operação-----------------------------
Após alimentar com 110vac, +5vdc, +12vdc, liga com o Botão B1, aciona o Led01.

---Observações--------------------------
Sem uma fonte adequada, a diferença da leitura da temperatura pode chegar a 5°C.

---BOTOES
B1 - ON
     Alimenta o sistema com 5v.
B2 - AUTOMÁTICO
     Inicia o controle automático
B3 - RESISTÊNCIA
     MANUAL - Liga a resistência (110vac). Cuidado com o sobreaquecimento.
B4 - LAMPADA
     MANUAL - Liga a lâmpada (110vac).
B5 - VENTILADOR VELOCIDADE MAXIMA
     AUTO - Quando em modo automático, aciona a entrada no arduino fazendo com que a velocidade esteja 
     sempre na máxima.
B6 - VETILADOR LIGAR
     MANUAL - Aciona manualmente o ventilador (já na velocidade máxima)

---LEDS                      - Ligado na        - RESISTOR  - TIPO
ON                           - CARGA (5v)       - 330 Ohms  - 
AUTO                         - CARGA (5v)       - 220 Ohms  - ENTRADA do Arduino
RESISTENCIA                  - CARGA (110 VAC)  - 100K Ohms - 
VENTILADOR ON                - CARGA (12v)      - 800 Ohms  - 
VENTILADOR VELOCiDADE MAXIMA - CARGA (5v)       - 220 Ohms  - ENTRADA do Arduino
ALARME                       - CARGA (5v)       - 220 Ohms  - SAÍDA do Arduino

---VENTILADOR
CORES    - SIGLA   - PINO - 
Azul     - VENT_TAC - A1   - Arduino Recebe pulsos do Ventilador
Amarelo  - VENT_PWM - A2   - Arduino Envia PWM ao Ventilador 
Vermelho - FanPos  - --   - Recebe 12v do MOC
Preto    - FanNeg  - --   - Ligado ao Terra

---RESISTENCIA 110v
Arduino - I/O   - Botão
D5      - saida - B3

---LAMPADA 110v
Arduino - I/O   - Botão
D4      - saida - B4

---TERMOMETRO 1   - LAMP
Arduino - I/O
A4      - entrada

---TERMOMETRO 2 - RESISTENCIA
Arduino - I/O
A5      - entrada

---ALARME
Arduino - I/O
A0      - saida

00.1 - Ligação Física
---LCD
Arduino	LCD
D13		RS
D12		E
D11		DB4
D10		DB5
D09		DB6
D08		DB7

Ligar: 
RW no GND
V0 -> 220 Ohm -> GND
VDD -> 5v
VSS -> GND

---Alarme
A0 -> Alarme



REGRAS DE FUNCIONAMENTO
1. Temos um sério problema de atraso de leitura entre o aquecimento e o valor do LM35.
Para resolver limitaremos o acionamento da resistência por 3 segundos, e só ligará novamente com a autorização da leitura do termômetro.

2.Antes de iniciar as operações deverá passar por uma rotina de testes.
*/

/* 01. LEITURA DOS SENSORES E BOTOES */
//LCD
int RS = 13;
int E = 12;
int DB4 = 11;
int DB5 = 10;
int DB6 = 9;
int DB7 = 8;
LiquidCrystal lcd(RS, E, DB4, DB5, DB6, DB7);

/* TERMOMETRO 1 - LAMP*/
const int T1 = A4;
int T1_leitura;
int T1_temp;
int T1_temp_anterior;
int T1_temp_erro = 0;

/* TERMOMETRO 2 - RESISTENCIA*/
const int T2 = A5;
int T2_Leitura;
int T2_temp;
int T2_temp_anterior;
int T2_temp_erro;

/* BOTOES */
int B02_D3_AUTO = 3;
int B02_D3_AUTO_Leitura = 0;
int B02_D3_AUTO_Status = 0;

int B03_D5_RES = 5;
int B03_D5_RES_Status = 0;
int B03_D5_RES_Ciclo_Descida = 0;

int B05_D2_VENT_MAX = 2;
int B05_D2_VENT_MAX_Valor = 0;
int B05_D2_VENT_MAX_Status = 0;

/* FALANTE */
int pino_falante = A0;

/* VENTILADOR */
int VENT_D6 = 6;

float VENT_PWM = A2;
int VENT_TAC = A1;
//Velocidade de 0 a 255
int VENT_Speed_Valor = 0;
int VENT_Speed_Manual = 0;
int VENT_Speed_Status = 0;
//int Pulso = 2;
int FanRPM = 0;
double FanFrequency;

unsigned long SensorPulsTijd;
int FanValor = 0;

int B04_D4_LAMP = 4;
int B04_D4_LAMP_Status = 0;
int B04_D4_LAMP_Ciclo_Descida = 0;
int B04_D4_LAMP_Ciclo_Iteracao = 0;

int VENT_LedMax = 1;


// DEFINICOES
// NOTAS
#define NOTE_B0  31
#define NOTE_C1  33
#define NOTE_CS1 35
#define NOTE_D1  37
#define NOTE_DS1 39
#define NOTE_E1  41
#define NOTE_F1  44
#define NOTE_FS1 46
#define NOTE_G1  49
#define NOTE_GS1 52
#define NOTE_A1  55
#define NOTE_AS1 58
#define NOTE_B1  62
#define NOTE_C2  65
#define NOTE_CS2 69
#define NOTE_D2  73
#define NOTE_DS2 78
#define NOTE_E2  82
#define NOTE_F2  87
#define NOTE_FS2 93
#define NOTE_G2  98
#define NOTE_GS2 104
#define NOTE_A2  110
#define NOTE_AS2 117
#define NOTE_B2  123
#define NOTE_C3  131
#define NOTE_CS3 139
#define NOTE_D3  147
#define NOTE_DS3 156
#define NOTE_E3  165
#define NOTE_F3  175
#define NOTE_FS3 185
#define NOTE_G3  196
#define NOTE_GS3 208
#define NOTE_A3  220
#define NOTE_AS3 233
#define NOTE_B3  247
#define NOTE_C4  262
#define NOTE_CS4 277
#define NOTE_D4  294
#define NOTE_DS4 311
#define NOTE_E4  330
#define NOTE_F4  349
#define NOTE_FS4 370
#define NOTE_G4  392
#define NOTE_GS4 415
#define NOTE_A4  440
#define NOTE_AS4 466
#define NOTE_B4  494
#define NOTE_C5  523
#define NOTE_CS5 554
#define NOTE_D5  587
#define NOTE_DS5 622
#define NOTE_E5  659
#define NOTE_F5  698
#define NOTE_FS5 740
#define NOTE_G5  784
#define NOTE_GS5 831
#define NOTE_A5  880
#define NOTE_AS5 932
#define NOTE_B5  988
#define NOTE_C6  1047
#define NOTE_CS6 1109
#define NOTE_D6  1175
#define NOTE_DS6 1245
#define NOTE_E6  1319
#define NOTE_F6  1397
#define NOTE_FS6 1480
#define NOTE_G6  1568
#define NOTE_GS6 1661
#define NOTE_A6  1760
#define NOTE_AS6 1865
#define NOTE_B6  1976
#define NOTE_C7  2093
#define NOTE_CS7 2217
#define NOTE_D7  2349
#define NOTE_DS7 2489
#define NOTE_E7  2637
#define NOTE_F7  2794
#define NOTE_FS7 2960
#define NOTE_G7  3136
#define NOTE_GS7 3322
#define NOTE_A7  3520
#define NOTE_AS7 3729
#define NOTE_B7  3951
#define NOTE_C8  4186
#define NOTE_CS8 4435
#define NOTE_D8  4699
#define NOTE_DS8 4978

// 4.2. SONORIZACAO
int noteDuration;
int qntNotas = 5;
int melody[] = {
  NOTE_B3,NOTE_B4,NOTE_B5,NOTE_B6,NOTE_B7
};
/* DURACAO DAS NOTAS
1 - 250 ms
2 - 125 ms
4 - 62,5 ms
8 - 31,25 ms
16 - 15,625 ms
*/
int noteDurations[] = {
  1,2,4,8,16 };
int temp_delay;

long TempoTotal, TempoCiclo;

//__INI setup_______________________________
void setup() {
// LCD
lcd.begin(16, 2);

// VENTILADOR
pinMode(VENT_PWM, OUTPUT);
pinMode(VENT_TAC, INPUT);
lcd.setCursor(11, 1);
lcd.print("V");
// LedMax
pinMode(VENT_LedMax, OUTPUT);
pinMode(B05_D2_VENT_MAX, INPUT);
lcd.setCursor(14, 1);
lcd.print("M");
pinMode(VENT_D6, OUTPUT);
digitalWrite(VENT_TAC,HIGH);

//Inicia com o ventilador desligado
digitalWrite(VENT_D6, LOW);
//Inicia com a velocidade baixa
analogWrite(VENT_PWM, VENT_Speed_Valor);


// AUTO
pinMode(B02_D3_AUTO, INPUT);
lcd.setCursor(8, 1);
lcd.print("A");

// RESISTÊNCIA
pinMode(B03_D5_RES, OUTPUT);
digitalWrite(B03_D5_RES, LOW);

// LÂMPADA
pinMode(B04_D4_LAMP, OUTPUT);
digitalWrite(B04_D4_LAMP, LOW);

// ALARME
  for (int i = 0; i < qntNotas; i++) {

    // to calculate the note duration, take one second 
    // divided by the note type.
    //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
    noteDuration = 1000/noteDurations[i];
    tone(pino_falante, melody[i],noteDuration);

    // to distinguish the notes, set a minimum time between them.
    // the note's duration + 30% seems to work well:
    int pauseBetweenNotes = noteDuration * 1.30;
    delay(pauseBetweenNotes);
    // stop the tone playing:
    noTone(pino_falante);
  }
  
// 5. TEMPORIZADOR  
TempoTotal = 0;

// TERMÔMETRO 01
pinMode(T1, INPUT);

// TERMÔMETRO 02
pinMode(T2, INPUT);


     Inicio();

}
//__FIM setup_______________________________

void loop() {
	// TEMPORIZADOR
	TempoTotal = millis();
	TempoCiclo = 0;
	TempoCiclo = millis();

     //CICLO 500 milisegundos
     if ((TempoTotal % 500) == 1){

          //__________________________________________
          //__INI - VENTILADOR________________________
          SensorPulsTijd = pulseIn(VENT_TAC, LOW);
          lcd.setCursor(0, 0);
          // lcd.print(SensorPulsTijd);
          if(SensorPulsTijd < 99999){
               FanFrequency = 1000000/SensorPulsTijd;
               FanRPM = 1000*FanFrequency/60;
          }else{
               FanRPM = 0;
          }

          // Indicador de Ventilador Ligado
          if (FanRPM == 0){
               lcd.setCursor(0, 0);
               lcd.print("RPM: 0   ");
               lcd.setCursor(12, 1);
               lcd.print("0");
          }else{
               lcd.setCursor(12, 1);
               lcd.print("1");
          }

          // Mostra no LCD
          if (FanRPM < 1000){
               lcd.setCursor(0, 0);
               lcd.print("RPM: ");
               lcd.print(FanRPM);
               lcd.print(" ");			
          }

          if ((FanRPM > 999) && (FanRPM < 3200)){
               lcd.setCursor(0, 0);
               lcd.print("RPM: ");
               lcd.print(FanRPM);
          }

          //LED DE VELOCIDADE MÁXIMA DO VENTILADOR
          if ((FanRPM > 2600) && (FanRPM < 3200)){
               digitalWrite(VENT_LedMax,HIGH);
               lcd.setCursor(15, 1);
               lcd.print("1");
          }else{
               digitalWrite(VENT_LedMax,LOW);
               lcd.setCursor(15, 1);
               lcd.print("0");
          }
            
          B05_D2_VENT_MAX_Valor = digitalRead(B05_D2_VENT_MAX);

          if((B05_D2_VENT_MAX_Valor)&&(FanRPM != 0)){
               if(VENT_Speed_Valor != 255){
                    VENT_Speed_Valor = 255;
                    analogWrite(VENT_PWM, VENT_Speed_Valor);
                    // lcd.setCursor(15, 1);
                    // lcd.print("1");
               }

               

               if((FanRPM > 999) && (FanRPM < 2500)){
                    Apito2();
               }
               if(FanRPM < 1000){
                    Apito3();
               }
          }else{
               if(VENT_Speed_Valor != 0){
                    VENT_Speed_Valor = 0;
                    analogWrite(VENT_PWM, VENT_Speed_Valor);
                    // lcd.setCursor(15, 1);
                    // lcd.print("0");
               }
          }

          //__________________________________________
          //__FIM - VENTILADOR________________________

          // //Muda velocidade só quando há mudança do botão B05 ou no modo AUTOMATICO
          // if (VENT_Speed_Valor > VENT_Speed_Manual){
          //      if(VENT_Speed_Valor != VENT_Speed_Status){
          //      VENT_Speed_Status = VENT_Speed_Valor;
          //      analogWrite(VENT_PWM, VENT_Speed_Valor);
          //      }
          // }else{
          //      if(VENT_Speed_Manual != VENT_Speed_Status){
          //      VENT_Speed_Status = VENT_Speed_Manual;
          //      analogWrite(VENT_PWM, VENT_Speed_Manual);
          //      }
          // }
          
          // if ((T1_temp_erro == 0) && (T2_temp_erro == 0)){
          //      B02_D3_AUTO_Leitura = digitalRead(B02_D3_AUTO);
          // }else{
          //      B02_D3_AUTO_Leitura = 0;
          //      Apito();
          // }

     }

     //CICLO 1 SEGUNDO - INICIO
     if ((TempoTotal % 1000) == 1){

          //__________________________________________
          //__INI - TEMPERATURA_______________________
          //LEITURA T1
          T1_leitura = analogRead(T1);
          T1_temp = (float(T1_leitura)*5/(1023))/0.01;
          
          if (T1_temp > T1_temp_anterior){
               if ((T1_temp - T1_temp_anterior) > 3 ){
                    T1_temp_erro = 1;
               }else{
                    T1_temp_anterior = T1_temp;
               }
          }else{
               if ((T1_temp_anterior - T1_temp) > 3 ){
                    T1_temp_erro = 1;
               }else{
                    T1_temp_anterior = T1_temp;
               }
          }
          
          
          //LEITURA T2
          T2_Leitura = analogRead(T2);
          T2_temp = (float(T2_Leitura)*5/(1023))/0.01;
          
          if (T2_temp > T2_temp_anterior){
               if ((T2_temp - T2_temp_anterior) > 3 ){
                    T2_temp_erro = 1;
               }else{
                    T2_temp_anterior = T2_temp;
               }
          }else{
               if ((T2_temp_anterior - T2_temp) > 3 ){
                    T2_temp_erro = 1;
               }else{
                    T2_temp_anterior = T2_temp;
               }
          }
          
          //IMPRIME TEMPERATURA NO LCD
          lcd.setCursor(0, 1);
          lcd.print("T");
          lcd.setCursor(2, 1);
          lcd.print(T1_temp);
          lcd.setCursor(5, 1);
          lcd.print(T2_temp);
          //__________________________________________
          //__FIM - TEMPERATURA_______________________

          

     }

     //CICLO 2 SEGUNDOS - INICIO
     if ((TempoTotal % 2000) == 1){
          Apito();

          // Ciclo automático
          B02_D3_AUTO_Leitura = digitalRead(B02_D3_AUTO);
          if(B02_D3_AUTO_Leitura){
               lcd.setCursor(9, 1);
               lcd.print("1");

               // --INI - MODO FULL------------------------------------
               //AO CHEGAR NA TEMPERATURA DE 31 GRAUS A LAMPADA DESLIGA
               if (T1_temp > 30){
                    if(B04_D4_LAMP_Status){

                         digitalWrite(B04_D4_LAMP,LOW);
                         B04_D4_LAMP_Status = 0;
                         B04_D4_LAMP_Ciclo_Descida = 1;
                         // Iterações
                         B04_D4_LAMP_Ciclo_Iteracao = 0;
                         lcd.setCursor(9, 0);
                         lcd.print(B04_D4_LAMP_Ciclo_Iteracao);
                         lcd.print(" ");

                         LigarVentilador(255);
                    }
               }else{
                    // // Funcionando ok, alternado, liga e desliga
                    // if(B04_D4_LAMP_Ciclo_Descida == 0){
                    //      if((B04_D4_LAMP_Ciclo_Iteracao % 2) == 1){
                    //           digitalWrite(B04_D4_LAMP,HIGH);
                    //      }else{
                    //           digitalWrite(B04_D4_LAMP,LOW);
                    //      }

                    //      B04_D4_LAMP_Ciclo_Iteracao = B04_D4_LAMP_Ciclo_Iteracao + 1;
                    //      lcd.setCursor(9, 0);
                    //      lcd.print(B04_D4_LAMP_Ciclo_Iteracao);

                    //      DesligarVentilador();

                    // }else{
                    //      if(T1_temp < 30){
                    //           if ((FanRPM > 2600) && (FanRPM < 3200)){
                    //                analogWrite(VENT_PWM, 0);
                    //           }
                    //      }
                    // }

                    // Testar novo modelo para ligar a cada 4 iterações, e desligar nas outras
                    if(B04_D4_LAMP_Ciclo_Descida == 0){
                         if((B04_D4_LAMP_Ciclo_Iteracao % 4) == 1){
                              digitalWrite(B04_D4_LAMP,HIGH);
                         }else{
                              digitalWrite(B04_D4_LAMP,LOW);
                         }

                         B04_D4_LAMP_Ciclo_Iteracao = B04_D4_LAMP_Ciclo_Iteracao + 1;
                         lcd.setCursor(9, 0);
                         lcd.print(B04_D4_LAMP_Ciclo_Iteracao);

                         DesligarVentilador();


                    }else{
                         if(T1_temp < 30){
                              if ((FanRPM > 2600) && (FanRPM < 3200)){
                                   analogWrite(VENT_PWM, 0);
                              }
                         }
                    }

               }
               
               //AO CHEGAR NA TEMPERATURA DE 28 GRAUS A LAMPADA LIGA
               if (T1_temp < 29){

                    // digitalWrite(B04_D4_LAMP,HIGH);

                    B04_D4_LAMP_Status = 1;
                    B04_D4_LAMP_Ciclo_Descida = 0;
                    
                    
               }
               // --FIM - MODO FULL------------------------------------

          }else{
               lcd.setCursor(9, 1);
               lcd.print("0");
               // Desliga Luz
               digitalWrite(B04_D4_LAMP,LOW);
          }

          
     }

}
//__fim do loop()
//__FIM DO PROGRAMA________________

//_________________________________
//__Funções________________________

// Inicio
int Inicio(){
     // VENTILADOR
     // digitalWrite(VENT_D6, HIGH);
     // lcd.setCursor(11, 1);
     // lcd.print("V");


     // LM35
     // Lâmpada
     T1_leitura = analogRead(T1);
     T1_temp = (float(T1_leitura)*5/(1023))/0.01;
     lcd.setCursor(11, 0);
     lcd.print(T1_temp);

     // Resistência
     T2_Leitura = analogRead(T2);
     T2_temp = (float(T2_Leitura)*5/(1023))/0.01;
     lcd.setCursor(14, 0);
     lcd.print(T2_temp);
     
}

int LigarVentilador(int pwm){
     digitalWrite(VENT_D6, HIGH);
     analogWrite(VENT_PWM, pwm);
}

int DesligarVentilador(){
     digitalWrite(VENT_D6, LOW);
}

// Apito
int Apito(){
    tone(pino_falante, NOTE_B7,20);
    delay(100);
}
int Apito2(){
    tone(pino_falante, NOTE_B7,20);
    delay(100);
    noTone(pino_falante);
    tone(pino_falante, NOTE_B6,20);
    delay(100);
}
int Apito3(){
    tone(pino_falante, NOTE_B7,20);
    delay(100);
    noTone(pino_falante);
    tone(pino_falante, NOTE_B6,20);
    delay(100);
    noTone(pino_falante);    
    tone(pino_falante, NOTE_B5,20);
    delay(100);
    noTone(pino_falante);        
}
//_________________________________
