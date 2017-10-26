/*
  Reading a serial ASCII-encoded string.

 This sketch demonstrates the Serial parseInt() function.
 It looks for an ASCII string of comma-separated values.
 It parses them into ints, and uses those to fade an RGB LED.

 Circuit: Common-Cathode RGB LED wired like so:
 * Red anode: digital pin 3
 * Green anode: digital pin 5
 * Blue anode: digital pin 6
 * Cathode : GND

 created 13 Apr 2012
 by Tom Igoe
 
 modified 14 Mar 2016
 by Arturo Guadalupi

 This example code is in the public domain.
 */

const int controlPin = 8;
const int ledPin = 13;

void setup() {
  // initialize serial:
  Serial.begin(9600);
  // make the pins outputs:
  pinMode(controlPin, OUTPUT);
  pinMode(ledPin, OUTPUT);
  Serial.println("simple serial........for breakfast!");
}

void loop() {
  // if there's any serial available, read it:
  while (Serial.available() > 0) {
    int val = Serial.parseInt();
    if (val == 0) {
      digitalWrite(controlPin, LOW);
      digitalWrite(ledPin, LOW);
    } 
    if (val == 1) {
      digitalWrite(controlPin, HIGH);
      digitalWrite(ledPin, HIGH);
    }
    // look for the newline. That's the end of your
    // sentence:
    if (Serial.read() == '\n') {
      Serial.print("val: ");
      Serial.println(val);
    }
  }
}








