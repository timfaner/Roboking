#include <PS4BT.h>
#include <usbhub.h>
//#include <Servo.h>
// Satisfy the IDE, which needs to see the include statment in the ino too.
#ifdef dobogusinclude
#include <spi4teensy3.h>
#include <SPI.h>
#endif
#include <math.h>
//Servo servoz;
//Servo servox;
USB Usb;
//USBHub Hub1(&Usb); // Some dongles have a hub inside
BTD Btd(&Usb); // You have to create the Bluetooth Dongle instance like so

/* You can create the instance of the PS4BT class in two ways */
// This will start an inquiry and then pair with the PS4 controller - you only have to do this once
// You will need to hold down the PS and Share button at the same time, the PS4 controller will then start to blink rapidly indicating that it is in pairing mode
PS4BT PS4(&Btd, PAIR);
char state;
//int posz=90;
//int posx=0;
void setup() {
  //servoz.attach(pinservoz);
  //servox.attach(pinservox);
  //servoz.write(posz);
  //servox.write(posx);
  pinMode(motor1pin, OUTPUT); //PWM
  pinMode(motor1pwm, OUTPUT);
  pinMode(motor1pin + 1, OUTPUT);
  pinMode(motor2pin, OUTPUT); //PWM
  pinMode(motor2pwm, OUTPUT);
  pinMode(motor2pin + 1, OUTPUT);
  pinMode(motor3pin, OUTPUT); //PWM
  pinMode(motor3pwm, OUTPUT);
  pinMode(motor3pin + 1, OUTPUT);
  pinMode(motor4pin, OUTPUT); //PWM
  pinMode(motor4pwm, OUTPUT);
  pinMode(motor4pin + 1, OUTPUT);
  pinMode(armpin, OUTPUT);
  pinMode(armpin + 1, OUTPUT);
  pinMode(armpwm, OUTPUT);
  Serial.begin(115200);
#if !defined(__MIPSEL__)
  while (!Serial); // Wait for serial port to connect - used on Leonardo, Teensy and other boards with built-in USB CDC serial connection
#endif
  if (Usb.Init() == -1) {
    Serial.print(F("\r\nOSC did not start"));
    while (1); // Halt
  }
  Serial.print(F("\r\nPS4 USB Library Started"));
}



