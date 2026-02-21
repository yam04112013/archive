#define ML1 10
#define ML2 6
#define MR1 5
#define MR2 9
#define LED_GR A1
#define LED_BL A2
int bt;            //                                             BT READ INT
int speedmod = 1;  //                                   SPEEDMOD INT
bool can_drive = 0;

void setup() {
  pinMode(ML1, OUTPUT);
  pinMode(ML2, OUTPUT);
  pinMode(MR1, OUTPUT);
  pinMode(MR2, OUTPUT);
  pinMode(LED_GR, OUTPUT);
  pinMode(LED_BL, OUTPUT);
  Serial.begin(9600);
}

void drive(int left, int right) {  //                     DRIVE
  if (can_drive == 1) {
    if (left > 0) {  //                                   DRIVE_LEFT
      digitalWrite(ML1, 1);
      analogWrite(ML2, 255 - left);
    } else {
      digitalWrite(ML2, 1);
      analogWrite(ML1, 255 - left);
    }



    if (right > 0) {  //                                   DRIVE_RIGHT
      digitalWrite(MR1, 1);
      analogWrite(MR2, 255 - right);
    } else {
      digitalWrite(MR2, 1);
      analogWrite(MR1, 255 - right);
    }
  }
}

void loop() {
  if(analogRead(A0)<484){
    digitalWrite(LED_BL, 1);
  }else{
    digitalWrite(LED_BL,0);
  }
  if (Serial.available()) {
    bt = Serial.read();
  }
  if (bt == 'N') {
    can_drive = 1;
  } else if (bt == 'n') {
    can_drive = 0;
  }
  if (bt == 'F') {  //                     command F
    drive(100 * speedmod, 100 * speedmod);
  }
  if (bt == 'B') {  //                     command B
    drive(-150 , -150 );
  }
  if (bt == 'R') {  //                     command R
    drive(-100, 100*speedmod );
  }
  if (bt == 'L') {  //                     command L
    drive(100*speedmod , -100 );
  }
  if (bt == 'I') {  //                     command I
    drive(50 * speedmod, 100 * speedmod);
  }
  if (bt == 'G') {  //                     command G
    drive(100 * speedmod, 50* speedmod);
  }
  if (bt == 'J') {  //                     command J
    drive(-150, -255 );
  }
  if (bt == 'H') {  //                     command H
    drive(-255 , -150);
  }
  if (bt == 'S') {  //                     command STOP
    drive(0, 0);
  }
  if (bt == 'K') {  //                     SPEEDMOD CHANGE
    speedmod = 1.8;
  } else if (bt == 'k') {
    speedmod = 1;
  }
}