// Declaring variables
#define trig 2
#define echo 3
const int forwardPinR = 8;
const int backwardPinR = 12;
const int forwardPinL = 9;
const int backwardPinL = 13;
int count;
// Setup function
void setup() { 
  Serial.begin(9600); // Setup console
  // Declaring pins
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
}
// Main loop
void loop() {
  // Receiving clear data from sensor
  int time, dist;
  digitalWrite(trig, HIGH);
  delayMicroseconds(1000);
  digitalWrite(trig, LOW);
  time = pulseIn(echo, HIGH);
  dist = (time/2)/29.1;
  Serial.print(dist);
  Serial.print('\n');

  // Getting nagative number sequence
  if ( dist <=-127) {
    count++;
  }
  else {
    count = 0;
  }

  Serial.print(count);
  // Calling functions to make turning action
  if (dist <= 14 && dist >= -14 || count == 4) {
    stop();
    delay(1000);
    reverse();
    delay(500);
    stop();
    delay(1000);
    turnRight();
    delay(500);
    stop();
    delay(1000);
  }
  else {
    drive();
  }

  // setting counter to default after sequense was found
  if (count == 4) {
    count = 0;
  }
}

// All the functions that moves robot
void turnRight() {
  digitalWrite (forwardPinL, HIGH);
  digitalWrite (backwardPinR, HIGH);
}

void reverse() {
  digitalWrite (backwardPinL, HIGH);
  digitalWrite (backwardPinR, HIGH);
}

void stop() {
  digitalWrite (forwardPinL, LOW);
  digitalWrite (backwardPinL, LOW);
  digitalWrite (backwardPinR, LOW);
  digitalWrite (forwardPinR, LOW);
}

void drive() {
  digitalWrite (forwardPinL, HIGH);
  digitalWrite (forwardPinR, HIGH);
}