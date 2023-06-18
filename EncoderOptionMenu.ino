#define DEBOUNCE_DELAY 50 // Debounce delay in milliseconds

volatile int optionSet = 0;
//String colorOptions[3] = {"Red", "Green", "Blue"};
String seatPositions[6] = { "BT", "SB",  "BB", "UTG_LJ", "HJ", "CO"};
//String sizeOptions[3] = {"Small", "Medium", "Large"};
String actions[4] = {"RFI", "Face_RFI", "3-BET", "4-BET"};
String shapeOptions[3] = {"Circle", "Square", "Triangle"};

//volatile int colorOption = 0;
volatile int seatPosition = 0;
//volatile int sizeOption = 0;
volatile int action = 0;
volatile int shapeOption = 0;

volatile unsigned long lastEncoderTurnTime = 0;  // For debouncing
volatile unsigned long lastEncoderPushTime = 0;  // For debouncing

void setup() {
  Serial.begin(9600);
  attachInterrupt(digitalPinToInterrupt(3), onEncoderTurn, LOW);
  attachInterrupt(digitalPinToInterrupt(2), onEncoderPush, FALLING);
  
  pinMode(2,INPUT_PULLUP);
  pinMode(4,INPUT);
}

void onEncoderTurn() {
  unsigned long now = millis();
  if (now - lastEncoderTurnTime > DEBOUNCE_DELAY) {
    if (digitalRead(4) == digitalRead(3)) { // replace with your pin numbers
      // rotation is clockwise
      if (optionSet == 0) {
        seatPosition = (seatPosition + 1) % 6;
      }
      else if (optionSet == 1) {
        action = (action + 1) % 4;
      }
      else if (optionSet == 2) {
        shapeOption = (shapeOption + 1) % 3;
      }
    }
    else {
      // rotation is counter-clockwise
      if (optionSet == 0) {
        seatPosition = (seatPosition - 1 + 6) % 6; // add 3 to avoid negative numbers
      }
      else if (optionSet == 1) {
        action = (action - 1 + 4) % 4;
      }
      else if (optionSet == 2) {
        shapeOption = (shapeOption - 1 + 3) % 3;
      }
    }
    lastEncoderTurnTime = now;
  }
}


void onEncoderPush() {
  unsigned long now = millis();
  if (now - lastEncoderPushTime > DEBOUNCE_DELAY) {
    optionSet = (optionSet + 1) % 3;
    lastEncoderPushTime = now;
  }
}

void loop() {
  Serial.print("Current color: ");
  Serial.print(seatPositions[seatPosition]);
  Serial.print(" Current size: ");
  Serial.print(actions[action]);
  Serial.print(" Current shape: ");
  Serial.println(shapeOptions[shapeOption]);

  delay(1000);
}
