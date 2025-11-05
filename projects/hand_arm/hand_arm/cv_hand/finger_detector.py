import cv2
from cvzone.HandTrackingModule import HandDetector
import serial
import time

# === CONFIGURAÇÃO SERIAL COM O ARDUINO ===
arduino = serial.Serial(port='COM3', baudrate=9600, timeout=.1)
time.sleep(2)

# === CONFIGURAÇÃO DA CÂMERA E DETECTOR ===
cap = cv2.VideoCapture(0)
detector = HandDetector(maxHands=1, detectionCon=0.8)

while True:
    success, img = cap.read()
    if not success:
        break

    hands, img = detector.findHands(img)
    if hands:
        hand = hands[0]
        fingers = detector.fingersUp(hand)
        print("Dedos:", fingers)

        vetor_str = ','.join(map(str, fingers)) + '\n'
        arduino.write(vetor_str.encode())

    cv2.imshow("Finger Detection", img)
    if cv2.waitKey(1) & 0xFF == ord('q'):
        break

cap.release()
cv2.destroyAllWindows()
arduino.close()
