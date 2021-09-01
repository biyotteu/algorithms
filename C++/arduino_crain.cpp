#include <Servo.h>
#include <Scheduler.h>

Servo servo;
int mox_front=47,mox_back=51;
int moy_left=49,moy_right=53;
int moz_up,moz_down;//dc모터
int sv = 7;//서브모터
int front,back,left,right //리미트버튼조작부(조작과 반대로 움직임)
int cbtt = 5,sbtt = 6; // 잡기버튼과 시작버튼
int step;//현재 단계
int time_limit = 20000;//게임 시간
int down_time,return_time;//집게 내려가는 시간 
int cheat,cmp;
unsigned long start_time;

void move_front(){
  digitalWrite(mox_up,HIGH);
  digitalWrite(mox_down,LOW);
}
void move_back(){
  digitalWrite(mox_down,HIGH);
  digitalWrite(mox_up,LOW);
}
void move_right(){
  digitalWrite(moy_right,HIGH);
  digitalWrite(moy_left,LOW);
}
void move_left(){
  digitalWrite(moy_left,HIGH);
  digitalWrite(moy_right,LOW);
}
void move_down(){
  digitalWrite(moz_down,HIGH);
  digitalWrite(moz_up,LOW);
}
void move_up(){
  digitalWrite(moz_up,HIGH);
  digitalWrite(moz_down,LOW);
}
void stop_bf(){
  digitalWrite(mox_front,LOW);
  digitalWrite(mox_back,LOW);
}
void stop_lr(){
  digitalWrite(moy_left,LOW);
  digitalWrite(moy_right,LOW);
}
void stop_ud(){
  digitalWrite(moz_up,LOW);
  digitalWrite(moz_down,LOW);
}
void _catch(){
  move_down();
  for(int i=100;i>=0;i--){
    servo.write(angle); 
    delay(10);
  }
  delay(down_time);
  stop_ud();
  delay(500);
  for(int i=0;i<=100;i++){
    servo.write(angle); 
    delay(10);
  }
  move_up();
  delay(down_time);
  stop_ud();
}
void _return(){
  move_front();
  move_left();
  delay(500);
  if(!cmp)  servo.write(80);
  delay(return_time);
  stop_lr();
  stop_bf();
  for(int i=80;i>=0;i--){
    servo.write(angle); 
    delay(10);
  }
}
void setup() {
  // put your setup code here, to run once:
  pinMode(mox_front,OUTPUT);
  pinMode(mox_back,OUTPUT);
  pinMode(moy_left,OUTPUT);
  pinMode(moy_right,OUTPUT);
  pinMode(moz_down,OUTPUT);
  pinMode(moz_up,OUTPUT);
  pinMode(sub,OUTPUT);
  pinMode(front,INPUT);
  pinMode(back,INPUT);
  pinMode(left,INPUT);
  pinMode(right,INPUT);
  pinMode(cbtt,INPUT);
  pinMode(sbtt,INPUT);
  pinMode(cheat,INPUT);
  servo.attach(sv);
  step = 0;
  cmp = 0;
}


void loop() {
  if(digitalRead(cheat)) cmp = 1;
  if(digitalRead(sbtt)){
    start_time = millis();
    step = 1;
  }
  if(step == 1){
    if(digitalRead(cbtt)){
      ++step;
    }else{
      if(digitalRead(front)) move_front();
      else if(digitalRead(back)) move_back();
      else stop_bf();
      if(digitalRead(left)) move_left();
      else if(digitalRead(right)) move_right();
      else stop_lr();
      if(millis()-start_time >= time_limit * 1000) ++step;
    }
  }
  if(step == 2){
    stop_lr();
    stop_bf();
    _catch();
    ++step;
  }
  if(step == 3){
      _return();
      step = 0;
  }
}