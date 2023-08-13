// set pins
const int button = A0;

int display = 0;

int buttonState = 0;
int lastButtonState = 0;

void setup() {
  pinMode(button, INPUT);
  digitalWrite(button, true);
  Serial.begin(9600);
}

void loop() {

  buttonState = analogRead(button);

  if (buttonState < 500 && lastButtonState >= 500) {
    if (display == 9) {
      display = 0;
    } else {
      display++;
    }
    Serial.print("Number: ");
    Serial.println(display);
    delay(200);
  }

  lastButtonState = buttonState;



}
