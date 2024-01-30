#include <Servo.h>
#include <math.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,16,2);  // set the LCD address to 0x27 for a 16 chars and 2 line display

//LiquidCrystal lcd(13, 12, 11, 10, 9, 8); // Creates an LCD object. Parameters: (rs, enable, d4, d5, d6, d7) 
Servo servo1, servo2;
#define joyX A0
#define joyY A1
#define RIGHT_SERVO_PIN 9
#define LEFT_SERVO_PIN 10

 
int xValue=0;
int yValue=0;
int xmap =0;
int ymap =0;

 
void setup() {
  lcd.begin(16,2);
  Serial.begin(9600);
  servo1.attach(2); // Attach servo1 to pin 5
  servo2.attach(3); // Attach servo2 to pin 6
  //lcd.begin(16,2); // Initializes the interface to the LCD screen, and specifies the dimensions (width and height) of the display } 
  lcd.backlight();

}

void loop() {



  // read analog X and Y analog values
  xmap = analogRead(joyX);
  ymap = analogRead(joyY);

  int xValue = map(xmap, 0, 1023,(360/1.4),0);
  int yValue = map(ymap, 0, 1023,(360/1.4),0); 

  // print data to Serial Monitor on Arduino IDE
  /*
  Serial.print("x = ");
  Serial.print(xmap);
  Serial.print(", y = ");
  Serial.println(ymap);
  //delay(20);
  */
  servo1.writeMicroseconds(map(yValue, 0, (360/1.4), 500, 2500));
  servo2.writeMicroseconds(map(xValue, 0, (360/1.4), 500, 2500));
  lcd.setCursor(1, 0);  // Move cursor to the beginning of the first line

  lcd.print("SA");
  lcd.print(xValue);
  lcd.print(" xmp=");
  lcd.print(int(xmap));

  lcd.setCursor(1, 1);  // Move cursor to the beginning of the second line

  lcd.print("SB");
  lcd.print(yValue);
  lcd.print(" ymp=");
  lcd.print(int(ymap));

  delay(20);
  lcd.clear();





  
}
