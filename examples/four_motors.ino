#include <L298N.cpp>
//enA, mo1a, mo1b, mo2a, mo2b, enB
L298N driver_front(4,2,3,5,6,7); 
L298N driver_back(10,8,9,11,12,13);
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
