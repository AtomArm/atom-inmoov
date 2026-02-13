#include <ESP32Servo.h>

Servo myServo;  // Cria objeto do servo
int ServoPos = 0;

#define SERVO_PIN 18  // GPIO18 para o sinal do servo

void setup() {
  Serial.begin(115200);
  myServo.attach(SERVO_PIN);  // Liga servo no pino escolhido
  myServo.write(ServoPos);    // Posição inicial
}

void loop() {
  // Exemplo: varre de 0° a 90°
  for (int pos = 0; pos <= 90; pos++) {
    myServo.write(pos);
    delay(15);
  }
  delay(500);

  // Volta de 90° a 0°
  for (int pos = 90; pos >= 0; pos--) {
    myServo.write(pos);
    delay(15);
  }
  delay(500);
}