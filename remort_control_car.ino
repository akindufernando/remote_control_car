// Pin definitions
const int motorA_EN = 9;
const int motorB_EN = 10;
const int motorA_IN1 = 7;
const int motorA_IN2 = 6;
const int motorB_IN3 = 5;
const int motorB_IN4 = 4;

// Setup function to configure pins
void setup() {
  // Set motor control pins as output
  pinMode(motorA_EN, OUTPUT);
  pinMode(motorB_EN, OUTPUT);
  pinMode(motorA_IN1, OUTPUT);
  pinMode(motorA_IN2, OUTPUT);
  pinMode(motorB_IN3, OUTPUT);
  pinMode(motorB_IN4, OUTPUT);

  // Enable serial communication for Bluetooth module
  Serial.begin(9600);
}

// Function to move the car forward
void moveForward() {
  digitalWrite(motorA_IN1, HIGH);
  digitalWrite(motorA_IN2, LOW);
  digitalWrite(motorB_IN3, HIGH);
  digitalWrite(motorB_IN4, LOW);
  analogWrite(motorA_EN, 255);
  analogWrite(motorB_EN, 255);
}

// Function to move the car backward
void moveBackward() {
  digitalWrite(motorA_IN1, LOW);
  digitalWrite(motorA_IN2, HIGH);
  digitalWrite(motorB_IN3, LOW);
  digitalWrite(motorB_IN4, HIGH);
  analogWrite(motorA_EN, 255);
  analogWrite(motorB_EN, 255);
}

// Function to turn the car left
void turnLeft() {
  digitalWrite(motorA_IN1, LOW);
  digitalWrite(motorA_IN2, HIGH);
  digitalWrite(motorB_IN3, HIGH);
  digitalWrite(motorB_IN4, LOW);
  analogWrite(motorA_EN, 200);
  analogWrite(motorB_EN, 200);
}

// Function to turn the car right
void turnRight() {
  digitalWrite(motorA_IN1, HIGH);
  digitalWrite(motorA_IN2, LOW);
  digitalWrite(motorB_IN3, LOW);
  digitalWrite(motorB_IN4, HIGH);
  analogWrite(motorA_EN, 200);
  analogWrite(motorB_EN, 200);
}

// Function to stop the car
void stopCar() {
  digitalWrite(motorA_IN1, LOW);
  digitalWrite(motorA_IN2, LOW);
  digitalWrite(motorB_IN3, LOW);
  digitalWrite(motorB_IN4, LOW);
  analogWrite(motorA_EN, 0);
  analogWrite(motorB_EN, 0);
}

// Main loop to read Bluetooth commands and control the car
void loop() {
  if (Serial.available() > 0) {
    char command = Serial.read();
    
    if (command == '1') { // Forward command
      moveForward();
    } 
    else if (command == '2') { // Backward command
      moveBackward();
    } 
    else if (command == '3') { // Left turn command
      turnLeft();
    } 
    else if (command == '4') { // Right turn command
      turnRight();
    } 
    else if (command == '5') { // Stop command
      stopCar();
    } 
    else {
      stopCar(); // Stop if unknown command
    }
  }
}
