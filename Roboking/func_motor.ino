
void motor(char pin,char pwmpin,char state,int val)//参数pin是输入的高低电平的IO口,in1=pin in2=pin+1，pwmpin表示输入的PWM波形的IO口，state指电机状态(正转或反转)，val是调速值大小0-255
{
    pinMode(pin, OUTPUT);    
  if(state==1)                             //当state为1时正转
  {  
    analogWrite(pwmpin,val);
    digitalWrite(pin,1);
    digitalWrite(pin+1,0);
   }
  else if(state==2)                     //当state为2时反转
{  
   analogWrite(pwmpin,val);
   digitalWrite(pin,0);
   digitalWrite(pin+1,1);
}
else if(state==0)                     //当state为0时停止
{
    analogWrite(pwmpin,0);
    digitalWrite(pin,0);
    digitalWrite(pin+1,0);
}
else if(state==3)                     //当state为3时刹车
{
    digitalWrite(pin,0);
    digitalWrite(pin+1,0);
}
}
