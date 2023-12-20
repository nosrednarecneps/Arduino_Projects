#define SP1 9
#define SP2 10
#define SP3 11
#define SP4 12

#define SP5 4
#define SP6 5
#define SP7 6
#define SP8 7

#define STEPS_PER_REVOLUTION 2048

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
  // put your main code here, to run repeatedly:
  rotateMotorByAngle(3, 500);
  delay(500);
  rotateMotorByAngle(2, 180);
  delay(500);
  rotateMotorByAngle(3, 500);
  delay(500);
  rotateMotorByAngle(2, 180);
  delay(500);
  rotateMotorByAngle(3, 500);
  delay(500);
  rotateMotorByAngle(2, 180);
  delay(500);
  rotateMotorByAngle(3, 500);
  delay(500);
  rotateMotorByAngle(2, 180);
  delay(3000);
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

void rotateMotorByAngle(int motorGroup, int angle) {
  int steps;
  steps = map(angle, 0, 360, 0, STEPS_PER_REVOLUTION);
  for (int i = 0; i < steps; i++) {
    moveForward(motorGroup);
    delay(2); // Adjust the delay as needed
  } 
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

void moveForward(int motorGroup) {
  if (motorGroup == 1) {
    //right
    moveLeftMotor(false);
    moveRightMotor(true);
    //forward
  } else if (motorGroup == 3) {
    moveLeftMotor(true);
    moveRightMotor(true);
  } else if (motorGroup == 2) {
    //left
    moveLeftMotor(true);
    moveRightMotor(false);
  } else if (motorGroup == 4) {
    moveLeftMotor(false);
    moveRightMotor(false);
  }
}