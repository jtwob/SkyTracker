// Define pins for the stepper driver
#define STEP_PIN 3 // Connect to PUL+
#define DIR_PIN 4  // Connect to DIR+
//#define ENABLE_PIN 7 // Optional, connect to ENABLE+ if your driver supports it

// Stepper motor settings
int stepsPerRevolution = 25600; // Adjust according to your motor's specs
int speedDelay = 1;        // Microseconds between steps (adjust for speed)
int dayLen = 86400;

void setup() {
  // Set pin modes
  pinMode(STEP_PIN, OUTPUT);
  pinMode(DIR_PIN, OUTPUT);
}

void loop() {
  // // Rotate once per day
  digitalWrite(DIR_PIN, HIGH); // Set direction to clockwise
  stepMotor();
  delay(dayLen*1000/(stepsPerRevolution*16)); 

  // // Rotate counterclockwise
  // digitalWrite(DIR_PIN, LOW); // Set direction to counterclockwise
  // for (int i = 0; i < stepsPerRevolution*16; i++) {
  //   stepMotor();
  // }
  // delay(1000); // Pause for 1 second
}

// Function to take a single step
void stepMotor() {
  digitalWrite(STEP_PIN, HIGH);
  delayMicroseconds(speedDelay); // Wait for step duration
  digitalWrite(STEP_PIN, LOW);
  delayMicroseconds(speedDelay); // Wait for step duration
}