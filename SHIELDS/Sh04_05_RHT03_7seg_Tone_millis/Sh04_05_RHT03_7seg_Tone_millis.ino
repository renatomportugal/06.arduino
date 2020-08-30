/* - NOVA TECNICA MULTITAREFA
 O Arduino nao tem um gerenciamento multitarefas.
 Utilizaremos uma tecnica de entrega de tarefas.
*/

// 1. INCLUDES
#include "stdio.h"
#include "DHT22.h" // Biblioteca do sensor

// 2. PINOS
// 2.1. SHIELD 04
// 2.1.1. DISPLAY 7 SEG
boolean pino_SRCLK = 13;
boolean pino_SER = 12;
boolean pino_RCLK = 11;
boolean pino_SRCLR_inv = 10;
boolean pino_OE_inv = 9;

// 2.2. SHIELD 05
// 2.2.1. RHT03
int pino_RHT03 = A1;
int pino_Sensor_Saida = A0;
int pino_SN54ALS151_A = A4;
int pino_SN54ALS151_B = A3;
int pino_SN54ALS151_C = A2;

// 2.2.2 FALANTE
int pino_falante = A5;

// 3. DEFINICOES
// 3.1 NOTAS
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


// 4. DECLARACAO DE VARIAVEIS
// 4.1. RHT03
float hum,temp,tempDec,tempHum,tempCent;
int digito_1,digito_2,digito_3,digito_4,digito_5,digito_6,digito_7;
int dadoInt1,dadoInt2,dadoInt3,dadoInt4,dadoInt5,dadoInt6,dadoInt7;
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
// 4.3. SENSOR
int sensor1,sensor2,sensor3,sensor4,sensor5,sensor6,sensor7,sensor8;
// 4.4. TEMPORIZADOR
long TempoTotal, TempoCiclo;

// 5.
DHT22 RHT03(pino_RHT03);//define nome da variável do sensor

void setup(){
// 1. DISPLAY 7 SEG
  pinMode(pino_SRCLK, OUTPUT);
  pinMode(pino_SER, OUTPUT);
  pinMode(pino_RCLK, OUTPUT);
  pinMode(pino_SRCLR_inv, OUTPUT);
  pinMode(pino_OE_inv, OUTPUT);
  digitalWrite(pino_SRCLK, LOW);
  digitalWrite(pino_SER, LOW);
  digitalWrite(pino_SRCLK, LOW);
  digitalWrite(pino_SRCLR_inv, LOW);
  digitalWrite(pino_OE_inv, HIGH);

// 2. SENSORES
  pinMode(pino_Sensor_Saida, INPUT);
  pinMode(pino_SN54ALS151_A, OUTPUT);
  pinMode(pino_SN54ALS151_B, OUTPUT);
  pinMode(pino_SN54ALS151_C, OUTPUT);
  
// 3. PREPARA O SHIFT REGISTER
 digitalWrite(pino_SRCLR_inv, LOW);
 digitalWrite(pino_SRCLR_inv, HIGH);
 digitalWrite(pino_OE_inv, HIGH);

// 4. SONORIZACAO INICIAL
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


}

