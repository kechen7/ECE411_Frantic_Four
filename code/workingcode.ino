#include <LiquidCrystal_I2C.h>

const int MOTOR_EN = A0; //pin for the pump
const int MOIST_IN = A1; //pin for the sensor
const int MAX_ANALOG_VAL = 4095;
#define LED 27 

LiquidCrystal_I2C lcd(0x27,16,2);  // set the LCD address to 0x3F for a 16 chars and 2 line display

void setup() {
  // put your setup code here, to run once:

  Serial.begin(9600);
  
  lcd.init();
  lcd.clear();         
  lcd.backlight();      // Make sure backlight is on
  pinMode(LED, OUTPUT);

  pinMode(MOTOR_EN,OUTPUT);
  pinMode(MOIST_IN,INPUT);
  digitalWrite(MOTOR_EN, HIGH);
  delay(5000);
  
}

void loop(){


  // put your main code here, to run repeatedly:
  int moistVal = analogRead(MOIST_IN);
  //moistVal = map(moistVal, 550,10,0,100);
  Serial.print("\nMoisture level: \n"); 
  Serial.print(moistVal);

  if(moistVal > 287){
  lcd.clear();
  lcd.setCursor(2,0);
  lcd.print("Watering.. ");
  lcd.setCursor(2,1);
  lcd.print(moistVal);
  
  digitalWrite(MOTOR_EN,HIGH);
  digitalWrite(LED, HIGH);
  delay(5000); // water 5seconds
  lcd.clear();         
  digitalWrite(MOTOR_EN,LOW);
  digitalWrite(LED, LOW);
  lcd.setCursor(2,0);   //Set cursor to character 2 on line 0
  lcd.print("Done");
 

  }
else{
  lcd.clear();
  lcd.setCursor(2,0);   //Set cursor to character 2 on line 0
  lcd.print("Soil is dry");
  digitalWrite(LED, LOW);
  delay(5000);
  lcd.clear();
  delay(1000);
  // Print a message on both lines of the LCD.
  lcd.setCursor(2,0);   //Set cursor to character 2 on line 0
  lcd.print(moistVal);
  }

  delay(2000);
}