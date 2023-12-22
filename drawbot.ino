#include <Stepper.h>

#define SP1 9
#define SP2 10
#define SP3 11
#define SP4 12

#define SP5 4
#define SP6 5
#define SP7 6
#define SP8 7

#define STEPS_PER_REVOLUTION 2048

Stepper lStepper(STEPS_PER_REVOLUTION, SP1, SP2, SP3, SP4);
Stepper rStepper(STEPS_PER_REVOLUTION, SP5, SP6, SP7, SP8);

int step_number_1 = 0;
int step_number_2 = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(SP1, OUTPUT);
  pinMode(SP2, OUTPUT);
  pinMode(SP3, OUTPUT);
  pinMode(SP4, OUTPUT);

  pinMode(SP5, OUTPUT);
  pinMode(SP6, OUTPUT);
  pinMode(SP7, OUTPUT);
  pinMode(SP8, OUTPUT);
}

void loop() {
  drawShape(2, 500, 500);
}

void changeMotorPositionOne(bool dir) {
  if (dir == false) {
    step_number_1++;
    if (step_number_1 > 3) {
      step_number_1 = 0;
    }
  } else if (dir == true) {
    step_number_1--;
    if (step_number_1 < 0) {
      step_number_1 = 3;
    }
  }
}

void changeMotorPositionTwo(bool dir) {
  if (dir == true) {
    step_number_2++;
    if (step_number_2 > 3) {
      step_number_2 = 0;
    }
  } else if (dir == false) {
    step_number_2--;
    if (step_number_2 < 0 ) {
      step_number_2 = 3;
    }
  }
}

void rotateMotors(int motorGroup, int angle, int Delay, int lSpeed, int rSpeed) {
  int steps;
  steps = map(angle, 0, 360, 0, STEPS_PER_REVOLUTION);
  if (lSpeed > 0) {
    lStepper.setSpeed(lSpeed);
  }
  if (rSpeed > 0) {
    rStepper.setSpeed(rSpeed);
  }
  for (int i = 0; i < steps; i++) {
    moveBot(motorGroup);
    delay(2);
  } 
  delay(Delay);
}

void moveLeftMotor(bool dir) {
  if (step_number_1 == 0) {
    digitalWrite(SP1, HIGH);
    digitalWrite(SP2, LOW);
    digitalWrite(SP3, LOW);
    digitalWrite(SP4, LOW);
    changeMotorPositionOne(dir);
  } else if (step_number_1 == 1) {
    digitalWrite(SP1, LOW);
    digitalWrite(SP2, HIGH);
    digitalWrite(SP3, LOW);
    digitalWrite(SP4, LOW);
    changeMotorPositionOne(dir);
  } else if (step_number_1 == 2) {
    digitalWrite(SP1, LOW);
    digitalWrite(SP2, LOW);
    digitalWrite(SP3, HIGH);
    digitalWrite(SP4, LOW);
    changeMotorPositionOne(dir);
  } else if (step_number_1 == 3) {
    digitalWrite(SP1, LOW);
    digitalWrite(SP2, LOW);
    digitalWrite(SP3, LOW);
    digitalWrite(SP4, HIGH);
    changeMotorPositionOne(dir);
  }
}

void moveRightMotor(bool dir) {
  if (step_number_2 == 0) {
    digitalWrite(SP5, HIGH);
    digitalWrite(SP6, LOW);
    digitalWrite(SP7, LOW);
    digitalWrite(SP8, LOW);
    changeMotorPositionTwo(dir);
  } else if (step_number_2 == 1) {
    digitalWrite(SP5, LOW);
    digitalWrite(SP6, HIGH);
    digitalWrite(SP7, LOW);
    digitalWrite(SP8, LOW);
    changeMotorPositionTwo(dir);
  } else if (step_number_2 == 2) {
    digitalWrite(SP5, LOW);
    digitalWrite(SP6, LOW);
    digitalWrite(SP7, HIGH);
    digitalWrite(SP8, LOW);
    changeMotorPositionTwo(dir);
  } else if (step_number_2 == 3) {
    digitalWrite(SP5, LOW);
    digitalWrite(SP6, LOW);
    digitalWrite(SP7, LOW);
    digitalWrite(SP8, HIGH);
    changeMotorPositionTwo(dir);
  }
}

void moveBot(int motorGroup) {
  switch (motorGroup) {
    case 1:
      //right
      moveLeftMotor(false);
      moveRightMotor(true);   
    case 2:  
      //left
      moveLeftMotor(true);
      moveRightMotor(false);
    case 3:
      //forward
      moveLeftMotor(true);
      moveRightMotor(true);
    case 4:
      //backwards
      moveLeftMotor(false);
      moveRightMotor(false);
  }
}

void drawShape(int shape, int cDelay, int sDelay) {
  int m = 100;
  switch (shape) {
    case 0:
      //draw square
      delay(sDelay);
      rotateMotors(3, 250, cDelay, m, m);
      rotateMotors(2, 180, cDelay, m, m);
      rotateMotors(3, 250, cDelay, m, m);
      rotateMotors(2, 180, cDelay, m, m);
      rotateMotors(3, 250, cDelay, m, m);
      rotateMotors(2, 180, cDelay, m, m);
      rotateMotors(3, 250, cDelay, m, m);
      rotateMotors(2, 180, cDelay, m, m);
    case 1:
      //draw triangle
      delay(sDelay);
      rotateMotors(3, 250, cDelay, m, m);
      rotateMotors(2, 180, cDelay, m, m);
      rotateMotors(3, 250, cDelay, m, m);
      rotateMotors(2, 270, cDelay, m, m);
      rotateMotors(3, 353, cDelay, m, m);
      rotateMotors(2, 270, cDelay, m, m);
    case 2:
      rotateMotors(3, 250, cDelay, 25, 25);
      rotateMotors(3, 250, cDelay, 50, 50);
      rotateMotors(3, 250, cDelay, m, m);
      rotateMotors(4, 250, cDelay, 25, 25);
      rotateMotors(4, 250, cDelay, 50, 50);
      rotateMotors(4, 250, cDelay, m, m);
      rotateMotors(2, 250, cDelay, 25, 25);
      rotateMotors(2, 250, cDelay, 50, 50);
      rotateMotors(2, 250, cDelay, m, m);
  }
}