void loop(){
  
  //TEMPORIZADOR
  TempoTotal = millis();
  TempoCiclo = 0;
  TempoCiclo = millis();
  
  //RHT03 - APRESENTACAO DOS RESULTADOS
    RHT03.readData();
    temp=RHT03.getTemperatureC();
    hum=RHT03.getHumidity();
    digito_1 = int(temp)/10;
    digito_2 = int(temp) - (digito_1 * 10);
    tempDec = (temp - int(temp))*10;
    digito_3 = (int)tempDec;
    tempCent = ((temp - int(temp))*100) - (tempDec*10);
    digito_4 = int(tempCent);
    digito_5 = int(hum)/10;
    digito_6 = int(hum) - (digito_5 * 10);
    tempHum = (hum - int(hum))*10;
    digito_7 = (int)tempHum;

    dadoInt1 = dadoIntSemPonto(digito_1);
    dadoInt2 = dadoIntComPonto(digito_2);
    dadoInt3 = dadoIntSemPonto(digito_3);
    dadoInt4 = dadoIntSemPonto(digito_4);
    dadoInt5 = dadoIntSemPonto(digito_5);
    dadoInt6 = dadoIntComPonto(digito_6);
    dadoInt7 = dadoIntSemPonto(digito_7);
    
    ShiftRegEnviaInt(pino_SER,dadoInt7);
    ShiftRegEnviaInt(pino_SER,dadoInt6);
    ShiftRegEnviaInt(pino_SER,dadoInt5);
    ShiftRegEnviaInt(pino_SER,dadoInt4);
    ShiftRegEnviaInt(pino_SER,dadoInt3);
    ShiftRegEnviaInt(pino_SER,dadoInt2);
    ShiftRegEnviaInt(pino_SER,dadoInt1);
    
    //MOSTRA O RESULTADO
    digitalWrite(pino_OE_inv, LOW);

    //UMIDADE CRITICA
    if (hum <= 40){
      temp_delay = 1000;
      delay(temp_delay);
      apito();
      Pisca();
      apito();
      Pisca();
      apito();
      Pisca();
    }
    
    //UMIDADE ABAIXO DO IDEAL 
    if ((hum > 40) && (hum <= 50)){
      temp_delay = 1000;
      delay(temp_delay);
      apito();
      Pisca();
      apito();
      Pisca();
    }

    //UMIDADE NORMAL
    if (hum > 50){
      temp_delay = 2000;
      delay(temp_delay);
    }
   
     //RESETA O SERIAL E INIBE A SAÍDA
     digitalWrite(pino_SRCLR_inv, LOW);
     digitalWrite(pino_SRCLR_inv, HIGH);
     digitalWrite(pino_OE_inv, HIGH);
//___________________________________________________________________
    //SENSORES
    //OS SENSORES SÃO ATIVOS COM NÍVEL BAIXO

    // LeituraSensor(sensorNum, sensor_SN54ALS151_C, sensor_SN54ALS151_B, sensor_SN54ALS151_A);
    LeituraSensor(1, 0, 0, 0);
    LeituraSensor(2, 0, 0, 1);
    LeituraSensor(3, 0, 1, 0);
    LeituraSensor(4, 0, 1, 1);
    LeituraSensor(5, 1, 0, 0);
    LeituraSensor(6, 1, 0, 1);
    LeituraSensor(7, 1, 1, 0);
    LeituraSensor(8, 1, 1, 1);
    
     //RESETA O SERIAL E INIBE A SAÍDA
     digitalWrite(pino_SRCLR_inv, LOW);
     digitalWrite(pino_SRCLR_inv, HIGH);
     digitalWrite(pino_OE_inv, HIGH);

}
//FIM DO PROGRAMA


/*--------------------------FUNCOES------------------------------------*/
// 1. FUNCAO QUE TRANSFORMA VALOR EM CODIGO PARA DISPLAY 7 SEG
int dadoIntSemPonto(int dadoCode){
  switch(dadoCode){
    case 0:
    return 63;
    break;
    case 1:
    return 6;
    break;
    case 2:
    return 91;
    break;
    case 3:
    return 79;
    break;
    case 4:
    return 102;
    break;
    case 5:
    return 109;
    break;
    case 6:
    return 124;
    break;
    case 7:
    return 7;
    break;
    case 8:
    return 127;
    break;
    case 9:
    return 103;
    break;
  }
}

// 2. FUNCAO QUE TRANSFORMA VALOR EM CODIGO PARA DISPLAY 7 SEG
int dadoIntComPonto(int dadoCode){
  switch(dadoCode){
    case 0:
    return 191;
    break;
    case 1:
    return 134;
    break;
    case 2:
    return 219;
    break;
    case 3:
    return 207;
    break;
    case 4:
    return 230;
    break;
    case 5:
    return 237;
    break;
    case 6:
    return 252;
    break;
    case 7:
    return 135;
    break;
    case 8:
    return 255;
    break;
    case 9:
    return 231;
    break;
  }
}

// 3. FUNCAO QUE ENVIA DADOS CHAR
  int ShiftRegEnviaChar(int PortaDados, char Dados[8]){
    for(int i=0;i<8;i++){
       if (Dados[i] == 1){digitalWrite(PortaDados, 1);}else{digitalWrite(PortaDados, LOW);}
       digitalWrite(pino_SRCLK, HIGH);
       digitalWrite(pino_RCLK, LOW);
       digitalWrite(pino_SRCLK, LOW);
       digitalWrite(pino_RCLK, HIGH);
    }  
    
  }

