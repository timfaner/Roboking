#define motor1pin 22
#define motor1pwm 12
#define motor2pin 26
#define motor2pwm 11
#define motor3pin 30
#define motor3pwm 10
#define motor4pin 34
#define motor4pwm 9
//#define armpin 38
//#define armpwm 8
void motor(char pin, char pwmpin, char states, int val) //参数pin是输入的高低电平的IO口,in1=pin in2=pin+1，pwmpin表示输入的PWM波形的IO口，state指电机状态(正转或反转)，val是调速值大小0-255
{
  pinMode(pin, OUTPUT);
  if (states == 1)                          //当state为1时正转
  {
    analogWrite(pwmpin, val);
    digitalWrite(pin, 1);
    digitalWrite(pin + 1, 0);
  }
  else if (states == 2)                  //当state为2时反转
  {
    analogWrite(pwmpin, val);
    digitalWrite(pin, 0);
    digitalWrite(pin + 1, 1);
  }
  else if (states == 0)                  //当state为0时停止
  {
    analogWrite(pwmpin, 0);
    digitalWrite(pin, 0);
    digitalWrite(pin + 1, 0);
  }
  else if (states == 3)                  //当state为3时刹车
  {
    digitalWrite(pin, 0);
    digitalWrite(pin + 1, 0);
  }
}
void setup() {
  // put your setup code here, to run once:
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
}
char ch;
void loop() {
  int val = 255;
  if (Serial.available()) {
    ch = Serial.read();
    if (ch == 0) {
      motor(motor1pin, motor1pwm, 1, val);
      motor(motor2pin, motor2pwm, 2, val);
      motor(motor3pin, motor3pwm, 2, val);
      motor(motor4pin, motor4pwm, 1, val);
      delay(1000);
    }
    if (ch == 1) {
      motor(motor1pin, motor1pwm, 2, val);
      motor(motor2pin, motor2pwm, 1, val);
      motor(motor3pin, motor3pwm, 1, val);
      motor(motor4pin, motor4pwm, 2, val);
      delay(1000);

    }
  }
  // put your main code here, to run repeatedly:

}
