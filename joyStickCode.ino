
#include <Servo.h>

Servo servo1, servo2, servo3, servo4, servo5, servo6;

int joyPinX1 = A0; // Joystick 1 X-axis
int joyPinY1 = A1; // Joystick 1 Y-axis
int joyPinX2 = A2; // Joystick 2 X-axis
int joyPinY2 = A3; // Joystick 2 Y-axis
int joyPinX3 = A4; // Joystick 3 X-axis
int joyPinY3 = A5; // Joystick 3 Y-axis

int servoMin = 0;   // Minimum servo position
int servoMax = 180; // Maximum servo position

int threshold = 5; // Threshold for joystick movement

void setup() {
  servo1.attach(3);
  servo2.attach(5);
  servo3.attach(6);
  servo4.attach(9);
  servo5.attach(10);
  servo6.attach(11);
}

void loop() {
  int x1 = analogRead(joyPinX1);
  int y1 = analogRead(joyPinY1);
  int x2 = analogRead(joyPinX2);
  int y2 = analogRead(joyPinY2);
  int x3 = analogRead(joyPinX3);
  int y3 = analogRead(joyPinY3);

  static int prevX1 = 0;
  static int prevY1 = 0;
  static int prevX2 = 0;
  static int prevY2 = 0;
  static int prevX3 = 0;
  static int prevY3 = 0;

  if (abs(x1 - prevX1) > threshold || abs(y1 - prevY1) > threshold ||
      abs(x2 - prevX2) > threshold || abs(y2 - prevY2) > threshold ||
      abs(x3 - prevX3) > threshold || abs(y3 - prevY3) > threshold) {
    int servoVal1 = map(x1, 0, 1023, servoMin, servoMax);
    int servoVal2 = map(y1, 0, 1023, servoMin, servoMax);
    int servoVal3 = map(x2, 0, 1023, servoMin, servoMax);
    int servoVal4 = map(y2, 0, 1023, servoMin, servoMax);
    int servoVal5 = map(x3, 0, 1023, servoMin, servoMax);
    int servoVal6 = map(y3, 0, 1023, servoMin, servoMax);

    servo1.write(servoVal1);
    servo2.write(servoVal2);
    servo3.write(servoVal3);
    servo4.write(servoVal4);
    servo5.write(servoVal5);
    servo6.write(servoVal6);

    prevX1 = x1;
    prevY1 = y1;
    prevX2 = x2;
    prevY2 = y2;
    prevX3 = x3;
    prevY3 = y3;
  }

  delay(15); // Delay to stabilize servos and reduce jitter
}
