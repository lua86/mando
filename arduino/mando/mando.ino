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
  // Read the pushbutton input pin:
  buttonStateSelect = digitalRead(buttonPinSelect);
  buttonStateStart = digitalRead(buttonPinStart);
  buttonStateDown = digitalRead(buttonPinDown);
  buttonStateUP = digitalRead(buttonPinUP);
  buttonStateLeft = digitalRead(buttonPinLeft);
  buttonStateRight = digitalRead(buttonPinRight);
  buttonStateL = digitalRead(buttonPinL);
  buttonStateR = digitalRead(buttonPinR);
 
   if (buttonStateSelect == HIGH and lastButtonStateSelect == LOW) {
      // If the current state is HIGH then the button
      // Send to serial that the button is pressed:   
      Serial.println("Select");
  } else if (buttonStateSelect == LOW and lastButtonStateSelect == HIGH) {
      //If the current state is LOW and last state
      //State was HIGH then send to serial it is
      //not pressed anymore:
      Serial.println("unSelect");
  }
  
   if (buttonStateStart == HIGH and lastButtonStateStart == LOW) {
      Serial.println("Start");
  } else if (buttonStateStart == LOW and lastButtonStateStart == HIGH) {
      Serial.println("unStart");
  }

   if (buttonStateDown == HIGH and lastButtonStateDown == LOW) {
      Serial.println("Down");
  } else if (buttonStateDown == LOW and lastButtonStateDown == HIGH) {
      Serial.println("unDown");
  }

   if (buttonStateUP == HIGH and lastButtonStateUP == LOW) {
      Serial.println("UP");
  } else if (buttonStateUP == LOW and lastButtonStateUP == HIGH) {
      Serial.println("unUP");
  }

   if (buttonStateLeft == HIGH and lastButtonStateLeft == LOW) {
      Serial.println("Left");
  } else if (buttonStateLeft == LOW and lastButtonStateLeft == HIGH) {
      Serial.println("unLeft");
  }

   if (buttonStateRight == HIGH and lastButtonStateRight == LOW) {
      Serial.println("Right");
  } else if (buttonStateRight == LOW and lastButtonStateRight == HIGH) {
      Serial.println("unRight");
  }

   if (buttonStateL == HIGH and lastButtonStateL == LOW) {
      Serial.println("L");
  } else if (buttonStateL == LOW and lastButtonStateL == HIGH) {
      Serial.println("unL");
  }

   if (buttonStateR == HIGH and lastButtonStateR == LOW) {
      Serial.println("R");
  } else if (buttonStateR == LOW and lastButtonStateR == HIGH) {
      Serial.println("unR");
  }
 
  
  // Save the current state as the last state,
  // for next time through the loop
  lastButtonStateSelect = buttonStateSelect;
  lastButtonStateStart = buttonStateStart;
  lastButtonStateDown = buttonStateDown;
  lastButtonStateUP = buttonStateUP;
  lastButtonStateLeft = buttonStateLeft;
  lastButtonStateRight = buttonStateRight;
  lastButtonStateL = buttonStateL;
  lastButtonStateR = buttonStateR;
delay('1');
Serial.flush();
}

