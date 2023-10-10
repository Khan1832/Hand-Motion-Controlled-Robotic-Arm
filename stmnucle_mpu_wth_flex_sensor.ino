#include "Wire.h"
#include "MPU6050_A.h"
#include<Servo.h>               //Servo Motor Library

#define FLEXSENSOR1   A0
#define FLEXSENSOR2   A1
#define LED            7

int angleflex1;
int angleflex2;
int angleX;
int angleY;
int angleZ;
int mapflex1;
int mapflex2;

Servo servo_1;
Servo servo_2;
Servo servo_3;
Servo servo_4;
Servo servo_5;

MPU6050 mpu(Wire);
unsigned long timer = 0;



void setup() {
  Serial.begin(9600);
  Wire.begin();
  pinMode(FLEXSENSOR1, INPUT);
  pinMode(FLEXSENSOR2, INPUT);
  pinMode(LED, OUTPUT);
  digitalWrite(LED,HIGH);  
  servo_1.attach(3);   // Forward/Reverse_Motor
  servo_2.attach(5);   // Up/Down_Motor
  servo_3.attach(6);   // Gripper_Motor
  servo_4.attach(9);   // Left/Right_Motor
  servo_5.attach(10);   // Left/Right_Mot
  servo_1.write(160);
  servo_2.write(90);
  servo_3.write(120);
  servo_4.write(60);
   servo_5.write(30);
  delay(1000);
  byte status = mpu.begin();
  Serial.print(F("MPU6050 status: "));
  Serial.println(status);
  while (status != 0) { } // stop everything if could not connect to MPU6050

  Serial.println(F("Calculating offsets, do not move MPU6050"));
  delay(1000);
  // mpu.upsideDownMounting = true; // uncomment this line if the MPU6050 is mounted upside-down
  mpu.calcOffsets(); // gyro and accelero
  Serial.println("Done!\n");
delay(1000);
 digitalWrite(LED,LOW);
}

void loop() {
  mpuSensor(); delay(50);
  // flexSensor();delay(50);
  control();
}

void mpuSensor() {
  mpu.update();
  angleflex1 = analogRead(FLEXSENSOR1);
  mapflex1 = map(angleflex1, 0, 250, 90, 0);
  angleflex2 = analogRead(FLEXSENSOR2);
  mapflex2 = map(angleflex2, 0, 300, 90, 0);
  if ((millis() - timer) > 10) { // print data every 10ms
    Serial.print("X : ");
    angleX = (mpu.getAngleX());
    Serial.print( angleX);
    Serial.print("\tY : ");
    angleY = (mpu.getAngleY());
    Serial.print( angleY);
    Serial.print( "\tZ : ");
    angleZ = (mpu.getAngleZ());
    Serial.print( angleZ);
    Serial.print("\ta : ");
    Serial.print( mapflex1);
    Serial.print("\tb : ");
    Serial.println(mapflex2);
    timer = millis();
  }
}


void control() {
         
  if (mapflex1 > 25)
  {
    //gripper = 180;
    //servo_5.write(mapflex1); 
   servo_5.write(180); 
  }
  else
  {
    //gripper = 0;
   servo_5.write(30); 
  }

  
  
   if((mapflex2 > 20) && (mapflex2 < 30))
  {
    
   servo_4.write(180); 
  }
  
   else if((mapflex2 > 30) && (mapflex2  < 50))
  {
 
   servo_4.write(0); 
  }
  else
  {
    //gripper = 0;
   servo_4.write(90); 
  
  }
  
  
  if (angleX >= -60 && angleX <= 0)
  {
    int mov1 = map(angleX,-60,0, 180, 90);
    //    Serial.print("Movement in F/R = ");
    //  Serial.print(mov2);
    // Serial.println((char)176);
    servo_3.write(mov1);
  }

  if (angleY >= 0 && angleY <= 60)
  {
    int mov2 = map(angleY, 0, 60, 90, 0);
    //Serial.print("Movement in Left = ");
    //Serial.print(mov3);
    //Serial.println((char)176);
    servo_2.write(mov2);

  }  

  if (angleZ >= 0 && angleZ <= 60)
  {
    int mov3 = map(angleZ, 0, 60, 160, 0);
    //Serial.print("Movement in Left = ");
    //Serial.print(mov4);
    //Serial.println((char)176);
    servo_1.write(mov3);
  }





}
