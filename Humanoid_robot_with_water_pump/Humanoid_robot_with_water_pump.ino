#include <Servo.h>

Servo s0;
Servo s1;
Servo s2;
Servo s3;
Servo s4;
Servo s5;
Servo s6;

const int relayPin = 9;  // Pin to control the relay for the water pump


void setup() {
  s0.attach(8);
  s0.write(90);

  s1.attach(2);
  s1.write(60);

  s2.attach(3);
  s2.write(180);

  s3.attach(4);
  s3.write(0);

  s4.attach(5);
  s4.write(120);

  s5.attach(6);
  s5.write(0);

  s6.attach(7);
  s6.write(180);

  // Initialize the relay pin
  pinMode(relayPin, OUTPUT);
  digitalWrite(relayPin, HIGH);  // Start with the water pump off


  Serial.begin(9600);  // starts the serial communication with Bluetooth module
}

void loop() {


  if (Serial.available() > 0) {
    char inputvalue = char(Serial.read());
    Serial.println(inputvalue);

    if (inputvalue == 'y') {  // Turn water pump ON
        
          digitalWrite(relayPin, LOW);
          delay(8000);
          digitalWrite(relayPin, HIGH); 

    } 
    // else if (inputvalue == 'z') {  // Turn water pump OFF
    //   digitalWrite(relayPin, HIGH);   // Relay off
    // }
    else if (inputvalue == 'l') {  //walk
      s1.write(120);
      s4.write(180);
      delay(250);
      s1.write(0);
      s4.write(60);
      delay(250);

      s1.write(120);
      s4.write(180);
      delay(250);
      s1.write(0);
      s4.write(60);
      delay(250);

      s1.write(120);
      s4.write(180);
      delay(250);
      s1.write(0);
      s4.write(60);
      delay(250);

      s1.write(120);
      s4.write(180);
      delay(250);
      s1.write(0);
      s4.write(60);
      delay(250);

      s1.write(120);
      s4.write(180);
      delay(250);
      s1.write(0);
      s4.write(60);
      delay(250);

      s1.write(120);
      s4.write(180);
      delay(250);
      s1.write(0);
      s4.write(60);
      delay(250);

      s1.write(120);
      s4.write(180);
      delay(250);
      s1.write(0);
      s4.write(60);
      delay(250);

      s1.write(120);
      s4.write(180);
      delay(250);
      s1.write(0);
      s4.write(60);
      delay(250);

      s1.write(120);
      s4.write(180);
      delay(250);
      s1.write(0);
      s4.write(60);
      delay(250);

      s1.write(60);
      s4.write(120);

    } else if (inputvalue == 'i') {  //hi

      s5.write(180);
      delay(250);
      s5.write(90);
      delay(250);
      s5.write(180);
      delay(250);
      s5.write(90);
      delay(250);
      s5.write(180);
      delay(250);
      s5.write(90);
      delay(250);
      s5.write(180);
      delay(250);
      s5.write(90);
      delay(250);
      s5.write(180);
      delay(250);
      s5.write(90);
      delay(250);
      s5.write(180);
      delay(250);
      s5.write(0);
    }

    else if (inputvalue == 'n') {  //no

      s0.write(0);
      delay(250);
      s0.write(180);
      s0.write(0);
      delay(250);
      s0.write(180);
      delay(250);
      s0.write(0);
      delay(250);
      s0.write(180);
      delay(250);
      s0.write(90);
    }

    else if (inputvalue == 'e') {  //come

      s1.write(180);
      delay(250);
      s3.write(180);
      delay(250);
      s3.write(0);
      delay(250);
      s3.write(180);
      delay(250);
      s3.write(0);
      delay(250);
      s3.write(180);
      delay(250);
      s3.write(0);
      delay(250);
      s3.write(180);
      delay(250);
      s3.write(0);
      delay(250);
      s3.write(180);
      delay(250);
      s3.write(0);
      delay(250);

      s1.write(60);

    }

    else if (inputvalue == 'p') {  //up
      s1.write(180);
      delay(250);
      s4.write(0);
      delay(250);
      s3.write(90);
      delay(250);
      s6.write(90);

      delay(6000);

      s1.write(60);
      delay(250);
      s4.write(120);
      delay(250);
      s3.write(0);
      delay(250);
      s6.write(180);
      delay(250);
    }


    else if (inputvalue == 'x') {  // Initioal positon
      s0.write(90);
      delay(250);
      s1.write(60);
      delay(250);

      s2.write(180);
      delay(250);
      s3.write(0);
      delay(250);
      s4.write(120);
      delay(250);
      s5.write(0);
      delay(250);
      s6.write(180);
      delay(250);
    }

    else if (inputvalue == 'd' || inputvalue == 'D') {  // dance
      s2.write(90);
      delay(100);
      s5.write(90);
      delay(500);

      s0.write(0);
      delay(100);
      s3.write(180);
      delay(150);
      s3.write(0);
      delay(150);
      s3.write(180);
      delay(150);
      s3.write(0);
      delay(150);
      s3.write(180);
      delay(150);
      s3.write(0);
      delay(150);
      s3.write(180);
      delay(150);
      s3.write(0);
      delay(150);
      s3.write(180);
      delay(150);
      s3.write(0);
      delay(150);

      s0.write(180);
      delay(100);
      s6.write(0);
      delay(150);
      s6.write(180);
      delay(150);
      s6.write(0);
      delay(150);
      s6.write(180);
      delay(150);
      s6.write(0);
      delay(150);
      s6.write(180);
      delay(150);
      s6.write(0);
      delay(150);
      s6.write(180);
      delay(150);
      s6.write(0);
      delay(150);
      s6.write(180);
      delay(150);

      //chat gpt
      // Neck movement side to side
s0.write(45);     // Neck to the left
delay(200);
s0.write(135);    // Neck to the right
delay(200);
s0.write(45);     // Neck to the left
delay(200);
s0.write(135);    // Neck to the right
delay(200);
s0.write(90);     // Center the neck
delay(200);

// Right hand wave
s3.write(180);    // Right hand up
delay(150);
s3.write(0);      // Right hand down
delay(150);
s3.write(180);    // Right hand up
delay(150);
s3.write(0);      // Right hand down
delay(150);
s3.write(180);    // Right hand up
delay(150);
s3.write(0);      // Right hand down
delay(150);

// Shoulders move up and down in sync
s1.write(45);     // Right shoulder up
s4.write(135);    // Left shoulder up
delay(300);
s1.write(90);     // Right shoulder down
s4.write(90);     // Left shoulder down
delay(300);
s1.write(45);     // Right shoulder up
s4.write(135);    // Left shoulder up
delay(300);
s1.write(90);     // Right shoulder down
s4.write(90);     // Left shoulder down
delay(300);
s1.write(45);     // Right shoulder up
s4.write(135);    // Left shoulder up
delay(300);
s1.write(90);     // Right shoulder down
s4.write(90);     // Left shoulder down
delay(300);

// Clap hands
s3.write(90);     // Move right hand to center
s6.write(90);     // Move left hand to center
delay(300);
s3.write(0);      // Right hand back
s6.write(180);    // Left hand back
delay(300);
s3.write(90);     // Move right hand to center
s6.write(90);     // Move left hand to center
delay(300);
s3.write(0);      // Right hand back
s6.write(180);    // Left hand back
delay(300);
s3.write(90);     // Move right hand to center
s6.write(90);     // Move left hand to center
delay(300);
s3.write(0);      // Right hand back
s6.write(180);    // Left hand back
delay(300);

// Elbow twist
s2.write(0);      // Right elbow straight
s5.write(180);    // Left elbow bent
delay(300);
s2.write(90);     // Right elbow bent
s5.write(90);     // Left elbow straight
delay(300);
s2.write(0);      // Right elbow straight
s5.write(180);    // Left elbow bent
delay(300);
s2.write(90);     // Right elbow bent
s5.write(90);     // Left elbow straight
delay(300);
s2.write(0);      // Right elbow straight
s5.write(180);    // Left elbow bent
delay(300);
s2.write(90);     // Right elbow bent
s5.write(90);     // Left elbow straight
delay(300);


      //////////////////
      s0.write(90);
      delay(250);
      s1.write(60);
      delay(250);

      s2.write(180);
      delay(250);
      s3.write(0);
      delay(250);
      s4.write(120);
      delay(250);
      s5.write(0);
      delay(250);
      s6.write(180);
      delay(250);
    }

    delay(15);  // waits for the servo to reach the position
  }
}
