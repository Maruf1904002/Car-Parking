#include <Servo.h>               // includes the servo library
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// LCD setup: address 0x27, 16 columns, 2 rows
LiquidCrystal_I2C lcd(0x27, 16, 2);
Servo myservo;

// IR sensor pins
#define ir_enter 2
#define ir_back 4
#define ir_car1 5
#define ir_car2 6
#define ir_car3 7
#define ir_car4 8

int S1 = 0, S2 = 0, S3 = 0, S4 = 0;
int flag1 = 0, flag2 = 0;
int slot = 4;

void setup() {
  Serial.begin(9600);

  pinMode(ir_car1, INPUT);
  pinMode(ir_car2, INPUT);
  pinMode(ir_car3, INPUT);
  pinMode(ir_car4, INPUT);
  pinMode(ir_enter, INPUT);
  pinMode(ir_back, INPUT);

  myservo.attach(3);
  myservo.write(90); // Default gate closed position

  lcd.begin(16, 2);
  lcd.setCursor(0, 1);
  lcd.print(" Car Parking");
  delay(2000);
  lcd.clear();

  Read_Sensor();
  int total = S1 + S2 + S3 + S4;
  slot = slot - total;
}

void loop() {
  Read_Sensor();

  lcd.setCursor(0, 0);
  lcd.print(" Have Slot: ");
  lcd.print(slot);

  lcd.setCursor(0, 1);
  if (S1 == 1) lcd.print("1:F ");
  else lcd.print("1:E ");

  lcd.setCursor(4, 1);
  if (S2 == 1) lcd.print("2:F ");
  else lcd.print("2:E ");

  lcd.setCursor(8, 1);
  if (S3 == 1) lcd.print("3:F ");
  else lcd.print("3:E ");

  lcd.setCursor(12, 1);
  if (S4 == 1) lcd.print("4:F ");
  else lcd.print("4:E ");

  // Entry logic
  if (digitalRead(ir_enter) == 0 && flag1 == 0) {
    if (slot > 0) {
      flag1 = 1;
      if (flag2 == 0) {
        myservo.write(180); // Open gate
        slot = slot - 1;
      }
    } else {
      lcd.setCursor(0, 0);
      lcd.print(" Sorry Parking Full ");
      delay(1500);
    }
  }

  // Exit logic
  if (digitalRead(ir_back) == 0 && flag2 == 0) {
    flag2 = 1;
    if (flag1 == 0) {
      myservo.write(180); // Open gate
      slot = slot + 1;
    }
  }

  // Reset and close gate
  if (flag1 == 1 && flag2 == 1) {
    delay(1000);
    myservo.write(90); // Close gate
    flag1 = 0;
    flag2 = 0;
  }

  delay(1);
}

void Read_Sensor() {
  S1 = 0;
  S2 = 0;
  S3 = 0;
  S4 = 0;

  if (digitalRead(ir_car1) == 0) S1 = 1;
  if (digitalRead(ir_car2) == 0) S2 = 1;
  if (digitalRead(ir_car3) == 0) S3 = 1;
  if (digitalRead(ir_car4) == 0) S4 = 1;
}
