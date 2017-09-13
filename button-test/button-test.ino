
const int buttonPin = 8;
const int ledPin = 13;

int buttonState = LOW; //this variable tracks the state of the button, low if not pressed, high if pressed
int ledState = -1; //this variable tracks the state of the LED, negative if off, positive if on
 
long lastDebounceTime = 0;  // the last time the output pin was toggled
long debounceDelay = 150;    // the debounce time; increase if the output flickers
 

void setup() {
  Serial.begin(9600);
  // put your setup code here, to run once:
  // Buttons setup
  pinMode(buttonPin, INPUT);
  pinMode(ledPin, OUTPUT);
  //enablePinInterupt(buttonPin);

  //timer1_init(100); // varable timer (1000 = 1 second)
}

void loop() {
  // put your main code here, to run repeatedly:
  debouncedButtonRead();
}

void debouncedButtonRead() {
  //sample the state of the button - is it pressed or not?
  buttonState = digitalRead(buttonPin);
 
  //filter out any noise by setting a time buffer
  if ( (millis() - lastDebounceTime) > debounceDelay) {
     if ( (buttonState == HIGH)) {
      lastDebounceTime = millis(); //set the current time
      Serial.println("button_press");
    }
  }//close if(time buffer)
}

void button_press() {
  Serial.println("button press");
}

void enablePinInterupt(byte pin)
{
    *digitalPinToPCMSK(pin) |= bit (digitalPinToPCMSKbit(pin));  // enable pin
    PCIFR  |= bit (digitalPinToPCICRbit(pin)); // clear any outstanding interrupt
    PCICR  |= bit (digitalPinToPCICRbit(pin)); // enable interrupt for the group
}

ISR (PCINT0_vect) // handle pin change interrupt for D8 to D13 here
{
  if(digitalRead(buttonPin)) {  button_press(); }
  //if(digitalRead(switchPin)) { switch_change(); }
}


