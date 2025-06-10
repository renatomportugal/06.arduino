#include <SoftwareSerial.h>
    
//Define os pinos para a serial  (RX, TX)
SoftwareSerial MinhaSerial(6,7);
String command = "";

int Led_13 = 13;

void setup()
{ 
  //Inicia a serial 
  Serial.begin(9600); 
  Serial.println("Digite algum comando abaixo pelo celular:");
  Serial.println("a - Acende o Led");
  Serial.println("b - Apaga o Led");
  
  //Inicia a serial configurada nas portas 6 e 7
  MinhaSerial.begin(9600); 
  
  pinMode(Led_13, OUTPUT);
} 
    
void loop() 
{ 
  
  if(Serial.available())
    {
      int c = (Serial.read());
      MinhaSerial.write(c);
    }

  
  if (MinhaSerial.available())
  { 
     while(MinhaSerial.available())
     {

       command += (char)MinhaSerial.read(); 
       
       if (command == "1"){
        digitalWrite(Led_13, HIGH);
       }
       else if (command == "2"){
        digitalWrite(Led_13, LOW);
       }
       
     } 
   Serial.println(command); 
   command = "";
  }
}
