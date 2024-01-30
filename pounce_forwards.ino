#include <Servo.h>

int ser2 = 90+ 25; 
int ser3 = 90- 25; 
int ser4 = 90+ 25; 
int ser5 = 90- 25;
int ser6 = 90+ 25;
int ser7 = 90- 25; 
int ser8 = 90+ 25; 
int ser9 = 90- 25;

Servo servo1;
Servo servo2;
Servo servo3;
Servo servo4;
Servo servo5;
Servo servo6;
Servo servo7;
Servo servo8;
Servo servo9;

void setup() {
  Serial.begin(9600);

  servo1.attach(2);
  servo2.attach(3);
  servo3.attach(4);
  servo4.attach(5);
  servo5.attach(6);
  servo6.attach(7);
  servo7.attach(8);
  servo8.attach(9);

  // Set the initial position of the servos to "up default"
  servo1.write(ser2);
  servo2.write(ser3);
  servo3.write(ser4);
  servo4.write(ser5);
  servo5.write(ser6);
  servo6.write(ser7);
  servo7.write(ser8);
  servo8.write(ser9);

  delay(5500);
  Serial.println("Initialization complete");
}

void loop() {
  /*
  servo1.write(ser2 + 25);
  servo2.write(ser3 - 25);
  servo3.write(ser4 + 25);
  servo4.write(ser5 - 25);
  servo5.write(ser6 + 25);
  servo6.write(ser7 - 25);
  servo7.write(ser8 + 25);
  servo8.write(ser9 - 25);
  */
// Forward and right turn
// Forward movement (LF, RB, LB, RF)
// Backward movement (LB, RF, RB, LF)
servo1.write(ser2 - 20);  // lf B
servo2.write(ser3 - 40);  // lf B

servo3.write(ser4 + 20);  // lb B
servo4.write(ser5 + 40);  // lb B

servo5.write(ser6 + 20);  // rf B
servo6.write(ser7 + 40);  // rf B

servo7.write(ser8 - 20);  // rb B
servo8.write(ser9 - 40);  // rb B
delay(1000);
// Forward movement (LB, RF, RB, LF)
servo3.write(ser4 - 20);  // lb F
servo4.write(ser5 - 40);  // lb F

servo5.write(ser6 - 20);  // rf F
servo6.write(ser7 - 40);  // rf F
delay(100);
servo7.write(ser8 + 20);  // rb F
servo8.write(ser9 + 40);  // rb F

servo1.write(ser2 + 20);  // lf F
servo2.write(ser3 + 40);  // lf F


delay(1000);

  

  Serial.println("runnin");
}
