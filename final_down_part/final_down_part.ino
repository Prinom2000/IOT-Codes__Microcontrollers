#include <AFMotor.h>
#include <Servo.h>

// Ultrasonic sensor pins
#define trigpin A5
#define echopin A4

// Motor definitions
AF_DCMotor motor1(1, MOTOR12_64KHZ);
AF_DCMotor motor2(2, MOTOR12_64KHZ);
AF_DCMotor motor3(3, MOTOR34_64KHZ);
AF_DCMotor motor4(4, MOTOR34_64KHZ);

Servo myservo;  // Servo for obstacle avoidance mode

// Variables
char command;
bool obstacleMode = false;
int distance_L, distance_F, distance_R;
long distance;
int setDistance = 50;  // Distance threshold for obstacle avoidance

void setup() {
  Serial.begin(9600);
  myservo.attach(10);
  myservo.write(90);  // Center position
  pinMode(trigpin, OUTPUT);
  pinMode(echopin, INPUT);

  // Set motor speeds
  motor1.setSpeed(255);
  motor2.setSpeed(255);
  motor3.setSpeed(255);
  motor4.setSpeed(255);

  Serial.println("Ready to receive commands");
}

void loop() {
  if (Serial.available() > 0) {
    command = Serial.read();
    if (command == 'W') {

      motor1.setSpeed(100);
      motor2.setSpeed(100);
      motor3.setSpeed(100); 
      motor4.setSpeed(100);

      obstacleMode = !obstacleMode;  // Toggle obstacle mode
      if (obstacleMode) {
        Serial.println("W");
        for (;;) {
          distance_F = measureDistance();
          Serial.println(distance_F);

          if (distance_F != 0) {
            if (distance_F > setDistance) {
              forward();
              Serial.println(distance_F);
            } else {
              Stop();
              back();
              scanSurroundings();
              compareDistances();
            }
          }
        }

      } else {
        Serial.println("Manual control mode ON");
        Stop();  // Stop all motors in case of mode switch
      }
    }
    if (!obstacleMode) {
      manualControl(command);  // Execute manual control commands
    }

    // if (command == 'U') {
    //   distance_F = measureDistance();
    //   // Adjust distance thresholds as needed
    //   if(distance_F!=0){
    //     if (distance_F > 20) {
    //     forward();  // Move forward to follow object
    //   } else if (distance_F < 10) {
    //     back();  // Move back if too close
    //   } else {
    //     Stop();  // Stop if object is out of range
    //   }
    //   }
      
    // }
  }

  if (obstacleMode) {
    obstacleAvoidance();
  }
}

// Manual Control Functions
void manualControl(char command) {
  Stop();  // Start by stopping the motors

  if (command == 'F') {
    Serial.println("F");
    forward();
  } else if (command == 'B') {
    Serial.println("B");
    back();
  } else if (command == 'L') {
    Serial.println("L");
    left();
  } else if (command == 'R') {
    Serial.println("R");
    right();
  } else if (command == 'I') {
    Serial.println("I");
    r();
  } else if (command == 'G') {
    Serial.println("G");
    l();
  }

  else if (command == 'O') {
  }
}

void r() {
  motor1.run(FORWARD);
  motor2.run(BACKWARD);
  motor3.run(BACKWARD);
  motor4.run(FORWARD);
}

void l() {
  motor1.run(BACKWARD);
  motor2.run(FORWARD);
  motor3.run(FORWARD);
  motor4.run(BACKWARD);
}

void forward() {
  motor1.run(FORWARD);
  motor2.run(FORWARD);
  motor3.run(FORWARD);
  motor4.run(FORWARD);
}

void back() {
  motor1.run(BACKWARD);
  motor2.run(BACKWARD);
  motor3.run(BACKWARD);
  motor4.run(BACKWARD);
}

void left() {
  motor1.run(BACKWARD);
  motor2.run(BACKWARD);
  motor3.run(FORWARD);
  motor4.run(FORWARD);
}

void right() {
  motor1.run(FORWARD);
  motor2.run(FORWARD);
  motor3.run(BACKWARD);
  motor4.run(BACKWARD);
}

void Stop() {
  motor1.run(RELEASE);
  motor2.run(RELEASE);
  motor3.run(RELEASE);
  motor4.run(RELEASE);
}

// Obstacle Avoidance Functions
void obstacleAvoidance() {
  distance_F = measureDistance();
  if (distance_F > setDistance) {
    forward();
  } else {
    Stop();
    scanSurroundings();
    compareDistances();
  }
}

long measureDistance() {
  digitalWrite(trigpin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigpin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigpin, LOW);
  distance = pulseIn(echopin, HIGH);
  return distance / 29 / 2;
}

void scanSurroundings() {
  myservo.write(0);
  delay(300);
  distance_R = measureDistance();

  delay(100);

  myservo.write(170);
  delay(500);
  distance_L = measureDistance();

  delay(100);

  myservo.write(90);  // Center servo
  delay(300);
}

void compareDistances() {
  if (distance_L > distance_R) {
    Serial.println("LLLLLLLLLLLL: " + distance_L);
    left();
    delay(350);
  } else if (distance_R > distance_L) {
    Serial.println("RRRRRRRRR: " + distance_R);
    right();
    delay(350);
  }
  // else {
  //   back();
  //   delay(300);
  //   left();
  //   delay(500);
  // }
}
