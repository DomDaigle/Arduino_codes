#define DEBOUNCE_DELAY 50 // Debounce delay in milliseconds

String positions[6] = {"BT", "SB", "BB", "UTG_LJ", "HJ", "CO"};
String* optionSets[4]; // An array of pointers to the option arrays

// Initialize all option sets to the full list of positions
String RFI_options[6] = {"BT", "SB", "BB", "UTG_LJ", "HJ", "CO"};
String FACE_RFI_options[5]; // One option will be excluded
String _3_BET_options[5];
String _4_BET_options[5];

int optionsCount[4] = {6, 5, 5, 5};

int currentOptionIndices[4] = {0, 0, 0, 0}; // Index of the current option for each set

volatile int optionSet = 0; // Index of the current option set
volatile unsigned long lastEncoderTurnTime = 0;  // For debouncing
volatile unsigned long lastEncoderPushTime = 0;  // For debouncing

void setup() {
  Serial.begin(9600);
  attachInterrupt(digitalPinToInterrupt(3), onEncoderTurn, LOW);
  attachInterrupt(digitalPinToInterrupt(2), onEncoderPush, FALLING);
  
  pinMode(2,INPUT_PULLUP);
  pinMode(4,INPUT);
  
  optionSets[0] = RFI_options;
  optionSets[1] = FACE_RFI_options;
  optionSets[2] = _3_BET_options;
  optionSets[3] = _4_BET_options;
}

void onEncoderTurn() {
  unsigned long now = millis();
  if (now - lastEncoderTurnTime > DEBOUNCE_DELAY) {
    if (digitalRead(4) == 1) {
      currentOptionIndices[optionSet] = (currentOptionIndices[optionSet] + 1) % optionsCount[optionSet];
    }
    lastEncoderTurnTime = now;
  }
}

void onEncoderPush() {
  unsigned long now = millis();
  if (now - lastEncoderPushTime > DEBOUNCE_DELAY) {
    // Before switching to the next option set, update the remaining sets to exclude the chosen option
    if (optionSet == 0) {
      int chosenOptionIndex = currentOptionIndices[0];
      String chosenOption = optionSets[0][chosenOptionIndex];
      
      for (int set = 1; set < 4; set++) {
        int optionIndex = 0;
        for (int i = 0; i < 6; i++) {
          if (RFI_options[i] != chosenOption) {
            optionSets[set][optionIndex++] = RFI_options[i];
          }
        }
      }
    }
    
    optionSet = (optionSet + 1) % 4;
    lastEncoderPushTime = now;
  }
}
String optionSetNames[4] = {"RFI", "FACE_RFI", "3-BET", "4-BET"};

void loop() {
  Serial.print("Start Position: ");
  Serial.print(RFI_options[currentOptionIndices[0]]);
  Serial.print(" - Current Action: ");
  Serial.print(optionSetNames[optionSet]);
  Serial.print(" - Vilain position: ");
  Serial.println(optionSets[optionSet][currentOptionIndices[optionSet]]);
  delay(1000);
}
