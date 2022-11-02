const int MOTOR_EN = 21;
const int MOIST_IN = A6;
const int MAX_ANALOG_VAL = 4095;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  
  pinMode(MOTOR_EN,OUTPUT);
  pinMode(MOIST_IN,INPUT);
  
}

void loop() {
  // put your main code here, to run repeatedly:
  int moistVal = analogRead(MOIST_IN);

  digitalWrite(MOTOR_EN,HIGH);
  delay(10000);
  digitalWrite(MOTOR_EN,LOW);
  delay(10000);

  Serial.println((String)moistVal);
}
