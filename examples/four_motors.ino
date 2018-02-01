#include <L298N.h>
  //Front Motors
const int ENA_1 = 3;  //PWM
const int IN1_1 = 0;
const int IN2_1 = 1;
const int IN3_1 = 2;
const int IN4_1 = 4;
const int ENB_1 = 5;  //PWM
  //Rear Motors
const int ENA_2 = 9;  //PWM
const int IN1_2 = 7;
const int IN2_2 = 8;
const int IN3_2 = 10;
const int IN4_2 = 12;
const int ENB_2 = 11;  //PWM
L298N driver_front(ENA_1,IN1_1,IN2_1,IN3_1,IN4_1,ENB_1); 
L298N driver_back(ENA_2,IN1_2,IN2_2,IN3_2,IN4_2,ENB_2);
int time_delay = 500;
int speed = 150;

void car_forward(speed) {
      driver_front.forward(speed);
      driver_back.forward(speed);
}
void car_backward(speed) {
      driver_front.backward(speed);
      driver_back.backward(speed);
}
void car_stop() {
      driver_front.full_stop();
      driver_back.full_stop();
}
void car_left(speed) {
      driver_front.turn_left(speed);
      driver_back.turn_left(speed);
}
void car_right(speed) {
      driver_front.turn_right(speed);
      driver_back.turn_right(speed);
}

void setup()
{
}

void loop()
{
  int a;
  switch (a) {
    case 0: 
      car_forward(speed); break;
    case 1: 
      car_backward(speed); break;
    case 2:
      car_left(speed); break;
    case 3:
      car_right(speed); break;
    default: 
    car_stop();
  }
}
