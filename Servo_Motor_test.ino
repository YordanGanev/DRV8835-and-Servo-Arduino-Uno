#include "pin_definitions.h"
#include <Servo.h>

Servo myServo;

#define SPEED 140

void setup() {
  
  pinMode(LEFT_MOTOR_DIR , OUTPUT);
  pinMode(RIGHT_MOTOR_DIR, OUTPUT);
  pinMode(LEFT_MOTOR_PWM, OUTPUT);
  pinMode(RIGHT_MOTOR_PWM, OUTPUT);
  
  foward();
  delay(2000);
  backward();
  delay(2000);
  
  myServo.attach(SERVO);
  myServo.write(90);
}

void loop() {
  foward();
  for(int i = 0; i < 180; i += 10)
  {
    myServo.write(i);
    delay(100);
  }
  backward();
  for(int i = 180; i > 0; i -= 10)
  {
    myServo.write(i);
    delay(100);
  }
}

void foward()
{
  digitalWrite(LEFT_MOTOR_DIR, HIGH);
  digitalWrite(RIGHT_MOTOR_DIR, HIGH);
  analogWrite(LEFT_MOTOR_PWM, SPEED);
  analogWrite(RIGHT_MOTOR_PWM, SPEED);
}

void backward()
{
  digitalWrite(LEFT_MOTOR_DIR, LOW);
  digitalWrite(RIGHT_MOTOR_DIR, LOW);
  analogWrite(LEFT_MOTOR_PWM, SPEED);
  analogWrite(RIGHT_MOTOR_PWM, SPEED);
}
