//Incluindo a Biblioteca
#include <LiquidCrystal.h>

/*
Título:  PLANTA DIDÁTICA DE TEMPERATURA
Autor:  Renato Menezes Portugal
*/

/* 00. ESTRUTURA FÍSICA
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
Azul     - FanPWM  - A1   - Arduino Envia PWM ao Ventilador 
Amarelo  - FanTach - A2   - Arduino Recebe pulsos do Ventilador
Vermelho - FanPos  - --   - Recebe 12v do MOC
Preto    - FanNeg  - --   - Ligado ao Terra


---LCD
D13 - 
D12 - 
D11 - 
D10 - 
D09 - 
D08 - 

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

REGRAS DE FUNCIONAMENTO
1. Temos um sério problema de atraso de leitura entre o aquecimento e o valor do LM35.
Para resolver limitaremos o acionamento da resistência por 3 segundos, e só ligará novamente com a autorização da leitura do termômetro.

2.Antes de iniciar as operações deverá passar por uma rotina de testes.
*/

/* 01. LEITURA DOS SENSORES E BOTOES */
/* TERMOMETRO 1 - LAMP*/
const int T1 = A4;
int T1_leitura;
int T1_temp;
int T1_temp_anterior;
int T1_temp_erro = 0;

/* TERMOMETRO 2 - RESISTENCIA*/
const int T2 = A5;
int T2_leitura;
int T2_temp;
int T2_temp_anterior;
int T2_temp_erro;

//LCD
int RS = 13;
int E = 12;
int DB4 = 11;
int DB5 = 10;
int DB6 = 9;
int DB7 = 8;
LiquidCrystal lcd(RS, E, DB4, DB5, DB6, DB7);

/* BOTOES */
int B02_D3_AUTO = 3;
int B02_D3_AUTO_Valor = 0;
int B02_D3_AUTO_Status = 0;

int B03_D5_RES = 5;
int B03_D5_RES_Status = 0;
int B03_D5_RES_Ciclo_Descida = 0;

int B05_D2_VENT_MAX = 2;
int B05_D2_VENT_MAX_Valor = 0;
int B05_D2_VENT_MAX_Status = 0;

int B06_A3_VENT = A3;
int B06_A3_VENT_Status = 0;
int B06_A3_VENT_Ciclo_Subida = 0;

int LedVentMax = 1;

/* FALANTE */
int pino_falante = A0;

/* VENTILADOR */
float FanPWM = A1;
int FanTach = A2;
//Velocidade de 0 a 255
int FanSpeed_Valor = 0;
int FanSpeed_Manual = 0;
int FanSpeed_Status = 0;
//int Pulso = 2;
int FanRPM = 0;
double FanFrequency;

unsigned long SensorPulsTijd;
int FanValor = 0;

int B04_D4_LAMP = 4;
int B04_D4_LAMP_Status = 0;
int B04_D4_LAMP_Ciclo_Descida = 0;

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

void setup() {

/* BOTOES */
pinMode(FanTach, INPUT);
digitalWrite(FanTach,HIGH);
pinMode(LedVentMax, OUTPUT);

pinMode(B02_D3_AUTO, INPUT);
pinMode(B03_D5_RES, OUTPUT);
digitalWrite(B03_D5_RES, LOW);
pinMode(B05_D2_VENT_MAX, INPUT);
pinMode(B04_D4_LAMP, OUTPUT);
digitalWrite(B04_D4_LAMP, LOW);
pinMode(B06_A3_VENT, OUTPUT);
digitalWrite(B06_A3_VENT, LOW);

lcd.begin(16, 2);
lcd.setCursor(0, 1);
lcd.print(millis()/1000);

//ESCREVE AUTOMÁTICO DESLIGADO
lcd.setCursor(10, 0);
lcd.print("AUTO 0");

//SONORIZACAO INICIAL
  // iterate over the notes of the melody:
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

//Inicia com a velocidade baixa
analogWrite(FanPWM, FanSpeed_Valor);

	//LEITURA T1
    T1_leitura = analogRead(T1);
    T1_temp_anterior = (float(T1_leitura)*5/(1023))/0.01;
	//LEITURA T2
    T2_leitura = analogRead(T2);
    T2_temp_anterior = (float(T2_leitura)*5/(1023))/0.01;
}

