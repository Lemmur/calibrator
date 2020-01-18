#include <Arduino.h>
#include <Adafruit_PWMServoDriver.h>

#define SERVOMIN  150 // This is the 'minimum' pulse length count (out of 4096)
#define SERVOMAX  600 // This is the 'maximum' pulse length count (out of 4096)
#define SERVO_FREQ 60 // Analog servos run at ~60 Hz updates

Adafruit_PWMServoDriver board = Adafruit_PWMServoDriver(0x41);

int getPulseFromDeg (int deg) {
  return map(deg, 0, 180, SERVOMIN, SERVOMAX);
}

void setup() {
  board.begin();
  board.setOscillatorFrequency(27000000);
  board.setPWMFreq(SERVO_FREQ);

  board.setPWM(15, 0, getPulseFromDeg(0));
}

void loop() {
  delay(1000);
  board.setPWM(15, 0, getPulseFromDeg(180));
  delay(1000);
  board.setPWM(15, 0, getPulseFromDeg(0));
}