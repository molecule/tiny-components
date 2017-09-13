const int transistorPin = 0;    // connected to the base of the transistor
const int ledPin = 0;
int mode = 1; // track mode of the motor
const int switcher = -1;

void setup() {
  // put your setup code here, to run once:
  pinMode(transistorPin, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (mode < 0) {
    //digitalWrite(transistorPin, HIGH);
    analogWrite(transistorPin, 100);
    digitalWrite(ledPin, HIGH);
  } else {
    //digitalWrite(transistorPin, LOW);
    analogWrite(transistorPin, 0);
    digitalWrite(ledPin, LOW);
  }

  delay(1000);
  mode = mode * switcher;

}
