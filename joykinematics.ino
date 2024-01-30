#include <Servo.h>
#include <math.h>
Servo servo1, servo2;
#define joyX A0
#define joyY A1
#define RIGHT_SERVO_PIN 9
#define LEFT_SERVO_PIN 10

 
int xValue=0.0000000001;
int yValue=0.0000000001;
int xmap =0.0000000001;
int ymap =0.0000000001;

 
void setup() {
  Serial.begin(9600);
  servo1.attach(2); // Attach servo1 to pin 5
  servo2.attach(3); // Attach servo2 to pin 6

}

void loop() {

  // read analog X and Y analog values
  xmap = analogRead(joyX);
  ymap = analogRead(joyY);

  int xValue = map(xmap, 0, 1023,360,0);
  int yValue = map(ymap, 0, 1023,360,0); 

  // print data to Serial Monitor on Arduino IDE
  Serial.print("x = ");
  Serial.print(xValue);
  Serial.print(", y = ");
  Serial.println(yValue);
  delay(20);
  servo1.writeMicroseconds(map(yValue, 0, (360/1.4), 500, 2500));
  servo2.writeMicroseconds(map(xValue, 0, (360/1.4), 500, 2500));
  
}
