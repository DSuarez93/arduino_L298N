/*
  Press Triangle or Circle to activate rumple.
  Disconnect the controller to shut off the motor.
  Uno (2) to Mega(9)
  Connect grounds of both microcontrollers together.
*/

#include <PS3BT.h>
#include <usbhub.h>
#include <SPI.h>

USB Usb;
BTD Btd(&Usb);
PS3BT PS3(&Btd, 0x00, 0x15, 0x83, 0x3D, 0x0A, 0x57);
bool switching;
const int ledPin =   4;
const int sendPin =  2;       //connect to MEGA
const int switcher = 7;

void setup() {
  Serial.begin(115200);
  switching = 1;
  pinMode(ledPin, OUTPUT);
  pinMode(sendPin, OUTPUT);
  #if !defined(__MIPSEL__)
    while (!Serial);
  #endif
  if (Usb.Init() ==-1) {
    while(1) {
      digitalWrite(ledPin, switching);
      switching = !switching;
      delay(500);
    }
  }
  for (int i = 0; i<6; i++) {
    digitalWrite(ledPin, switching);
    switching = !switching;
    delay(200);
  }
}

void loop() {
  Usb.Task();
  if (PS3.PS3Connected) {
    digitalWrite(sendPin, HIGH);
    if (PS3.getButtonPress(PS) && PS3.getButtonPress(L2) && PS3.getButtonPress(R1)) {
      PS3.disconnect();
      //brake if breaks
    }
    if (PS3.getButtonClick(UP)) {
          PS3.setLedOff();
          PS3.setLedOn(LED4);
    }
    if (PS3.getButtonClick(RIGHT)) {
          PS3.setLedOff();
          PS3.setLedOn(LED1);
    }
    if (PS3.getButtonClick(DOWN)) {
          PS3.setLedOff();
          PS3.setLedOn(LED2);
    }
    if (PS3.getButtonClick(LEFT)) {
          PS3.setLedOff();
          PS3.setLedOn(LED3);
    }
    if (PS3.getButtonClick(SQUARE)) {
        
    }
    if (PS3.getButtonClick(TRIANGLE)) {
        PS3.setRumbleOn(RumbleLow);
    }
    if (PS3.getButtonClick(CROSS)) {
        
    }
    if (PS3.getButtonClick(CIRCLE)) {
        PS3.setRumbleOn(RumbleHigh);
    }
    if (PS3.getButtonClick(R1)) {
        
    }
    if (PS3.getButtonClick(L1)) {
    }
    if (PS3.getButtonClick(L3)) {
    }
    if (PS3.getButtonClick(R3)) {
    }
    if (PS3.getButtonClick(L2)) {
    }    
    if (PS3.getButtonClick(R2)) {
    }
  } else digitalWrite(sendPin, LOW);//end PS3 Connect; brake if breaks
}