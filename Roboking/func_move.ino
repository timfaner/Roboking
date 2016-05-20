//本页定义移动的函数
void m_stop() {                         //停止
  motor(motor1pin, motor1pwm, 0, 0);
  motor(motor2pin, motor2pwm, 0, 0);
  motor(motor3pin, motor3pwm, 0, 0);
  motor(motor4pin, motor4pwm, 0, 0);
}
void m_forward(int val) {
  motor(motor3pin, motor3pwm, 2, val);
  motor(motor4pin, motor4pwm, 2, val);

}
void m_backward(int val) {
  motor(motor3pin, motor3pwm, 1, val);
  motor(motor4pin, motor4pwm, 1, val);

}
void m_right(int val) {
  motor(motor1pin, motor1pwm, 2, val);
  motor(motor2pin, motor2pwm, 2, val);
}
void m_left(int val) {
  motor(motor1pin, motor1pwm, 1, val);
  motor(motor2pin, motor2pwm, 1, val);
}
void m_turnshun(int val) {                  //顺时针转
  motor(motor1pin, motor1pwm, 2, val);
  motor(motor2pin, motor2pwm, 1, val);
  motor(motor3pin, motor3pwm, 1, val);
  motor(motor4pin, motor4pwm, 2, val);
}
void m_turnni(int val) {                  //你时针转
  motor(motor1pin, motor1pwm, 1, val);
  motor(motor2pin, motor2pwm, 2, val);
  motor(motor3pin, motor3pwm, 2, val);
  motor(motor4pin, motor4pwm, 1, val);
}

