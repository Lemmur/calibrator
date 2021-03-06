#include <Arduino.h>
#include <Adafruit_PWMServoDriver.h>

#define SERVOMIN  100 // This is the 'minimum' pulse length count (out of 4096)
#define SERVOMAX  550 // This is the 'maximum' pulse length count (out of 4096)
#define SERVO_FREQ 60 // Analog servos run at ~60 Hz updates

Adafruit_PWMServoDriver board = Adafruit_PWMServoDriver(0x40);

int getPulseFromDeg (int deg) {
  return map(deg, 0, 180, SERVOMIN, SERVOMAX);
}

void setup() {

  board.begin();
  board.setOscillatorFrequency(27000000);
  board.setPWMFreq(60);
  board.setPWM(0, 0, getPulseFromDeg(90));
}

void loop() {
  
}