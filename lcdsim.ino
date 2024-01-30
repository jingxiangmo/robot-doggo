#include <Servo.h>
#include <math.h>
#include <LiquidCrystal.h>

#define joyX A0
#define joyY A1
// Servo objects
Servo servoLeft;
Servo servoRight;

LiquidCrystal lcd(12,11,5,4,3,2);

// Dimensions
const float l1 = 32.0;
const float l2 = 72.0;


// Coordinates of the foot relative to the hip
float a = -1.3;
float b = -90.0;
float xmap = 0;
float ymap = 0;

void setup() {
  Serial.begin(9600);
  // Attach servo pins
  servoLeft.attach(2);  // Change the pin numbers accordingly
  servoRight.attach(3);
  lcd.begin(16, 2);

  // Initialize the servos to initial positions
  moveToPosition(0, 0);
}

void loop() {
  xmap = analogRead(joyX);
  ymap = analogRead(joyY);
  // Update coordinates of the foot (you can use sensor inputs here)
  a = map(xmap, 0, 1023,-100,100);  // Example values, update as needed
  b = map(ymap, 0, 1023,-100,100);

  // Calculate angles
  float d = sqrt(a*a + b*b);
  float thetaA = acos((l1*l1 + d*d - l2*l2) / (2 * l1 * d));
  float thetaL = acos(2*b*b / abs(2*b*d)) * (a < 0 ? -1.f : 1.f);
  
  // Calculate servo angles
  float theta0 = thetaA + thetaL - radians(90);
  float theta01 = thetaA - thetaL - radians(90);

  // Move servos to new positions
  moveToPosition(theta0, theta01);
  lcd.setCursor(0,0);
  lcd.print("0 ");
  lcd.print(theta0);
  lcd.print(" a");
  lcd.print(a);
  lcd.setCursor(0,1);
  lcd.print("1 ");
  lcd.print(theta01);
  lcd.print(" b");
  lcd.print(b);


  // Add a delay if needed
  delay(100);
  lcd.clear();

}

// Function to move servos to specified angles
void moveToPosition(float angleLeft, float angleRight) {
  // Convert angles to degrees
  int posLeft = degrees(angleLeft);
  int posRight = degrees(angleRight);

  // Set servo positions
  servoLeft.write(posLeft);
  servoRight.write(posRight);
  Serial.print("x = ");
  Serial.print(posLeft);
  Serial.print(", y = ");
  Serial.println(posRight);
  
}
