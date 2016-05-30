#include <AFMotor.h>
AF_DCMotor motor1(1, MOTOR12_8KHZ);
AF_DCMotor motor2(2, MOTOR12_8KHZ);
AF_DCMotor motor3(3, MOTOR34_1KHZ);
String c = "";

void setup() {
  // put your setup code here, to run once:
  Serial1.begin(9600);
  Serial.begin(9600);
}
boolean state;
int a;
void loop()
{
  while (Serial1.available() > 0)
  {
    c = char(Serial1.read());
    delay(2);
    Serial.println(c);
  }
  if (c == "V")
    state = 0;
  if (c == "v")
    state = 1;
  if (c == "1")
    a = 100;
  else if (c == "2")
    a = 110;
  else if (c == "3")
    a = 120;
  else if (c == "4")
    a = 130;
  else if (c == "5")
    a = 140;
  else if (c == "6")
    a = 160;
  else if (c == "7")
    a = 180;
  else if (c == "8")
    a = 200;
  else if (c == "9")
    a = 220;
  if (state) {
    if (c == "F") //前进指令
    {
      motor1.setSpeed(a);
      motor2.setSpeed(a);
      motor1.run(FORWARD);
      motor2.run(FORWARD);
      Serial.println(a);
    }
    else if (c == "L") //左转指令
    {
      motor1.setSpeed(a);
      motor2.setSpeed(a);
      motor1.run(BACKWARD);
      motor2.run(FORWARD);
      Serial.println(a);
    }
    else if (c == "R") //右转指令
    {
      motor1.setSpeed(a);
      motor2.setSpeed(a);
      motor1.run(FORWARD);
      motor2.run(BACKWARD);
    }
    else if (c == "S") //松手制动
    {
      motor1.setSpeed(0);
      motor2.setSpeed(0);
    }
    if (c == "B
    ") //后退指令
  {
    motor1.setSpeed(a);
    motor2.setSpeed(a);
    motor1.run(BACKWARD);
    motor2.run(BACKWARD);
    }
  }
  if (!state) {

    if (c == "B") //前进指令
    {
      motor1.setSpeed(a);
      motor2.setSpeed(a);
      motor1.run(FORWARD);
      motor2.run(FORWARD);
      Serial.println(a);
    }
    else if (c == "S") //松手制动
    {
      motor1.setSpeed(0);
      motor2.setSpeed(0);
    }

    else if (c == "L") //左转指令
    {
      motor1.setSpeed(a);
      motor2.setSpeed(a);
      motor1.run(BACKWARD);
      motor2.run(FORWARD);
      Serial.println(a);
    }
    else if (c == "R") //右转指令
    {
      motor1.setSpeed(a);
      motor2.setSpeed(a);
      motor1.run(FORWARD);
      motor2.run(BACKWARD);
    }
  
  if (c == "F") //后退指令
  {
    motor1.setSpeed(a);
    motor2.setSpeed(a);
    motor1.run(BACKWARD);
    motor2.run(BACKWARD);
  }
}
 if (c == "W") //紧急制动
{
  motor1.setSpeed(0);
  motor2.setSpeed(0);
  motor1.run(RELEASE);
  motor2.run(RELEASE);
}
else if (c == "U") //风扇转动
{
  motor3.setSpeed(180);
  motor3.run(FORWARD);
}
 else if (c == "u") //风扇停止
{
  motor3.setSpeed(0);
  motor3.run(RELEASE);

}
}



