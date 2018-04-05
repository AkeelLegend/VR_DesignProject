#include<Wire.h>
const int MPU6050 = 0x68;
int16_t AcX, AcY, AcZ, Tmp, GyX, GyY, GyZ, velX, velY, velZ;
int data;

void setup() {
  // put your setup code here, to run once:
  Wire.begin();
  Wire.beginTransmission(MPU6050);
  Wire.write(0x6B);
  Wire.write(0);
  Wire.endTransmission(true);
  Serial.begin(115200);

}

void loop() {
  // put your main code here, to run repeatedly:
  GetMPU_Value();
  SetUniity();

}


void GetMPU_Value(){
  Wire.beginTransmission(MPU6050);
  Wire.write(0x3B); //accel address
  Wire.endTransmission(false);
  Wire.requestFrom(MPU6050, 14, true);

  AcX = Wire.read()<<8| Wire.read();
  AcY = Wire.read()<<8| Wire.read();
  AcZ = Wire.read()<<8| Wire.read();
  Tmp = Wire.read()<<8| Wire.read();
  GyX = Wire.read()<<8| Wire.read();
  GyY = Wire.read()<<8| Wire.read();
  GyZ = Wire.read()<<8| Wire.read();

  velX += (AcX/16384)*9.8*0.01;
  delay(10);
  velY += (AcY/16384)*9.8*0.01;
  delay(10);
  velZ += ((AcZ-16384)/16384)*9.8*0.01;
  delay(10);
}

void SetUniity(){
if (Serial.available()){
  
  data = Serial.read();
  
    if(data == 'a') Serial.println(velX);
    if(data == 'b') Serial.println(velY);
    if(data == 'c') Serial.println(velZ);
    if(data == 'd') Serial.println(GyX);
    if(data == 'e') Serial.println(GyY);
    if(data == 'f') Serial.println(GyZ);
  }  
} 
