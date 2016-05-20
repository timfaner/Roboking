#include <PS4BT.h>
#include <usbhub.h>
//#include <Servo.h>
// Satisfy the IDE, which needs to see the include statment in the ino too.
#ifdef dobogusinclude
#include <spi4teensy3.h>
#include <SPI.h>
#endif

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



int l,r,yh,xh,pitch[2],roll[2];
char printTouch;
void loop() {
  Usb.Task();
  
  if(PS4.connected()){
    l =PS4.getAnalogHat(RightHatX);
    //r = PS4.getAnalogButton(R2);
    yh = PS4.getAnalogHat(LeftHatX);
    xh = PS4.getAnalogHat(LeftHatY);
    PS4.setRumbleOn(xh,yh);
    //pitch[1] = PS4.getAngle(Pitch);
    //roll[1] = PS4.getAngle(Roll);
    
    /*if (PS4.getButtonClick(TOUCHPAD)) printTouch = !printTouch;
    if (printTouch){
      int dposz = roll[1]-roll[0];
      int dposx = pitch[1]-pitch[0];
      servoz.write(posz+dposz);
      servox.write(posx+dposx);
      
    }
    */
    if (PS4.getButtonClick(CROSS)){
      state = !state;
      motor(motor1pin,motor1pwm,0,0);
      motor(motor2pin,motor2pwm,0,0);
      motor(motor3pin,motor3pwm,0,0);
      motor(motor4pin,motor4pwm,0,0);
    }
    if (state) PS4.setLedFlash(10, 10);
    else PS4.setLed(Blue);
    
    if (PS4.getButtonClick(PS)) {
      Serial.print(F("\r\nPS"));
      PS4.disconnect();}
    if (l<116) {
      int val=(255-l)/2;
      PS4.setLed(Green);
      motor(motor1pin,motor1pwm,1,val);
      motor(motor2pin,motor2pwm,2,val);
      motor(motor3pin,motor3pwm,2,val);
      motor(motor4pin,motor4pwm,1,val);
    }
    if (l>137) {
      int val=l/2;
      PS4.setLed(Green);
      motor(motor1pin,motor1pwm,2,val);
      motor(motor2pin,motor2pwm,1,val);
      motor(motor3pin,motor3pwm,1,val);
      motor(motor4pin,motor4pwm,2,val);
      
    }
    if (xh > 137){
   
    int val=(xh-137)*2;
    PS4.setLed(Green);
    motor(motor1pin,motor1pwm,2,val);
    motor(motor2pin,motor2pwm,2,val);
    
    }
   if (xh < 117){
    int val=(xh)*2;
    PS4.setLed(Green);
    motor(motor1pin,motor1pwm,1,255-val);
    motor(motor2pin,motor2pwm,1,255-val);
    
    }
  if (yh > 137){
    int val=(yh-137)*2;
    PS4.setLed(Red);
    motor(motor3pin,motor3pwm,1,val);
    motor(motor4pin,motor4pwm,1,val);
    
    }
   if (yh < 117){
    int val=(yh)*2;
    PS4.setLed(Blue);
    motor(motor3pin,motor3pwm,2,255-val);
    motor(motor4pin,motor4pwm,2,255-val);
    
    }
  
}
l = 0;
//r = 0;
yh = 0;
xh = 0;
//pitch[0] = pitch[1];
//roll[0] = roll[1];
}