void loop() {
//TEMPORIZADOR
  TempoTotal = millis();
  TempoCiclo = 0;
  TempoCiclo = millis();  

//CICLO 500 milisegundos
if ((TempoTotal % 500) == 1){
	SensorPulsTijd = pulseIn(FanTach, LOW);
	FanFrequency = 1000000/SensorPulsTijd;
	FanRPM = 1000*FanFrequency/60;  

	if (FanRPM == 0){
	  lcd.setCursor(0, 0);
	  lcd.print("RPM: 0   ");
	}  

	//Muda velocidade só quando há mudança do botão B05 ou no modo AUTOMATICO
	if (FanSpeed_Valor > FanSpeed_Manual){
		if(FanSpeed_Valor != FanSpeed_Status){
		FanSpeed_Status = FanSpeed_Valor;
		analogWrite(FanPWM, FanSpeed_Valor);
		}
	}else{
		if(FanSpeed_Manual != FanSpeed_Status){
		FanSpeed_Status = FanSpeed_Manual;
		analogWrite(FanPWM, FanSpeed_Manual);
		}
	}
	
	if ((T1_temp_erro == 0) && (T2_temp_erro == 0)){
		B02_D3_AUTO_Valor = digitalRead(B02_D3_AUTO);
	}else{
		B02_D3_AUTO_Valor = 0;
		apito();
	}

}

//CICLO 1 SEGUNDO - INICIO
  if ((TempoTotal % 1000) == 1){
	
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
    T2_leitura = analogRead(T2);
    T2_temp = (float(T2_leitura)*5/(1023))/0.01;
	
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
    lcd.print("T1: ");
    lcd.print(T1_temp);
    lcd.print(" ");
    lcd.print("T2: ");
    lcd.print(T2_temp);


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
	if ((FanRPM > 2700) && (FanRPM < 3200)){
	digitalWrite(LedVentMax,HIGH);
	}else{
	digitalWrite(LedVentMax,LOW); 
	}

//CICLO AUTOMATICO - INICIO
if(B02_D3_AUTO_Status){

//T1 - INICIO	
  //AO CHEGAR NA TEMPERATURA DE 31 GRAUS A LAMPADA DESLIGA
    if (T1_temp > 30){
      if(B04_D4_LAMP_Status){
        digitalWrite(B04_D4_LAMP,LOW);
		B04_D4_LAMP_Status = 0;
		B04_D4_LAMP_Ciclo_Descida = 1;
      }
    }
  
	//AO CHEGAR NA TEMPERATURA DE 28 GRAUS A LAMPADA LIGA
      if (T1_temp < 29){
        digitalWrite(B04_D4_LAMP,HIGH);
        B04_D4_LAMP_Status = 1;
		B04_D4_LAMP_Ciclo_Descida = 0;
      }
//T1 - FIM	

//T2 - INICIO	
	//AO CHEGAR NA TEMPERATURA DE 40 GRAUS A RESISTENCIA DESLIGA
	//35 CHEGOU A 52
	//31 CHEGOU A 48
	//30 CHEGOU A 48

    if (T2_temp > 30){
		if(B03_D5_RES_Status){
			digitalWrite(B03_D5_RES,LOW);
			B03_D5_RES_Status = 0;
		}
	}
	
	if (T2_temp > 35){
	  //LIGA O VENTILADOR NA VELOCIDADE MAXIMA
	  digitalWrite(B06_A3_VENT, HIGH);
	  B06_A3_VENT_Status = 1;
	  FanSpeed_Valor = 255;
	  B03_D5_RES_Ciclo_Descida = 1;
	}
	
	if(B03_D5_RES_Ciclo_Descida){
		if (T2_temp < 33){
			FanSpeed_Valor = 0;
			if(B05_D2_VENT_MAX_Valor){
				FanSpeed_Valor = 255;
			}
		}

		if (T2_temp < 32){
			//DESLIGA O VENTILADOR
			digitalWrite(B06_A3_VENT, LOW);
			B06_A3_VENT_Status = 0;
		}
	}
	
	if (T2_temp < 30){
		if (B03_D5_RES_Status == 0){
			digitalWrite(B03_D5_RES,HIGH);
			B03_D5_RES_Status = 1;
			B03_D5_RES_Ciclo_Descida = 0;
		}
	}

//T2 - FIM

//ALARME
if(T1_temp > 40){T1_temp_erro = 1;}
if(T2_temp > 50){
	T2_temp_erro = 1;
	digitalWrite(B06_A3_VENT, HIGH);
	B06_A3_VENT_Status = 1;
	FanSpeed_Valor = 255;
	}
}
//CICLO AUTOMATICO - FIM

//VER OUTRA FORMA DE RESOLVER ISSO	
if((T1_temp < 25)&&(T2_temp < 25)){
	T1_temp_erro = 0;
	T2_temp_erro = 0;
	}
	
	//ALARME DO VENTILADOR SE ESTIVER LIGADO
	if(B06_A3_VENT_Status){
		//apito2();
		if (FanSpeed_Valor == 255){
			if((FanRPM > 999) && (FanRPM < 2500)){
				apito2();
			}
			if(FanRPM < 1000){
				apito3();
			}
		}
		if (FanSpeed_Valor == 0){
			if(FanRPM < 800){
				apito();
			}
		}
	}	
}
//CICLO 1 SEGUNDO - FIM
  
//CICLO 2 SEGUNDOS - INICIO
  if ((TempoTotal % 2000) == 1){
    
//B05 - INICIO
    
    B05_D2_VENT_MAX_Valor = digitalRead(B05_D2_VENT_MAX);
    
    //SE LIGADO, EXECUTA
	//if(B05_D2_VENT_MAX_Valor){
		//
		
	//}else{
		
	//}
	
    if((B05_D2_VENT_MAX_Valor)&&(FanRPM != 0)){
	  if((FanRPM > 999) && (FanRPM < 2500)){
		apito2();
	  }
	  if(FanRPM < 1000){
		apito3();
	  }
    }else{
    if((FanRPM > 0)&&(FanRPM < 800)){
		apito();
      }
    }
    
    //MUDANÇA DE VALOR
	if(B02_D3_AUTO_Valor == 0){
		if (B05_D2_VENT_MAX_Valor != B05_D2_VENT_MAX_Status){
			B05_D2_VENT_MAX_Status = B05_D2_VENT_MAX_Valor;
		  if(B05_D2_VENT_MAX_Status){
		  FanSpeed_Valor = 255;
		  FanSpeed_Manual = 255;
		  }else{
		  FanSpeed_Valor = 0;
		  FanSpeed_Manual = 0;
		  }
		}
	}
//B05 - FIM

//B02 - INICIO
//Se der erro não ler mais o botão, forçar para 0


    
    //SE LIGADO, EXECUTA
    if(B02_D3_AUTO_Valor){
    //apito();
    }
    
    //MUDANÇA DE VALOR
    if (B02_D3_AUTO_Valor != B02_D3_AUTO_Status){
      B02_D3_AUTO_Status = B02_D3_AUTO_Valor;
	  //Como entra uma vez só aqui, equivale ao SETUP.
      if(B02_D3_AUTO_Status){
		lcd.setCursor(10, 0);
		lcd.print("AUTO 1");
      }else{
		lcd.setCursor(10, 0);
		lcd.print("AUTO 0");
		
		//DESLIGA RESISTENCIA, LAMPADA E VENTILADOR
		digitalWrite(B04_D4_LAMP,LOW);
		B04_D4_LAMP_Status = 0;
		B04_D4_LAMP_Ciclo_Descida = 1;
		
//		digitalWrite(B06_A3_VENT, LOW);
//		B06_A3_VENT_Status = 0;
//		B06_A3_VENT_Ciclo_Subida = 0;

		digitalWrite(B03_D5_RES, LOW);
		B03_D5_RES_Status = 0;
		B03_D5_RES_Ciclo_Descida = 0;
      }
    }
//B02 - FIM
}
//CICLO 2 SEGUNDOS - FIM

}//fim do loop()
//FIM DO PROGRAMA

// Apito
int apito(){
    tone(pino_falante, NOTE_B7,20);
    delay(100);
}
int apito2(){
    tone(pino_falante, NOTE_B7,20);
    delay(100);
    noTone(pino_falante);
    tone(pino_falante, NOTE_B6,20);
    delay(100);
}
int apito3(){
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
