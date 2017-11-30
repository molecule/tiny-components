/*
Serial code based off of original work
 by Tom Igoe
 created 13 Apr 2012
 
 modified 14 Mar 2016
 by Arturo Guadalupi

 This example code is in the public domain.

 circuit: http://bildr.org/2011/03/high-power-control-with-arduino-and-tip120/
 */

const int controlPin = 9;

void setup() {
  // initialize serial:
  Serial.begin(9600);
  // make the pins outputs:
  pinMode(controlPin, OUTPUT);
  Serial.println("simple serial........for breakfast!");
}

void loop() {
  // if there's any serial available, read it:
  while (Serial.available() > 0) {
    int val = Serial.parseInt();
    analogWrite(controlPin, val);
    delay(50);
  
    // look for the newline. That's the end of your
    // sentence:
    if (Serial.read() == '\n') {
      Serial.print("val: ");
      Serial.println(val);
    }
  }
}








