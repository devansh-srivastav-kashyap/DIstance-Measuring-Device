This project measures the distance between the sensor and the object in front of the sensor. This sensor works on the concept similar to SONAR. 

Equipments Used- 
1- HCSR04 Ultrasonic Sensor
2- LCD
3- TMP36 Temperature sensor

HCSR04 Ultrasonic sensor has 4 pins. One power pin, one ground pin, trigger and echo pin. 
trigger pin- 13
echo pin- 12

Arduino Uno R3 triggers a voltage signal that will initiate the signal. The signal will have a duty cycle of 10 microseconds. Initial Condition is LOW. Then HIGH for 10microseconds and 
then again LOW. This will be the trigger signal. On this, echo pin will get back the signal. For that, make it high. To measure the duration of the transmission and receiving, we will use pulseIN()
function. This pulseIn() function counts the time when signal goes LOW-HIGH-LOW. The time taken to complete this cycle will be given by puleIn() function.

Distance= (duration/2)*(331+0.6*temp)

where (331+0.6*temp) is the speed of the sound.
