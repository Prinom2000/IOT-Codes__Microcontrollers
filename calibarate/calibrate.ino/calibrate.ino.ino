#include<Servo.h>

Servo s0;
Servo s1;
Servo s2;
Servo s3;
Servo s4;
Servo s5;
Servo s6;

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


  Serial.begin(9600); // starts the serial communication with Bluetooth module

  s2.write(90);
  s5.write(90);
  s0.write(0);


}

void loop() {


  if (Serial.available() > 0) {
    char inputvalue = char(Serial.read());
    Serial.println(inputvalue);
    if (inputvalue == 'k') {  //walk
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

    }
    else if (inputvalue == 'i') {  //hi
      
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
      // s0.write(90);
      // delay(250);
      s0.write(180);
      // delay(250);
      // s0.write(90);

      s0.write(0);
      delay(250);
      // s0.write(90);
      // delay(250);
      s0.write(180);
      delay(250);
      // s0.write(90);

      s0.write(0);
      delay(250);
      // s0.write(90);
      // delay(250);
      s0.write(180);
      delay(250);
      s0.write(90);
    }

    else if (inputvalue == 'o') {  //no
      
      s1.write(0);
      
    }
    
    delay(15);           // waits for the servo to reach the position
  }
}
