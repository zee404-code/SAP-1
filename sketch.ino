int clockState = LOW;
int address[] = {A3,A2,A1,A0};
int output[] = {3, 4,5,6,7,8,9,10};
int ram[16][8] = {
  {0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,1},
  {0,0,0,0,0,0,1,0},
  {0,0,0,0,0,0,1,1},
  {0,0,0,0,0,1,0,0},
  {0,0,0,0,0,1,0,1},
  {0,0,0,0,0,1,1,0},
  {0,0,0,0,0,1,1,1},
  {0,0,0,0,1,0,0,0},
  {0,0,0,0,1,0,0,1},
  {0,0,0,0,1,0,1,0},
  {0,0,0,0,1,0,1,1},
  {0,0,0,0,1,1,0,0},
  {0,0,0,0,1,1,0,1},
  {0,0,0,0,1,1,1,0},
  {0,0,0,0,1,1,1,1}
};
void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
pinMode(0, OUTPUT);
pinMode(A5, OUTPUT);
pinMode(3, INPUT);
pinMode(4, INPUT);
pinMode(5, INPUT);
pinMode(6, INPUT);

pinMode(A0, INPUT);
pinMode(A1, INPUT);
pinMode(A2, INPUT);
pinMode(A3, INPUT);
}


void loop() {
  // put your main code here, to run repeatedly:
  int x1 = digitalRead(3);
  int x2 = digitalRead(4);
  int x3 = digitalRead(5);
  int x4 = digitalRead(6);
  if(clockState==HIGH){int decimalValue = 8 * x4 + 4 * x3 + 2 * x2 + 1 *x1;
  Serial.println(decimalValue);
  Serial.println();

   for (int i = 0; i < 8; i++){
      digitalWrite(output[i], ram[decimalValue][i]);
      Serial.print(ram[decimalValue][i]);
    }
  }
   else {
      for (int i = 0; i < 8; i++){
      digitalWrite(output[i], 0);
    }
   }
  Serial.println();
clockState = (clockState == LOW) ? HIGH : LOW;
  
  // Output the clock state on the clockPin
digitalWrite(A5, clockState);
digitalWrite(0, LOW);

  
  // Add a delay to control the clock frequency
  delay(1000);
}
