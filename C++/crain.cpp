#include <Servo.h>
int pinx1 = 2, pinx2 = 3;
int piny1 = 4, piny2 = 5;
int crainy = 6, crainx = 7;
int button = 8;
int vx = A0,vy = A1;
int start = 9;
int cmp = 0;
Servo servoy,servox;
unsigned long start_time = 0;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(button, INPUT_PULLUP);
    pinMode(start,INPUT_PULLUP);
     servoy.attach(crainy); 
     servox.attach(crainx);
}

void loop() {
  // put your main code here, to run repeatedly:
  int VX = analogRead(vx);
  int VY = analogRead(vy);
  int reading = digitalRead(start);
  Serial.println(reading);
  if(!reading && !cmp){
    cmp = 1;
    start_time = millis();
  }
  //Serial.println(reading);
  if(cmp){
  	Serial.println("@@@@@@");
    unsigned int cur = millis();
    if((cur - start_time)%1000==0) Serial.println((cur - start_time)/1000);
    int tmp = digitalRead(button);
    if(VX < 300){
      digitalWrite(pinx1,LOW);
      digitalWrite(pinx2,HIGH);   
    }else if(VX > 700){
      digitalWrite(pinx1,HIGH);
      digitalWrite(pinx2,LOW);     
    }else{
      digitalWrite(pinx1,LOW);
      digitalWrite(pinx2,LOW);     
    }
    if(VY < 300){
      digitalWrite(piny1,LOW);
      digitalWrite(piny2,HIGH);   
    }else if(VY > 700){
      digitalWrite(piny1,HIGH);
      digitalWrite(piny2,LOW);     
    }else{
      digitalWrite(piny1,LOW);
      digitalWrite(piny2,LOW);     
    } 
    if(cur > start_time + 20000 || tmp == 0){
      if(tmp == 0){
        int pos;
        for(pos = 179; pos >= 0; pos -= 1)  // 0도에서 180도로 이동합니다.
        {                                  // 이동할때 각도는 1도씩 이동합니다. 
          servoy.write(pos);              // 'pos'변수의 위치로 서보를 이동시킵니다.
          delay(15);                       // 서보 명령 간에 20ms를 기다립니다.
        } 
        for(pos = 0; pos<180; pos+=1)     // 180도에서 0도로 이동합니다.
        {                                
          servox.write(pos);              // 서보를 반대방향으로 이동합니다.
          delay(15);                       // 서보 명령 간에 20ms를 기다립니다.
        } 
      }
      digitalWrite(piny1,HIGH);
      digitalWrite(piny2,LOW);
      delay(5000);
      digitalWrite(piny1,LOW);
      digitalWrite(piny2,LOW);
      digitalWrite(pinx1,HIGH);
      digitalWrite(pinx2,LOW);
      delay(5000);
      digitalWrite(pinx1,LOW);
      digitalWrite(pinx2,LOW);
      if(tmp == 0){
        int pos;
        for(pos = 0; pos <180; pos += 1)  // 0도에서 180도로 이동합니다.
        {                                  // 이동할때 각도는 1도씩 이동합니다. 
          servoy.write(pos);              // 'pos'변수의 위치로 서보를 이동시킵니다.
          delay(15);                       // 서보 명령 간에 20ms를 기다립니다.
        } 
        for(pos = 180; pos>=1; pos -=1)     // 180도에서 0도로 이동합니다.
        {                                
          servox.write(pos);              // 서보를 반대방향으로 이동합니다.
          delay(15);                       // 서보 명령 간에 20ms를 기다립니다.
        } 
      }
      cmp = 0;
    }
  }
}