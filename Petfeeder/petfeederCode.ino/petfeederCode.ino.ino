#include<Servo.h>
Servo myservo;
int pos;
char inputByte = 'z';
#define pos_initial 90
void setup()
{
 myservo.write(pos_initial);
 Serial.begin(9600);
 myservo.attach(13);
}
void loop()
{
 while(Serial.available() > 0)
 {
 inputByte = Serial.read();
 if(inputByte == 'Z')
 {
 for(pos=90;pos<180;pos++)
 {
 myservo.write(pos);
 delay(1);
 }
 delay(600);

14
 for(pos=180;pos>=90;pos--)
 {
 myservo.write(pos);
 delay(1);
 }
 Serial.println("Pet feeder has dispensed food!");
 }
 else if(inputByte == 'G')
 {
 for(pos=90;pos<180;pos++)
 {
 myservo.write(pos);
 delay(1);
 }
 delay(1500);
 for(pos=180;pos>=90;pos--)
 {
 myservo.write(pos);
 delay(1);
 }
 Serial.println("Pet feeder has dispensed extra food!");
 }
 else if(inputByte=='z' || inputByte=='g')
 {
 break;
 }
 }
} 