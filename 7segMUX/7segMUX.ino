//  Set delay time for the mux
int delayInt = 1;

// set pins
// inputs
const int button = A0;
const int pot = A1;

// Selectors on mulitiplexer
const int S0 = 2;
const int S1 = 3;
const int S2 = 4;


// ~~~~~~~~~~~~~~~
// 7seg to MUX key
// ~~~~~~~~~~~~~~~
// segA - A0
// segB - A3
// segC - A7
// segD - A6
// segE - A4
// segF - A1
// segG - A2
// segDP - A5
// ~~~~~~~~~~~~~~


int number = 0;

int buttonState = 0;
int lastButtonState = 0;


// Logic for the multiplexer
void segA() {
  digitalWrite(S0, LOW);
  digitalWrite(S1, LOW);
  digitalWrite(S2, LOW);
}
void segB() {
  digitalWrite(S0, HIGH);
  digitalWrite(S1, HIGH);
  digitalWrite(S2, LOW);
}
void segC() {
  digitalWrite(S0, HIGH);
  digitalWrite(S1, HIGH);
  digitalWrite(S2, HIGH);
}
void segD() {
  digitalWrite(S0, LOW);
  digitalWrite(S1, HIGH);
  digitalWrite(S2, HIGH);
}
void segE() {
  digitalWrite(S0, LOW);
  digitalWrite(S1, LOW);
  digitalWrite(S2, HIGH);
}
void segF() {
  digitalWrite(S0, HIGH);
  digitalWrite(S1, LOW);
  digitalWrite(S2, LOW);
}
void segG() {
  digitalWrite(S0, LOW);
  digitalWrite(S1, HIGH);
  digitalWrite(S2, LOW);
}
void segDP() {
  digitalWrite(S0, HIGH);
  digitalWrite(S1, LOW);
  digitalWrite(S2, HIGH);
}

void display0() {
  segA();
  delay(delayInt);
  segB();
  delay(delayInt);
  segC();
  delay(delayInt);
  segD();
  delay(delayInt);
  segE();
  delay(delayInt);
  segF();
  delay(delayInt);
}
void display1() {
  segB();
  delay(delayInt);
  segC();
  delay(delayInt);
}
void display2() {
  segA();
  delay(delayInt);
  segB();
  delay(delayInt);
  segG();
  delay(delayInt);
  segE();
  delay(delayInt);
  segD();
  delay(delayInt);
}
void display3() {
  segA();
  delay(delayInt);
  segB();
  delay(delayInt);
  segG();
  delay(delayInt);
  segC();
  delay(delayInt);
  segD();
  delay(delayInt);
}
void display4() {
  segB();
  delay(delayInt);
  segC();
  delay(delayInt);
  segF();
  delay(delayInt);
  segG();
  delay(delayInt);
}
void display5() {
  segA();
  delay(delayInt);
  segF();
  delay(delayInt);
  segG();
  delay(delayInt);
  segC();
  delay(delayInt);
  segD();
  delay(delayInt);
}
void display6() {
  segA();
  delay(delayInt);
  segF();
  delay(delayInt);
  segE();
  delay(delayInt);
  segC();
  delay(delayInt);
  segD();
  delay(delayInt);
  segG();
  delay(delayInt);
}
void display7() {
  segA();
  delay(delayInt);
  segB();
  delay(delayInt);
  segC();
  delay(delayInt);
  segC();
}
void display8() {
  segA();
  delay(delayInt);
  segF();
  delay(delayInt);
  segG();
  delay(delayInt);
  segC();
  delay(delayInt);
  segD();
  delay(delayInt);
  segE();
  delay(delayInt);
  segB();
}
void display9() {
  segA();
  delay(delayInt);
  segF();
  delay(delayInt);
  segG();
  delay(delayInt);
  segB();
  delay(delayInt);
  segC();
  delay(delayInt);
  segD();
}
void displayDP() {
  segDP();
}

void checkNumber() {
  switch (number) {
    case 0:
      display0();
      break;
    case 1:
      display1();
      break;
    case 2:
      display2();
      break;
    case 3:
      display3();
      break;
    case 4:
      display4();
      break;
    case 5:
      display5();
      break;
    case 6:
      display6();
      break;
    case 7:
      display7();
      break;
    case 8:
      display8();
      break;
    case 9:
      display9();
      break;
    default:
      displayDP();
      break;
  }
}

void setup() {
  Serial.begin(9600);
  pinMode(button, INPUT);
  digitalWrite(button, true); // Enable the internal pull-up resistor for the pin

  pinMode(S0, OUTPUT);
  pinMode(S1, OUTPUT);
  pinMode(S2, OUTPUT);

}

void loop() {
  buttonState = analogRead(button);

  int potValue = analogRead(pot);
  int mappedValue = map(potValue, 0, 1023, 1, 500);
  delayInt = mappedValue;

  Serial.print("Mapped Value: ");
  Serial.println(mappedValue);
  // delay(1);
  
  

  if (buttonState < 500 && lastButtonState >= 500) {
    if (number == 9) {
      number = 0;
    } else {
      number++;
    }
    Serial.print("Number: ");
    Serial.println(number);
    delay(200);
  }

  lastButtonState = buttonState;
  checkNumber();
}
