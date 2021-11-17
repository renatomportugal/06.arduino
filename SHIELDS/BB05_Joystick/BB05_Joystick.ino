//POTENCIOMETRO
#define LeftVert A5
#define LeftHori A4
#define RightVert A3
#define RightHori A2
#define BtnLeft A1
#define BtnRight A0

void setup() {
  Serial.begin(9600);
  
  pinMode (LeftVert, INPUT);
  pinMode (LeftHori, INPUT);
  pinMode (RightVert, INPUT);
  pinMode (RightHori, INPUT);
  pinMode (BtnLeft, INPUT);
  pinMode (BtnRight, INPUT);
}


void loop () {
  int intLeftVert = analogRead(LeftVert);
  int intLeftHori = analogRead(LeftHori);
  int intRightVert = analogRead(RightVert);
  int intRightHori = analogRead(RightHori);
  bool boolBtnLeft = digitalRead(BtnLeft);
  bool boolBtnRight = digitalRead(BtnRight);

  Serial.print("LV: ");
  Serial.print(intLeftVert);
  Serial.print(" - LH: ");
  Serial.print(intLeftHori);
  Serial.print(" - RV: ");
  Serial.print(intRightVert);
  Serial.print(" - RH: ");
  Serial.print(intRightHori);
  Serial.print(" - LB: ");
  Serial.print(boolBtnLeft);
  Serial.print(" - RB: ");
  Serial.println(boolBtnRight);
  delay(200);
}
