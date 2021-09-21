#include <SoftwareSerial.h>
SoftwareSerial EEBlue(10, 11); // RX | TX

char inputByte = 'z';
const int ENA = 9;
const int ENB = 3;
cosnt int IN1 = 7;
cosnt int IN2 = 6;
cosnt int IN3 = 5;
cosnt int IN4 = 4;
int pwm = 125;
void setup()
{
  Serial.begin(9600);
  EEBlue.begin(9600);  //Baud Rate for command Mode. 
  Serial.println("Enter AT commands!");
  pinMode(13, OUTPUT);
  pinMode (ENA, OUTPUT);
  pinMode (ENB, OUTPUT);
  pinMode (IN1, OUTPUT);
  pinMode (IN2, OUTPUT);
  pinMode (IN3, OUTPUT);
  pinMode (IN4, OUTPUT);
}
 
void loop()
{
 
  // Feed any data from bluetooth to Terminal.
  if (EEBlue.available())
    //Serial.write(EEBlue.read());
    inputByte = EEBlue.read();
    //Serial.write(inputByte);
    //Serial.println(inputByte);
    if (inputByte == '+')
    {
      Serial.println("Increasing speed by 5%");
      pwm+=5;
      Serial.println(pwm);
      digitalWrite(13, HIGH);
      speedMotor(pwm); 
      
    }
    else if (inputByte == '-'){
      Serial.println("Decreasing speed by 5%");
      pwm-=5;
      Serial.println(pwm);
      digitalWrite(13, HIGH);
      speedMotor(pwm); 
      
    }
    else
    {
      speedMotor(pwm);
      digitalWrite(13, LOW);
    }
 
  // Feed all data from termial to bluetooth
  if (Serial.available())
    EEBlue.write(Serial.read());
}

void speedMotor(int pw){
      analogWrite(ENA, pw);
      analogWrite(ENB, pw); 
      digitalWrite(IN1,HIGH);
      digitalWrite(IN2,LOW);
      digitalWrite(IN3,HIGH);
      digitalWrite(IN4,LOW);
      delay(100);
}