int l, yh, xh;
int i = 0;
void loop() {
  Usb.Task();
  //if (i % 90 == 0)
  // Serial.println("ha");

  if (PS4.connected()) {
    l = PS4.getAnalogHat(RightHatX);
    yh = PS4.getAnalogHat(LeftHatX);
    xh = PS4.getAnalogHat(LeftHatY);
    //PS4.setRumbleOn(xh, yh);
    long pos = sqrt((xh - 128) * (xh - 128) + (yh - 128) * (yh - 128));

    if (int m = PS4.getAnalogButton(L2))
      motor(armpin, armpwm, 2, m);
    if (int m = PS4.getAnalogButton(R2))
      motor(armpin, armpwm, 1, m);

    if (PS4.getButtonClick(PS)) {
      Serial.print(F("\r\nPS"));
      PS4.disconnect();
    }
    if (PS4.getButtonClick(CROSS)) {
      m_stop();
      state = !state;
    }
    if (state) PS4.setLedFlash(10, 10);
    else PS4.setLedFlash(1000, 1000);

    if (l < 116) {
      int val = (116 - l) * 1.5;
      m_turnni(val);
    }
    else if (l > 138) {
      int val = (l - 138) * 1.5;
      m_turnshun(val);
    }
    l = 0;


    if (xh > 128 && yh < 128 && pos >= 10) {
      float vx = (xh - 128) * 2;
      float vy = (128 - yh) * 2;
      float a = atan(vy / vx);
      float v = sqrt(vx * vx + vy * vy);
      if (a > 45) {
        float v12 = abs(v * cos(a - 45));
        float v34 = abs(v * sin(a - 45));
        motor(motor1pin, motor1pwm, 2, v12);
        motor(motor2pin, motor2pwm, 2, v12);
        motor(motor3pin, motor3pwm, 1, v34);
        motor(motor4pin, motor4pwm, 1, v34);
        //daying(v12, v34);
      }
      if (a < 45) {
        float v12 = abs(v * cos(45 - a));
        float v34 = abs(v * sin(45 - a));
        motor(motor1pin, motor1pwm, 2, v12);
        motor(motor2pin, motor2pwm, 2, v12);
        motor(motor3pin, motor3pwm, 2, v34);
        motor(motor4pin, motor4pwm, 2, v34);
        //daying(v12, v34);
      }
    }

    else if (xh > 128 && yh > 128 && pos >= 10) {
      float vx = (xh - 128) * 2;
      float vy = (yh - 128) * 2;
      float a = atan(vy / vx);
      float v = sqrt(vx * vx + vy * vy);
      if (a > 45) {
        float v34 = abs(v * cos(a - 45));
        float v12 = abs(v * sin(a - 45));
        motor(motor1pin, motor1pwm, 1, v12);
        motor(motor2pin, motor2pwm, 1, v12);
        motor(motor3pin, motor3pwm, 2, v34);
        motor(motor4pin, motor4pwm, 2, v34);
        //daying(v12, v34);
      }
      if (a < 45) {
        float v34 = abs(v * cos(45 - a));
        float v12 = abs(v * sin(45 - a));
        motor(motor1pin, motor1pwm, 2, v12);
        motor(motor2pin, motor2pwm, 2, v12);
        motor(motor3pin, motor3pwm, 2, v34);
        motor(motor4pin, motor4pwm, 2, v34);
        //daying(v12, v34);
      }
    }

    else if (xh < 128 && yh > 128 && pos >= 10) {
      float vx = (128 - xh) * 2;
      float vy = (yh - 128) * 2;
      float a = atan(vy / vx);
      float v = sqrt(vx * vx + vy * vy);
      if (a > 45) {
        float v12 = abs(v * cos(a - 45));
        float v34 = abs(v * sin(a - 45));
        motor(motor1pin, motor1pwm, 1, v12);
        motor(motor2pin, motor2pwm, 1, v12);
        motor(motor3pin, motor3pwm, 2, v34);
        motor(motor4pin, motor4pwm, 2, v34);
        //daying(v12, v34);
      }
      if (a < 45) {
        float v12 = abs(v * cos(45 - a));
        float v34 = abs(v * sin(45 - a));
        motor(motor1pin, motor1pwm, 1, v12);
        motor(motor2pin, motor2pwm, 1, v12);
        motor(motor3pin, motor3pwm, 1, v34);
        motor(motor4pin, motor4pwm, 1, v34);
        //daying(v12, v34);
      }
    }

    else if (xh < 128 && yh < 128 && pos >= 10) {
      float vx = (128 - xh) * 2;
      float vy = (128 - yh) * 2;
      float a = atan(vy / vx);
      float v = sqrt(vx * vx + vy * vy);
      if (a > 45) {
        float v34 = abs(v * cos(a - 45));
        float v12 = abs(v * sin(a - 45));
        motor(motor1pin, motor1pwm, 2, v12);
        motor(motor2pin, motor2pwm, 2, v12);
        motor(motor3pin, motor3pwm, 1, v34);
        motor(motor4pin, motor4pwm, 1, v34);
        //daying(v12, v34);
      }
      if (a < 45) {
        float v34 = abs(v * cos(45 - a));
        float v12 = abs(v * sin(45 - a));
        motor(motor1pin, motor1pwm, 1, v12);
        motor(motor2pin, motor2pwm, 1, v12);
        motor(motor3pin, motor3pwm, 1, v34);
        motor(motor4pin, motor4pwm, 1, v34);
        //daying(v12, v34);
      }
    }

  }

  //归零
  yh = 0;

  //i = i + 1;
  //if (i % 90 == 0)
  // Serial.println("all done");
}



