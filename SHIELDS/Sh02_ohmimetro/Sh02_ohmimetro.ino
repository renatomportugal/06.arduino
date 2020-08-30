void setup(){
  Serial.begin(9600);
}

void loop(){
 float analog, calculo, mediaTotal;
 int amostra1, amostra2, amostra3, amostra4, amostra5, resultado;
 //Meça com um multímetro confiável e coloque aqui o valor em Ohms.
 int rRef = 216;

 char leitura = Serial.read();
 analog = analogRead(5);
 
 if (leitura == 'r')
 {
   //PRIMEIRA LEITURA
   
   calculo = float(analog*5/1024);
   amostra1 = float(rRef *(5-calculo)/calculo);
   delay(50);
   
   //SEGUNDA LEITURA
   calculo = float(analog*5/1024);
   amostra2 = float(rRef *(5-calculo)/calculo);
   delay(50);
   
   //TERCEIRA LEITURA
   calculo = float(analog*5/1024);
   amostra3 = float(rRef *(5-calculo)/calculo);
   delay(50);
   
   //QUARTA LEITURA
   calculo = float(analog*5/1024);
   amostra4 = float(rRef *(5-calculo)/calculo);
   delay(50);
   
   //QUINTA LEITURA
   calculo = float(analog*5/1024);
   amostra5 = float(rRef *(5-calculo)/calculo);
   delay(50);
   
   //MEDIA DAS LEITURAS
   mediaTotal = ((amostra1+amostra2+amostra3+amostra4+amostra5)/5);
  
   //IMPRIME NA TELA
  Serial.print(mediaTotal);   
  Serial.println(" Ohms(s)");   
 }
}
