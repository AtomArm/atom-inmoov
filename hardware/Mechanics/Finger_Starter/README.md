# Finger Starter

"This is going to be interesting!!
We are going to assemble a finger to a small servo for testing it with an Arduino board. The servo I used on the pictures is a digital HK15298 but you can use also a cheap analog MG995 or even cheaper if you find and if the size specifications are the same.
The Arduino board used here is a Arduino Uno. It is best to add an external power supply because even if these servos are small they draw too much current which will or might reboot your board.
At the end of this tuto, there is also a picture that illustrate how to simply connect your servo to the board.
REMEMBER: this connection set up can only power a single servo with low Amps drawing, if your board resets itself, or if the servo jitters, it means your servo is to high power consumption for the power pin. You will need an external power supply."


## Parts Needed
- 1 x Servo (HK15298, MG995, or similar)
- 1 x Arduino Uno (or similar)
- 1 x Finger Starter Kit (or similar)


- [YouTube: Finger Assembly Tutorial](https://www.youtube.com/watch?v=0t2uhAyf2-c)

- [Test Your Finger Sensor](https://inmoov.fr/test-your-finger-sensor/)
- [Finger Starter](https://inmoov.fr/finger-starter/)
- [YouTube: Finger Starter Demo](https://www.youtube.com/watch?v=y1LIKOaPQ1E)

- [YouTube: Servo Connection Guide](https://www.youtube.com/watch?v=UZnay5oXk4g)

## Instructions

1. Assemble the finger using the Finger Starter Kit. Follow the [Finger Assembly Tutorial](https://www.youtube.com/watch?v=0t2uhAyf2-c) for detailed instructions.

2. Connect the servo to the Arduino Uno:
   - Connect the servo's power wire (usually red) to the 5V pin on the Arduino.
   - Connect the servo's ground wire (usually black or brown) to a GND pin on the Arduino.
   - Connect the servo's signal wire (usually yellow, orange, or white) to a PWM-capable digital pin on the Arduino (e.g., pin 9).
    - If using an external power supply, connect the servo's power wire to the positive terminal of the power supply and the ground wire to the negative terminal. Ensure that the ground of the power supply is connected to the ground of the Arduino.

3. Setup the Servo Motor
    
    - 3.1 Setup the Servo Motor Library in the Arduino IDE:
        - Open the Arduino IDE on your computer.
        - Go to `File` > `Examples` > `Servo` > `Knob`. This example code will allow you to control the servo using a potentiometer.
        - Modify the code if necessary to match the pin you connected the servo signal wire to.

    - 3.2 Set the motor to the initial position:
        Run the code located at [`ServoMotorSetup/Set_Servo_Position.ino`](ServoMotorSetup/Set_Servo_Position.ino) in your Arduino IDE to set the servo to its initial position. Upload the sketch to your Arduino board and verify that the servo moves to the desired starting angle.

    - 3.2 Upload the Test Code:
        - Run the code located at [`ServoMotorSetup/Finger_Starter.ino`](ServoMotorSetup/Finger_Starter.ino) in your Arduino IDE to test the servo's movement. Upload the sketch to your Arduino board and observe the servo's behavior.
