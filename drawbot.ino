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
  rotateMotorByAngle(1, 180);
  delay(1500);
}

void changeMotorPositionOne() {
  step_number_1++;
  if(step_number_1 > 3) {
    step_number_1 = 0;
  }
}

void changeMotorPositionTwo() {
  step_number_2++;
  if(step_number_2 > 3) {
    step_number_2 = 0;
  }
}

void rotateMotorByAngle(int motorGroup, int angle) {
  int steps;
  if (motorGroup == 1 || motorGroup == 3) {
    steps = map(angle, 0, 360, 0, STEPS_PER_REVOLUTION);
    for (int i = 0; i < steps; i++) {
      moveForward(motorGroup);
      delay(2); // Adjust the delay as needed
    }
  } else if (motorGroup == 2) {
    // Adjust this condition if motorGroup 2 has a different mapping
    steps = map(angle, 0, 360, 0, STEPS_PER_REVOLUTION);
    for (int i = 0; i < steps; i++) {
      moveForward(motorGroup);
      delay(2); // Adjust the delay as needed
    }
  }
}

void moveForward(int motorGroup){
  if (motorGroup == 1) {
    switch(step_number_1) {
      case 0:
        digitalWrite(SP1, HIGH);
        digitalWrite(SP2, LOW);
        digitalWrite(SP3, LOW);
        digitalWrite(SP4, LOW);
        changeMotorPositionOne();
        break;
      case 1:
        digitalWrite(SP1, LOW);
        digitalWrite(SP2, HIGH);
        digitalWrite(SP3, LOW);
        digitalWrite(SP4, LOW);
        changeMotorPositionOne();
        break;
      case 2:
        digitalWrite(SP1, LOW);
        digitalWrite(SP2, LOW);
        digitalWrite(SP3, HIGH);
        digitalWrite(SP4, LOW); 
        changeMotorPositionOne();
        break;
      case 3:
        digitalWrite(SP1, LOW);
        digitalWrite(SP2, LOW);
        digitalWrite(SP3, LOW);
        digitalWrite(SP4, HIGH);
        changeMotorPositionOne();
        break;
    } 
  } else if (motorGroup == 3) {
    switch(step_number_1) {
      case 0:
        digitalWrite(SP1, HIGH);
        digitalWrite(SP2, LOW);
        digitalWrite(SP3, LOW);
        digitalWrite(SP4, LOW);
        changeMotorPositionOne();
        break;
      case 1:
        digitalWrite(SP1, LOW);
        digitalWrite(SP2, HIGH);
        digitalWrite(SP3, LOW);
        digitalWrite(SP4, LOW);
        changeMotorPositionOne();
        break;
      case 2:
        digitalWrite(SP1, LOW);
        digitalWrite(SP2, LOW);
        digitalWrite(SP3, HIGH);
        digitalWrite(SP4, LOW); 
        changeMotorPositionOne();
        break;
      case 3:
        digitalWrite(SP1, LOW);
        digitalWrite(SP2, LOW);
        digitalWrite(SP3, LOW);
        digitalWrite(SP4, HIGH);
        changeMotorPositionOne();
        break;
    } switch (step_number_2) {
      case 0:
        digitalWrite(SP5, HIGH);
        digitalWrite(SP6, LOW);
        digitalWrite(SP7, LOW);
        digitalWrite(SP8, LOW);
        changeMotorPositionTwo();
        break;
      case 1:
        digitalWrite(SP5, LOW);
        digitalWrite(SP6, HIGH);
        digitalWrite(SP7, LOW);
        digitalWrite(SP8, LOW);
        changeMotorPositionTwo();
        break;
      case 2: 
        digitalWrite(SP5, LOW);
        digitalWrite(SP6, LOW);
        digitalWrite(SP7, HIGH);
        digitalWrite(SP8, LOW);
        changeMotorPositionTwo();
        break;
      case 3:
        digitalWrite(SP5, LOW);
        digitalWrite(SP6, LOW);
        digitalWrite(SP7, LOW);
        digitalWrite(SP8, HIGH); 
        changeMotorPositionTwo();
        break;
    }
  } else if (motorGroup == 2) {
    switch(step_number_2) {
      case 0:
        digitalWrite(SP5, HIGH);
        digitalWrite(SP6, LOW);
        digitalWrite(SP7, LOW);
        digitalWrite(SP8, LOW);
        changeMotorPositionTwo();
        break;
      case 1:
        digitalWrite(SP5, LOW);
        digitalWrite(SP6, HIGH);
        digitalWrite(SP7, LOW);
        digitalWrite(SP8, LOW);
        changeMotorPositionTwo();
        break;
      case 2: 
        digitalWrite(SP5, LOW);
        digitalWrite(SP6, LOW);
        digitalWrite(SP7, HIGH);
        digitalWrite(SP8, LOW);
        changeMotorPositionTwo();
        break;
      case 3:
        digitalWrite(SP5, LOW);
        digitalWrite(SP6, LOW);
        digitalWrite(SP7, LOW);
        digitalWrite(SP8, HIGH); 
        changeMotorPositionTwo();
        break;
    }    
  }
}