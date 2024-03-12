#include "I2Cdev.h"
#include "MPU6050_6Axis_MotionApps20.h"
#include <PID_v1.h>
#if I2CDEV_IMPLEMENTATION == I2CDEV_ARDUINO_WIRE
#include "Wire.h"
#endif


MPU6050 mpu;
const int PACKET_SIZE = 8;

//motor control vars
int ena = 9;
int enb = 11;
int ina = 4;
int inb = 5;
int inc = 6;
int ind = 7;

//PID vars
double kp = 5;
double kd = 30;
double ki = 1;
float tempkp = 0;
float tempkd = 0;
float tempki = 0;
const int PID_MIN_LIMIT = -190;  //Min limit for PID
const int PID_MAX_LIMIT = 190;  //Max limit for PID
const int PID_SAMPLE_TIME_IN_MILLI = 10;

double setPoint = 0;
float error = 0;
float preverror = 0;
float pid_i_mem = 0;
double motorSpeed = 0;
double pitchGyroAngle = 0;

// MPU control/status vars
bool dmpReady = false; // set true if DMP init was successful
uint8_t mpuIntStatus; // holds actual interrupt status byte from MPU
uint8_t devStatus; // return status after each device operation (0 = success, !0 = error)
uint16_t packetSize; // expected DMP packet size (default is 42 bytes)
uint16_t fifoCount; // count of all bytes currently in FIFO
uint8_t fifoBuffer[64]; // FIFO storage buffer

// orientation/motion vars
Quaternion q; // [w, x, y, z] quaternion container
VectorFloat gravity; // [x, y, z] gravity vector
float ypr[3]; // [yaw, pitch, roll] yaw/pitch/roll container and gravity vector

volatile bool mpuInterrupt = false; // indicates whether MPU interrupt pin has gone high
float input;
PID pitchPID(&pitchGyroAngle, &motorSpeed, &setPoint, kp, ki, kd, DIRECT);
int interrupt_pin = 2;

void dmpDataReady()
{
  mpuInterrupt = true;
}
void setupPID()
{
  pitchPID.SetOutputLimits(PID_MIN_LIMIT, PID_MAX_LIMIT);
  pitchPID.SetMode(AUTOMATIC);
  pitchPID.SetSampleTime(PID_SAMPLE_TIME_IN_MILLI);
}
void setMotors()
{
  pinMode(ena, OUTPUT);
  pinMode(enb, OUTPUT);
  pinMode(ina, OUTPUT);
  pinMode(inb, OUTPUT);
  pinMode(inc, OUTPUT);
  pinMode(ind, OUTPUT);

  digitalWrite(ena, LOW);
  digitalWrite(enb, LOW);
  digitalWrite(ina, LOW);
  digitalWrite(inb, LOW);
  digitalWrite(inc, LOW);
  digitalWrite(ind, LOW);
}
void setupMPU()
{
  // join I2C bus (I2Cdev library doesn't do this automatically)
#if I2CDEV_IMPLEMENTATION == I2CDEV_ARDUINO_WIRE
  Serial.begin(9600);
  Wire.begin();
  TWBR = 24; // 400kHz I2C clock (200kHz if CPU is 8MHz)
#elif I2CDEV_IMPLEMENTATION == I2CDEV_BUILTIN_FASTWIRE
  Fastwire::setup(400, true);
#endif

  mpu.initialize();

  devStatus = mpu.dmpInitialize();

  mpu.setXGyroOffset(220);
  mpu.setYGyroOffset(76);
  mpu.setZGyroOffset(-85);
  mpu.setZAccelOffset(1788);

  // make sure it worked (returns 0 if so)
  if (devStatus == 0)
  {
    // Calibration Time: generate offsets and calibrate our MPU6050
    mpu.CalibrateAccel(6);
    mpu.CalibrateGyro(6);
    mpu.PrintActiveOffsets();
    // turn on the DMP, now that it's ready
    mpu.setDMPEnabled(true);

    // enable Arduino interrupt detection
    attachInterrupt(digitalPinToInterrupt(interrupt_pin), dmpDataReady, RISING);
    mpuIntStatus = mpu.getIntStatus();

    // set our DMP Ready flag so the main loop() function knows it's okay to use it
    dmpReady = true;

    // get expected DMP packet size for later comparison
    packetSize = mpu.dmpGetFIFOPacketSize();
    Serial.println(packetSize);
  }
  else
  {
    // ERROR!
    // 1 = initial memory load failed
    // 2 = DMP configuration updates failed
    // (if it's going to break, usually the code will be 1)
    Serial.print(F("DMP Initialization failed (code "));
    Serial.print(devStatus);
    Serial.println(F(")"));
  }
}
void setup()
{
  //This is to set up motors
  setMotors();   
  //This is to set up MPU6050 sensor
  setupMPU();
  //This is to set up PID 
  setupPID();
}


