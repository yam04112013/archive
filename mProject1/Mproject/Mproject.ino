int start = 0;
int lbuttons = 1;
#define led1 11
#define led2 12
#define lboardButton1 7
#define lboardButton2 8
#define rboardButton3 9
#define rboardButton4 10
#define control1 5
#define control2 6
#define startButton 2
#define stopButton 3


void setup() {
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(control1, OUTPUT);
  pinMode(control2, OUTPUT);
  pinMode(lboardButton1, INPUT_PULLUP);
  pinMode(lboardButton2, INPUT_PULLUP);
  pinMode(rboardButton3, INPUT_PULLUP);
  pinMode(rboardButton4, INPUT_PULLUP);
  pinMode(startButton, INPUT_PULLUP);
  pinMode(stopButton, INPUT_PULLUP);
}
void move(int speed) {
  if (speed > 0) {
    digitalWrite(control1, 1);
    analogWrite(control2, 255 - speed);
  } else if (speed < 0) {
    analogWrite(control1, 255 + speed);
    digitalWrite(control2, 1);
  } else {
    digitalWrite(control1, 1);
    digitalWrite(control2, 1);
  }
}



void loop() {
  if (digitalRead(startButton) == 0) {
    start = 1;
  }


  while (start == 1) {
    if (lbuttons == 1) {
      move(100);
    }
    if ((digitalRead(lboardButton1)) == 0 && (digitalRead(lboardButton2)) == 0) {
      lbuttons = 0;
      digitalWrite(led1, 1);
    }else{
      digitalWrite(led1, 0);
    }
    if (lbuttons == 0) {
      move(-100);
    }
    if ((digitalRead(rboardButton3) == 0) && (digitalRead(rboardButton4) == 0)) {
      start = 0;
      lbuttons = 1;
      digitalWrite(led2, 1);
      move(0);
    }else{
      digitalWrite(led2, 0);
    }
  }
}