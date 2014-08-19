// Asignando botones:
const int buttonPinSelect = 2;
const int buttonPinStart = 3;
const int buttonPinDown = 4;
const int buttonPinUP = 5;
const int buttonPinLeft = 6;
const int buttonPinRight = 7;
const int buttonPinL = 8;
const int buttonPinR = 9;

// Variables:
int buttonStateSelect = 0;
int lastButtonStateSelect = 0;
int buttonStateStart = 0;
int lastButtonStateStart = 0;
int buttonStateDown = 0;
int lastButtonStateDown = 0;
int buttonStateUP = 0;
int lastButtonStateUP = 0;
int buttonStateLeft = 0;
int lastButtonStateLeft = 0;
int buttonStateRight = 0;
int lastButtonStateRight = 0;
int buttonStateL = 0;
int lastButtonStateL = 0;
int buttonStateR = 0;
int lastButtonStateR = 0;

void setup() {
  // Initialize the button pin as an input:
  pinMode(buttonPinSelect, INPUT);
  pinMode(buttonPinStart, INPUT);
  pinMode(buttonPinDown, INPUT);
  pinMode(buttonPinUP, INPUT);
  pinMode(buttonPinLeft, INPUT);
  pinMode(buttonPinRight, INPUT);
  pinMode(buttonPinL, INPUT);
  pinMode(buttonPinR, INPUT);
  // Initialize serial communication:
  Serial.begin(9600);
}

void loop() {
  buttonStateSelect = 0;
  // Read the pushbutton input pin:
  buttonStateSelect = digitalRead(buttonPinSelect);
 
    if (buttonStateSelect == HIGH) {
      // If the current state is HIGH then the button
      // Send to serial that the engine has started:   
      Serial.println("Select");
      delay (100);
  }
  // Save the current state as the last state,
  // for next time through the loop
  lastButtonStateUP = buttonStateUP;
}
// *********************************************
