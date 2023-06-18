#define LED_PIN 8
#define BUTTON_PIN 7
void setup() {
  pinMode(LED_PIN, OUTPUT);
  pinMode(BUTTON_PIN, INPUT);
  Serial.begin(9600);
  randomSeed(analogRead(0)); // use noise on analog pin 0 for randomness
}



void loop() {
  if (digitalRead(BUTTON_PIN) == HIGH) {
    digitalWrite(LED_PIN, HIGH);
  }
  else {
    digitalWrite(LED_PIN, LOW);
  }
}

float getRandomNumber() {
  int randomInt = random(9901); // gives a random integer between 0 and 9900
  return 1.00 + (float)randomInt / 100.0; // divide by 100 to get a float with two decimal places, add 1 to ensure the lower limit is 1
}