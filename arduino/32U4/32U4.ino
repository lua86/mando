// Asignando botones:
const int buttonPinSelect = 2;
const int buttonPinStart = 3;
const int buttonPinDown = 4;
const int buttonPinUP = 5;
const int buttonPinLeft = 6;
const int buttonPinRight = 7;
const int buttonPinL = 8;
const int buttonPinR = 9;
const int buttonPinA = 10;
const int buttonPinB = 11;

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
int buttonStateA = 0;
int lastButtonStateA = 0;
int buttonStateB = 0;
int lastButtonStateB = 0;



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
  pinMode(buttonPinA, INPUT);
  pinMode(buttonPinB, INPUT);
  //  Initialize serial communication:
  // Serial.begin(9600);
  // Wait 0.2s and Initialize Keyboard
  delay(200);
  Keyboard.begin();
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
  buttonStateA = digitalRead(buttonPinA);
  buttonStateB = digitalRead(buttonPinB);
   if (buttonStateSelect == HIGH and lastButtonStateSelect == LOW) {
      // If the current state is HIGH then the button
      // Send to serial that the button is pressed:
     Keyboard.press('e');
  } else if (buttonStateSelect == LOW and lastButtonStateSelect == HIGH) {
      //If the current state is LOW and last state
      //State was HIGH then send to serial it is
      //not pressed anymore:
     Keyboard.release('e');
  }
  
   if (buttonStateStart == HIGH and lastButtonStateStart == LOW) {
     Keyboard.press('s');
  } else if (buttonStateStart == LOW and lastButtonStateStart == HIGH) {
     Keyboard.release('s');
  }

   if (buttonStateDown == HIGH and lastButtonStateDown == LOW) {
     Keyboard.press(KEY_DOWN_ARROW);
  } else if (buttonStateDown == LOW and lastButtonStateDown == HIGH) {
     Keyboard.release(KEY_DOWN_ARROW);
  }

   if (buttonStateUP == HIGH and lastButtonStateUP == LOW) {
     Keyboard.press(KEY_UP_ARROW);
  } else if (buttonStateUP == LOW and lastButtonStateUP == HIGH) {
     Keyboard.release(KEY_UP_ARROW);
  }

   if (buttonStateLeft == HIGH and lastButtonStateLeft == LOW) {
     Keyboard.press(KEY_LEFT_ARROW);
  } else if (buttonStateLeft == LOW and lastButtonStateLeft == HIGH) {
     Keyboard.release(KEY_LEFT_ARROW);
  }

   if (buttonStateRight == HIGH and lastButtonStateRight == LOW) {
     Keyboard.press(KEY_RIGHT_ARROW);
  } else if (buttonStateRight == LOW and lastButtonStateRight == HIGH) {
     Keyboard.release(KEY_RIGHT_ARROW);
  }

   if (buttonStateL == HIGH and lastButtonStateL == LOW) {
     Keyboard.press('l');
  } else if (buttonStateL == LOW and lastButtonStateL == HIGH) {
     Keyboard.release('l');
  }

   if (buttonStateR == HIGH and lastButtonStateR == LOW) {
     Keyboard.press('r');
  } else if (buttonStateR == LOW and lastButtonStateR == HIGH) {
     Keyboard.release('r');
  }

   if (buttonStateA == HIGH and lastButtonStateA == LOW) {
     Keyboard.press('a');
  } else if (buttonStateA == LOW and lastButtonStateA == HIGH) {
     Keyboard.release('a');
  }

   if (buttonStateB == HIGH and lastButtonStateB == LOW) {
     Keyboard.press('b');
  } else if (buttonStateB == LOW and lastButtonStateB == HIGH) {
     Keyboard.release('b');
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
  lastButtonStateA = buttonStateA;
  lastButtonStateB = buttonStateB;
delay('1');
}

