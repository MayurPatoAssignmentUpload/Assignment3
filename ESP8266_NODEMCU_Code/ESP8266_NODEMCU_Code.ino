#include <BlynkSimpleEsp8266.h> 
#include <Servo.h>

#define BLYNK_TEMPLATE_ID "TMPL3dS8GsEei"
#define BLYNK_DEVICE_NAME "Assignment2"
#define BLYNK_AUTH_TOKEN "cpDhWvdpRiU5SEpVkiRYiARfWHx3kU6l"
#define BLYNK_PRINT Serial 

int value = 0, angle;
Servo servo;

char auth[] = BLYNK_AUTH_TOKEN ;
char ssid[] = "pato";
char pass[] = "mayurpato";

void move_servo(int);

BLYNK_WRITE(V0){
  if (value != param.asInt())
  {
    value = param.asInt();
    move_servo(value);
  }
}

void setup(){
  Serial.begin(115200);
  Blynk.begin(auth, ssid, pass);
  servo.attach(D4);
  servo.write(0);
  delay(200);
}

void loop(){
  Blynk.run();
}

void move_servo(int angle){
  Serial.print("Moving Servo by ");
  Serial.println(angle);
  servo.write(angle);
  delay(100);
}
