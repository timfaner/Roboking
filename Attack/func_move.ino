//本页定义移动的函数
void motorabs(char pin, char pwmpin, char state, int val) //参数pin是输入的高低电平的IO口,in1=pin in2=pin+1，pwmpin表示输入的PWM波形的IO口，state指电机状态(正转或反转)，val是调速值大小0-255
{
  
    if (val > 255)
        val = 255;
      if (state == 1)                          //当state为1时正转
      {
        analogWrite(pwmpin, val);
        digitalWrite(pin, 1);
        digitalWrite(pin + 1, 0);
      }
      else if (state == 2)                  //当state为2时反转
      {
        analogWrite(pwmpin, val);
        digitalWrite(pin, 0);
        digitalWrite(pin + 1, 1);
      }
      else if (state == 0)                  //当state为0时停止
      {
        analogWrite(pwmpin, 0);
        digitalWrite(pin, 0);
        digitalWrite(pin + 1, 0);
      }
      else if (state == 3)                  //当state为3时刹车
      {
        digitalWrite(pin, 1);
        digitalWrite(pin + 1, 1);
      }
    
  }

void m_stop() {                         //停止
  motor(motor1pin, motor1pwm, 3, 0);
  motor(motor2pin, motor2pwm, 3, 0);
  motor(motor3pin, motor3pwm, 3, 0);
  motor(motor4pin, motor4pwm, 3, 0);
  Serial.println("Stop");
}
void m_forward(int val) {
  motor(motor1pin, motor1pwm, 2, val);
  motor(motor2pin, motor2pwm, 2, val);
  motor(motor3pin, motor3pwm, 1, val);
  motor(motor4pin, motor4pwm, 1, val);
  Serial.println("Forward");
}
void m_backward(int val) {
  motor(motor1pin, motor1pwm, 1, val);
  motor(motor2pin, motor2pwm, 1, val);
  motor(motor3pin, motor3pwm, 2, val);
  motor(motor4pin, motor4pwm, 2, val);
  Serial.println("Backward");
}
void m_right(int val) {
  motor(motor1pin, motor1pwm, 2, val);
  motor(motor2pin, motor2pwm, 2, val);
  motor(motor3pin, motor3pwm, 2, val);
  motor(motor4pin, motor4pwm, 2, val);
  Serial.println("Right");
}
void m_left(int val) {
  motor(motor1pin, motor1pwm, 1, val);
  motor(motor2pin, motor2pwm, 1, val);
  motor(motor3pin, motor3pwm, 1, val);
  motor(motor4pin, motor4pwm, 1, val);
  Serial.println("Left");
}
void m_turnshun(int val) {                  //顺时针转
  motorabs(motor1pin, motor1pwm, 2, val);
  motorabs(motor2pin, motor2pwm, 1, val);
  motorabs(motor3pin, motor3pwm, 1, val);
  motorabs(motor4pin, motor4pwm, 2, val);
  //Serial.println("Shun");
}
void m_turnni(int val) {                  //你时针转
  motorabs(motor1pin, motor1pwm, 1, val);
  motorabs(motor2pin, motor2pwm, 2, val);
  motorabs(motor3pin, motor3pwm, 2, val);
  motorabs(motor4pin, motor4pwm, 1, val);
  //Serial.println("Ni");
}
void daying(int vvx,int vvy) {
  Serial.print("vvx=");
  Serial.print(vvx);
  Serial.print(" ; ");
  Serial.print("vvy=");
  Serial.println(vvy);
}



