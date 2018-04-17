#define wired 0
#define lowDead 50
#define highDead 200
USB Usb
#if (wired == 0)
  BTD Btd(&Usb);
  PS3BT PS3(&Btd, 0x00, 0x15, 0x83, 0x3D, 0x0A, 0x57);
#else
  PS3USB PS3(&Usb);
#endif

const int sendPin =  2;       //connect to MEGA
const int tens =   3;
const int hundreds = 4;
            //            (2, 4, 7)
int statuo; //0: stop     (0, 0, 0)
            //1: right    (0, 0, 1)
            //2: left     (0, 1, 0)
            //3: forward  (0, 1, 1)
            //4: backward (1, 0, 0)
  
  //  Connect USB Bluetooth in void setup()
void initConnect() {
  #if !defined(__MIPSEL__)  // - used on Leonardo, Teensy and other boards with built-in USB CDC serial connection
  while (!Serial); // Wait for serial port to connect
  #endif
  if (Usb.Init() == -1) {
    while (1) {
      digitalWrite(LED_BUILTIN, LOW); //halt if USB Host Shield is not connected
      delay(1200);
      digitalWrite(LED_BUILTIN, HIGH);
      delay(1200);
    }
  }
}

void dc() {
  if (PS3.getButtonPress(R2) && (PS3.getButtonPress(L1) && (PS3.getButtonClick(PS)) {           
    PS3.disconnect();
  }
}
void LEDs() {
  if (PS3.getButtonClick(UP)) {
    PS3.setLedOff(); PS3.setLedOn(LED4); }
  if (PS3.getButtonClick(RIGHT)) {
    PS3.setLedOff(); PS3.setLedOn(LED1); }
  if (PS3.getButtonClick(DOWN)) {
    PS3.setLedOff(); PS3.setLedOn(LED2); }
  if (PS3.getButtonClick(LEFT)) {
    PS3.setLedOff(); PS3.setLedOn(LED3); }
}
void control() {
    if(PS3.getAnalogHat(LeftHatY) < lowDead) {
      statuo = 3; return;
    }
    if(PS3.getAnalogHat(LeftHatY) > highDead) {
      statuo = 4; return;
    }
    if(PS3.getAnalogHat(RightHatX) > lowDead) {
      statuo = 2; return;
    }
    if(PS3.getAnalogHat(RightHatX) < highDead) {
      statuo = 1; return;
    }
    statuo = 0;
}

void sendOut(int stat) {
  switch(stat) {
    case 3:   //forward
      digitalWrite(hundreds, LOW); 
      digitalWrite(tens,    HIGH); 
      digitalWrite(sendPin, HIGH);
      break;
    case 2:   //left
      digitalWrite(hundreds, LOW); 
      digitalWrite(tens,     HIGH); 
      digitalWrite(sendPin,  LOW);
      break;
    case 1:   //right
      digitalWrite(hundreds, LOW); 
      digitalWrite(tens,     LOW); 
      digitalWrite(sendPin,  HIGH);
      break;
    case 4:   //backward
      digitalWrite(hundreds, HIGH); 
      digitalWrite(tens,     LOW); 
      digitalWrite(sendPin,  LOW);
      break;      
    default: 
      digitalWrite(hundreds, LOW); 
      digitalWrite(tens, LOW); 
      digitalWrite(sendPin, LOW);
  }
}
