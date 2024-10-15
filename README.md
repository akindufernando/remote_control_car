# remote_control_car

Here's an Arduino code example for a simple remote-controlled car that uses an Arduino Uno, Bluetooth module (e.g., HC-05 or HC-06), a motor driver module (e.g., L298N), and two gear motors. This code defines methods for moving forward, backward, turning left, and turning right.

Components:
Arduino Uno
Bluetooth module (HC-05 or HC-06)
L298N motor driver module
2 gear motors
Power supply (battery pack)

Wiring:

Bluetooth module:
VCC to 5V
GND to GND
TX to RX on Arduino
RX to TX on Arduino

L298N Motor Driver:
IN1 to Arduino pin 7
IN2 to Arduino pin 6
IN3 to Arduino pin 5
IN4 to Arduino pin 4
ENA (motor A enable) to Arduino pin 9
ENB (motor B enable) to Arduino pin 10
Motor A to left motor terminals
Motor B to right motor terminals
GND to Arduino GND
VCC (12V) to the power source for motors

Gear motors:
Connect each motor to the L298N motor driver.

Explanation:
The code reads commands sent via the Bluetooth module (e.g., 'F' for forward, 'B' for backward, 'L' for left, 'R' for right, and 'S' for stop).
Based on the received command, the corresponding function is called to control the motor direction and speed.
The analogWrite() function controls the motor speed by adjusting the PWM signal (255 for full speed).

Controlling the Car:
You can use a Bluetooth terminal app on your smartphone to send commands to the car:

'F' for forward
'B' for backward
'L' for left
'R' for right
'S' for stop
