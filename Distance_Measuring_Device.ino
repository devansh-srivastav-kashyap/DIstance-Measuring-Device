/* This project measures the distance between the sensor and the object in front of the sensor. This sensor works on the concept similar to SONAR. 

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

*/


#include <LiquidCrystal.h>

#define trigger 13
#define echo 12
#define green 11
#define red 10

float temp1;

LiquidCrystal lcd(2,3,4,5,6,7);

float countTemperature()
{
  float tmp,voltage;
  voltage= analogRead(A0) * 0.00488758553;   //value of input values in range of 0-5
  tmp= (voltage-0.5)* 100; 
  return tmp;
}




void setup()
{
lcd.begin(16, 2);
lcd.setCursor(0,0);
pinMode(A0, INPUT);
pinMode(trigger, OUTPUT);
pinMode(echo, INPUT);
pinMode(green, OUTPUT);
pinMode(red, OUTPUT);
Serial.begin(9600);
}

void loop()
{
temp1=countTemperature();
lcd.setCursor(0,0);
lcd.print("Temp-");
lcd.setCursor(5,0);
lcd.print(temp1);
digitalWrite(trigger,LOW);
delayMicroseconds(2);
digitalWrite(trigger,HIGH);
delayMicroseconds(10);
digitalWrite(trigger,LOW);
float duration = pulseIn(echo,HIGH);
float distance = ((duration * (331+ 0.6 * temp1)) / 2)/10000;
lcd.setCursor(0,1);
lcd.println("Dist-");
lcd.setCursor(5,1);
lcd.print(distance);

  if(distance > 150)
  {
    digitalWrite(green,HIGH);
    digitalWrite(red,LOW);
  }
  else if (distance <= 150)
  {
   digitalWrite(red,HIGH);
   digitalWrite(green,LOW);
  }
}
