/*
  Program this sketch to Mega 2560 and connect to Arduino Uno with Bluetooth Host Shield.
  Establish a common ground when using the two microcotrollers.
  Connect a resistor to the Analog In Wire
  AnalogRead values range from 0 to 1023
  Use with PS3BT_Test
*/

volatile int motorSpeed = 128; //according to PWM, 2^8-1 is max speed in one direction

//Pins
const int ledPin = LED_BUILTIN;
volatile const int one_one = 2;
volatile const int one_two = 3;
const int one_pwm = 4;
volatile const int two_one = 5;
volatile const int two_two = 6;
const int two_pwm = 7;
const int readIn = 9;

unsigned long previousMillis = 0;
unsigned long currentMillis;
const long interval = 1000;
bool toggle;
volatile bool ledOn;
int readValue;

void Pins() {
  pinMode(one_one, OUTPUT);
	pinMode(one_two, OUTPUT);
	pinMode(one_pwm, OUTPUT);
  pinMode(two_one, OUTPUT);
	pinMode(two_two, OUTPUT);
	pinMode(two_pwm, OUTPUT);	
	pinMode(readIn, INPUT_PULLUP);
	
}

void setup() {
	currentMillis = 0;
	ledOn = false;
	toggle = LOW;
	Pins();
  stopMotor();
//	attachInterrupt(digitalPinToInterrupt(interruptPin), stopMotor, HIGH);	
//	attachInterrupt(digitalPinToInterrupt(interrupt2), movement, HIGH);
}

void sett() {
	if (currentMillis - previousMillis >= interval) {
		previousMillis = currentMillis;
		action();
	}
}

void action() {
  digitalWrite(ledPin, ledOn); ledOn = !ledOn;
}

/*
void turn() {
  //when called, read another digital pin to dictate lef or rig
  if (true) left(); else right();
}
*/

void stopMotor() {
  digitalWrite(one_one, LOW);
  digitalWrite(one_two, LOW);
  analogWrite(one_pwm, 0);
  digitalWrite(two_one, LOW);
  digitalWrite(two_two, LOW);
  analogWrite(two_pwm, 0);
}
void forward() {
  if (true) toggle = HIGH;
  digitalWrite(one_one, toggle); toggle = !toggle;
  digitalWrite(one_two, toggle); toggle = !toggle;
  digitalWrite(two_one, toggle); toggle = !toggle;
  digitalWrite(two_two, toggle); toggle =!toggle;
  analogWrite(one_pwm, motorSpeed);
  analogWrite(two_pwm, motorSpeed);
}

void loop() {
	currentMillis = millis();
	sett();       //disable if using real-time
	if (digitalRead(readIn) == LOW) stopMotor();
	if (digitalRead(readIn) == HIGH) forward();
	//action();   //disable if using a timer
}