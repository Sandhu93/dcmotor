# dcmotor

Simple DC Motor speed control using bluetooth and PWM.
Set duty cycle of the pwm to 50% and using bluetooth, it arduino receives '+' or '-' characters, the pwm frequency changes by 5%.

Serial Bluetooth Terminal App is used to send command signals. HC-05 is interfaced using serial communication
https://play.google.com/store/apps/details?id=de.kai_morich.serial_bluetooth_terminal&hl=en&gl=US 

L29N motor driver is used instead of BTS7960
Because it was not available on circuit.io or proteus.
Coding is same for both drivers.