void loop()
{
  // if programming failed, don't try to do anything
  if (!dmpReady) return;

  // wait for MPU interrupt or extra packet(s) available
  if (Serial.available())
  {
    while (Serial.available())
      handleSerial(Serial.peek());
  }
  while (!mpuInterrupt && fifoCount < packetSize)
  {
    //calculate PID from here
    pitchPID.Compute(true);
    motorDrive(motorSpeed);
  }

  // reset interrupt flag and get INT_STATUS byte
  mpuInterrupt = false;
  mpuIntStatus = mpu.getIntStatus();

  // get current FIFO count
  fifoCount = mpu.getFIFOCount();

  // check for overflow (this should never happen unless our code is too inefficient)
  if ((mpuIntStatus & 0x10) || fifoCount == 1024)
  {
    // reset so we can continue cleanly
    mpu.resetFIFO();
    Serial.println(F("FIFO overflow!"));

    // otherwise, check for DMP data ready interrupt (this should happen frequently)
  }
  else if (mpuIntStatus & 0x02)
  {
    // wait for correct available data length, should be a VERY short wait
    while (fifoCount < packetSize) fifoCount = mpu.getFIFOCount();

    // read a packet from FIFO
    mpu.getFIFOBytes(fifoBuffer, packetSize);

    // track FIFO count here in case there is > 1 packet available
    // (this lets us immediately read more without waiting for an interrupt)
    fifoCount -= packetSize;

    mpu.dmpGetQuaternion(&q, fifoBuffer);
    mpu.dmpGetGravity(&gravity, &q);
    mpu.dmpGetYawPitchRoll(ypr, &q, &gravity);
    pitchGyroAngle = ypr[1] * 180 / M_PI;
  }
}
void motorDrive(int motorSpeed)
{
//  if (motorSpeed == 0)
//  {
//    digitalWrite(ina, LOW);
//    digitalWrite(inb, LOW);
//    digitalWrite(inc, LOW);
//    digitalWrite(ind, LOW);
//  }
  if (motorSpeed >= 0)
  {
    digitalWrite(ina, HIGH);
    digitalWrite(inb, LOW);
    digitalWrite(inc, LOW);
    digitalWrite(ind, HIGH);
  }
  if (motorSpeed < 0)
  {
    digitalWrite(ina, LOW);
    digitalWrite(inb, HIGH);
    digitalWrite(inc, HIGH);
    digitalWrite(ind, LOW);
  }
  if(abs(motorSpeed)>PID_MAX_LIMIT)
  {
    motorSpeed = PID_MAX_LIMIT;
  }
  motorSpeed = abs(motorSpeed);
  //Serial.println(motorSpeed);
  analogWrite(ena,motorSpeed);
  analogWrite(enb,motorSpeed);    
}
void handleSerial(char c)
{
  switch (c)
  {
    case 'P':
      {
        if (Serial.available() < PACKET_SIZE)
          break;
        tempkp = Serial.parseFloat();
        if (Serial.read() == 13)
        {
          if (Serial.read() == 10)
          {
            //Use kp value from here
            kp = tempkp;
            pitchPID.SetTunings(kp, ki, kd);
            Serial.print("KP: ");
            Serial.println(kp);
          }
          else
            clearSerialBuffer();
        }
        else
          clearSerialBuffer();
      } break;
    case 'D':
      {
        if (Serial.available() < PACKET_SIZE)
          break;
        tempkd = Serial.parseFloat();
        if (Serial.read() == 13)
        {
          if (Serial.read() == 10)
          {
            //Use kd value from here
            kd = tempkd;
            pitchPID.SetTunings(kp, ki, kd);
            Serial.print("KD: ");
            Serial.println(kd);
          }
          else
            clearSerialBuffer();
        }
        else
          clearSerialBuffer();
      } break;
    case 'I':
      {
        if (Serial.available() < PACKET_SIZE)
          break;
        tempki = Serial.parseFloat();
        if (Serial.read() == 13)
        {
          if (Serial.read() == 10)
          {
            //Use ki value from here
            ki = tempki;
            pitchPID.SetTunings(kp, ki, kd);
            Serial.print("KI: ");
            Serial.println(ki);
          }
          else
            clearSerialBuffer();
        }
        else
          clearSerialBuffer();
      } break;
    default:
      clearSerialBuffer();
      break;
  }
}
void clearSerialBuffer()
{
  while (Serial.available())
    Serial.read();
}
