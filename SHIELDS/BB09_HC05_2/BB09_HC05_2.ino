//Programa : Modulo bluetooth HC-06 - Configuracao
//Autor : Adilson Thomsen
 
//Carrega a biblioteca SoftwareSerial
#include <SoftwareSerial.h>
    
//Define os pinos para a serial  (RX, TX)
SoftwareSerial MinhaSerial(6,7);
String command = "";

const int portaLed = 13;
const int portaBT = 10;
const int EN = 04;

    
void setup()
{ 
  //Inicia a serial 
  Serial.begin(9600); 
  Serial.println("Digite os comandos AT :"); 
  //Inicia a serial configurada nas portas 6 e 7
  MinhaSerial.begin(9600); 
  
  pinMode(portaLed, OUTPUT);
  pinMode(portaBT, OUTPUT);
  pinMode(EN, OUTPUT);
} 
    
void loop() 
{ 
  
  if(Serial.available())
    {
      int c = (Serial.read());
        
      if (c == 'a')
      {
        digitalWrite(portaLed, HIGH);
        Serial.println("Ok, led Ligado!");
      }
      else if (c =='b'){
        digitalWrite(portaLed, LOW);      
        Serial.println("Ok, led DesLigado!");
      }
      else if (c == 'c'){
        digitalWrite(portaBT, HIGH);      
        Serial.println("Porta Bluetooth Ligada!");
      }
      else if (c == 'd'){
        digitalWrite(portaBT, LOW);
        Serial.println("Porta Bluetooth Desligada!");      
      }
      
      else if (c == 'e'){
        digitalWrite(EN, HIGH);
        Serial.println("Porta Enable Habilitada!");      
      }
      
      else if (c == 'f'){
        digitalWrite(EN, LOW);
        Serial.println("Porta Enable Desabilitada!"); 
      }
        
        MinhaSerial.write(c);
        if (MinhaSerial.available())
        { 
           while(MinhaSerial.available())
           {
             command += (char)MinhaSerial.read(); 
           } 
         Serial.println(command); 
         command = "";
        }
      
    }
}
