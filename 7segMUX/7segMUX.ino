//  Set delay time for the mux
const int delayInt = 1;

// set pins
const int button = A0;
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
void displayDP() {
  segDP();
}

void checkNumber() {
  if (number == 0) {
    display0();
  } else if (number == 1) {
    display1();
  } else if (number == 2) {
    display2();
  }else if (number == 4) {
    display4();
  } else {
    displayDP();
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
