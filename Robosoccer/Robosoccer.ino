// Pin definitions
#define in1 12
#define in2 11
#define in3 10
#define in4 9

// Speed control variables
int motorSpeed = 255; // Default maximum speed

void setup() {
  Serial.begin(9600);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
}

void loop() {
  if (Serial.available() > 0) {
    char inputvalue = char(Serial.read());
    Serial.println(inputvalue);
    if (inputvalue == 'F') { // Forward
      analogWrite(in1, motorSpeed);
      analogWrite(in2, LOW);
      analogWrite(in3, LOW);
      analogWrite(in4, motorSpeed);
    }
    else if (inputvalue == 'B') { // Backward
      analogWrite(in1, LOW);
      analogWrite(in2, motorSpeed);
      analogWrite(in3, motorSpeed);
      analogWrite(in4, LOW);
    }
    else if (inputvalue == 'L') { // Left
      analogWrite(in1, LOW);
      analogWrite(in2, LOW);
      analogWrite(in3, LOW);
      analogWrite(in4, motorSpeed);
    }
    else if (inputvalue == 'R') { // Right
      analogWrite(in1, motorSpeed);
      analogWrite(in2, LOW);
      analogWrite(in3, LOW);
      analogWrite(in4, LOW);
    }
    // Add other movement directions and stop condition as needed...
    else if (inputvalue == 'S' || inputvalue == 'D') { // Stop
      analogWrite(in1, LOW);
      analogWrite(in2, LOW);
      analogWrite(in3, LOW);
      analogWrite(in4, LOW);
    }
    else { // Stop if input is invalid
      analogWrite(in1, LOW);
      analogWrite(in2, LOW);
      analogWrite(in3, LOW);
      analogWrite(in4, LOW);
    }
  }
}
