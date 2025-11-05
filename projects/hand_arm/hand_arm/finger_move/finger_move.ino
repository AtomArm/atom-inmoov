#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>

// Cria o objeto do PCA9685 (endereço padrão: 0x40)
Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver(0x40);

// Define o intervalo de pulso (ajuste fino conforme seu servo)
#define SERVO_MIN 150  // Pulso para 0 graus (~1.0 ms)
#define SERVO_MAX 600  // Pulso para 180 graus (~2.0 ms)

// Quantidade de servos usados
#define NUM_SERVOS 6

// Canais do PCA9685 usados (0 a 15 possíveis)
uint8_t servoChannels[NUM_SERVOS] = {0, 1, 2, 3, 4, 5};

void setup() {
  Serial.begin(9600);
  Serial.println("Inicializando PCA9685 para 6 servos...");

  pwm.begin();
  pwm.setPWMFreq(50); // Frequência típica de servo: 50Hz (20 ms)

  delay(500);
}

void loop() {
  // Exemplo: varrer todos os 6 servos de 0° a 180° e voltar
  for (int angle = 0; angle <= 180; angle += 5) {
    moveAllServos(angle);
    delay(30);
  }
  for (int angle = 180; angle >= 0; angle -= 5) {
    moveAllServos(angle);
    delay(30);
  }
}

// Função auxiliar para converter ângulo em pulso
int angleToPulse(int angle) {
  return map(angle, 0, 180, SERVO_MIN, SERVO_MAX);
}

// Move todos os servos simultaneamente
void moveAllServos(int angle) {
  int pulse = angleToPulse(angle);
  for (uint8_t i = 0; i < NUM_SERVOS; i++) {
    pwm.setPWM(servoChannels[i], 0, pulse);
  }

  Serial.print("Ângulo: ");
  Serial.print(angle);
  Serial.print("  Pulso: ");
  Serial.println(pulse);
}