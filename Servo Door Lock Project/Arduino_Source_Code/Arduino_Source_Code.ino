#include <SoftwareSerial.h>
#include <Servo.h>

Servo myServo;
int TxD = 11;
int RxD = 10;
int servoposition;
int servopos;
int new1;
SoftwareSerial bluetooth(TxD, RxD);

void setup() {
  int pos=0;
  myServo.attach(9);
  myServo.write(0);
  Serial.begin(9600);       // start serial communication at 9600bps
  bluetooth.begin(9600);
}

void loop() {
 if (bluetooth.available())
   {
    String value = bluetooth.readString();
    servoposition = value.toInt();

    if (value.toInt() == 0)
    {
      bluetooth.print("3");
    myServo.write(0);
      }

      if (value.toInt() == 45)
    {
    myServo.write(45);
      }

      if (value.toInt() == 90)
    {
      bluetooth.print("4");
    myServo.write(90);
      }

      if (value.toInt() == 135)
    {
    myServo.write(135);
      }

      if (value.toInt() == 180)
    {
    myServo.write(180);
      }
      
   while(value.toInt()==1){
    if (bluetooth.available())
   {
    value = bluetooth.readString();
    if (value.toInt()==2)
    { break; }
      
   }
   
    servopos++;
    delay(30);
    myServo.write(servopos);
  
 
    
    if (servopos ==180 )
    {servopos=0;break;}
 
    
  }

 }

}
