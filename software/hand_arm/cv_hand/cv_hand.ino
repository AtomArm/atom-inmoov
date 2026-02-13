#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>

Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();

#define SERVOMIN  150
#define SERVOMAX  600

const int numServos = 6;
int servos[numServos] = {0, 1, 2, 3, 4, 5};

String inputString = "";
bool stringComplete = false;

void setup() {
  Serial.begin(9600);
  pwm.begin();
  pwm.setPWMFreq(50); // frequência padrão de servos

  for (int i = 0; i < numServos; i++) {
    pwm.setPWM(servos[i], 0, SERVOMIN);
  }
}

void loop() {
  if (stringComplete) {
    int valores[numServos];
    int index = 0;
    char *token = strtok((char*)inputString.c_str(), ",");

    while (token != NULL && index < numServos) {
      valores[index++] = atoi(token);
      token = strtok(NULL, ",");
    }

    for (int i = 0; i < numServos; i++) {
      if (valores[i] == 1)
        pwm.setPWM(servos[i], 0, SERVOMAX);  // Levanta dedo
      else
        pwm.setPWM(servos[i], 0, SERVOMIN);  // Abaixa dedo
    }

    inputString = "";
    stringComplete = false;
  }
}

void serialEvent() {
  while (Serial.available()) {
    char inChar = (char)Serial.read();
    if (inChar == '\n') {
      stringComplete = true;
    } else {
      inputString += inChar;
    }
  }
}