// 4. FUNCAO QUE ENVIA DADOS INT
  int ShiftRegEnviaInt(int PortaDados, int dadoInt){

    //CONVERTE PARA CHAR    
    char Dados[8];
    //Preenche o char Dados[8]  
    for(int i=8;i>0;--i){
    int j = i - 1;
    Dados[j] = dadoInt%2;
    dadoInt = dadoInt / 2;
    }
    
    for(int i=0;i<8;i++){
       if (Dados[i] == 1){digitalWrite(PortaDados, HIGH);}else{digitalWrite(PortaDados, LOW);}
        digitalWrite(pino_SRCLK, HIGH);
        digitalWrite(pino_RCLK, LOW);
        digitalWrite(pino_SRCLK, LOW);
        digitalWrite(pino_RCLK, HIGH);
        //delay(3);
    }
  }

// 5. FUNCAO QUE FAZ PISCAR
int Pisca(){
      digitalWrite(pino_OE_inv, HIGH);
      delay(50);
      digitalWrite(pino_OE_inv, LOW);
      delay(300);
}

// 6. Apito
int apito(){
    tone(pino_falante, NOTE_B7,20);
    delay(100);
    noTone(pino_falante);
}

//7. LEITURA DO SENSOR

int LeituraSensor(int sensorNum, int sensor_SN54ALS151_C, int sensor_SN54ALS151_B, int sensor_SN54ALS151_A){
    digitalWrite(pino_SN54ALS151_C, sensor_SN54ALS151_C);
    digitalWrite(pino_SN54ALS151_B, sensor_SN54ALS151_B);
    digitalWrite(pino_SN54ALS151_A, sensor_SN54ALS151_A);
    //PEGA O VALOR DO SENSOR
    sensor2 = digitalRead(pino_Sensor_Saida);

    if (sensor2){
      //Mostara 0001 S02
      dadoInt1 = dadoIntSemPonto(0);
      dadoInt2 = dadoIntSemPonto(0);
      dadoInt3 = dadoIntSemPonto(0);
      dadoInt4 = dadoIntSemPonto(0);
      dadoInt5 = 0;
      dadoInt6 = dadoIntSemPonto(0);
      dadoInt7 = dadoIntSemPonto(sensorNum);
      
      ShiftRegEnviaInt(pino_SER,dadoInt7);
      ShiftRegEnviaInt(pino_SER,dadoInt6);
      ShiftRegEnviaInt(pino_SER,dadoInt5);
      ShiftRegEnviaInt(pino_SER,dadoInt4);
      ShiftRegEnviaInt(pino_SER,dadoInt3);
      ShiftRegEnviaInt(pino_SER,dadoInt2);
      ShiftRegEnviaInt(pino_SER,dadoInt1);
      
    //MOSTRA O RESULTADO
    digitalWrite(pino_OE_inv, LOW);
    
    }else{
      //Mostara 0000 S02
      dadoInt1 = dadoIntSemPonto(0);
      dadoInt2 = dadoIntSemPonto(0);
      dadoInt3 = dadoIntSemPonto(0);
      dadoInt4 = dadoIntSemPonto(1);
      dadoInt5 = 0;
      dadoInt6 = dadoIntSemPonto(0);
      dadoInt7 = dadoIntSemPonto(sensorNum);
      
      ShiftRegEnviaInt(pino_SER,dadoInt7);
      ShiftRegEnviaInt(pino_SER,dadoInt6);
      ShiftRegEnviaInt(pino_SER,dadoInt5);
      ShiftRegEnviaInt(pino_SER,dadoInt4);
      ShiftRegEnviaInt(pino_SER,dadoInt3);
      ShiftRegEnviaInt(pino_SER,dadoInt2);
      ShiftRegEnviaInt(pino_SER,dadoInt1);
      
    //MOSTRA O RESULTADO
    digitalWrite(pino_OE_inv, LOW);      
    }
    delay(1000);
    //INIBE A SAIDA
    digitalWrite(pino_OE_inv, HIGH); 
}
