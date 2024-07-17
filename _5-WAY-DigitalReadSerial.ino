#define leftMotor1 2  
#define leftMotor2 3
#define rightMotor1 6
#define rightMotor2 7

int IRSensor1 = A0; 
int IRSensor2 = A1;  
int IRSensor3 = A2;
int IRSensor4 = A3;
int IRSensor5 = A4;
 
void setup() {
  
  pinMode(leftMotor1, OUTPUT);
  pinMode(leftMotor2, OUTPUT); 
  pinMode(rightMotor1, OUTPUT);
  pinMode(rightMotor2, OUTPUT);
  
  // Initialize IR sensor pins as inputs
  pinMode(IRSensor1, INPUT);
  pinMode(IRSensor2, INPUT);
  pinMode(IRSensor3, INPUT);  
  pinMode(IRSensor4, INPUT);
  pinMode(IRSensor5, INPUT);  
}

void loop() {

  // Read values from all IR sensors  
  int sensor1 = digitalRead(IRSensor1);
  int sensor2 = digitalRead(IRSensor2);
  int sensor3 = digitalRead(IRSensor3);
  int sensor4 = digitalRead(IRSensor4);
  int sensor5 = digitalRead(IRSensor5);
  
  // Control motors based on sensor values
  if(sensor1 == 1 && sensor2 == 0 && sensor3 == 0 && sensor4 == 0 && sensor5 == 1) 
    forward();
  else if(sensor1 == 0 && sensor2 == 1 && sensor3 == 0 && sensor4 == 1 && sensor5 == 0)  
    slightRight();
  else if(sensor1 == 0 && sensor2 == 0 && sensor3 == 1 && sensor4 == 0 && sensor5 == 0)  
    sharpRight();
  else if(sensor1 == 0 && sensor2 == 1 && sensor3 == 1 && sensor4 == 0 && sensor5 == 0)
    left();
  else if(sensor1 == 0 && sensor2 == 0 && sensor3 == 0 && sensor4 == 1 && sensor5 == 0)   
    slightLeft();
  else if(sensor1 == 1 && sensor2 == 1 && sensor3 == 1 && sensor4 == 1 && sensor5 == 1)  
    stopRobot(); 
}

void forward() {
   digitalWrite(leftMotor1, HIGH);
   digitalWrite(leftMotor2 , LOW);  
   digitalWrite(rightMotor1, HIGH);
   digitalWrite(rightMotor2, LOW);
}

void slightRight() {
  digitalWrite(leftMotor1, HIGH);
  digitalWrite(leftMotor2, LOW);  
  digitalWrite(rightMotor1, LOW);
  digitalWrite(rightMotor2, LOW);  
}

void slightLeft() {
  digitalWrite(leftMotor1, LOW);
  digitalWrite(leftMotor2, LOW);
  digitalWrite(rightMotor1, HIGH);  
  digitalWrite(rightMotor2, LOW);
}

void sharpRight() {
   digitalWrite(leftMotor1, HIGH);
   digitalWrite(leftMotor2, LOW); 
   digitalWrite(rightMotor1, LOW);
   digitalWrite(rightMotor2, HIGH);   
}

void left() {
   digitalWrite(leftMotor1, LOW);
   digitalWrite(leftMotor2, HIGH);  
   digitalWrite(rightMotor1, HIGH);
   digitalWrite(rightMotor2, LOW);  
}

void stopRobot() {
   digitalWrite(leftMotor1, LOW);
   digitalWrite(leftMotor2, LOW);
   digitalWrite(rightMotor1, LOW);
   digitalWrite(rightMotor2, LOW);
}