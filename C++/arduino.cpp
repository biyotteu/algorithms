int pin0 = 4;
int pin1 = 5;
int pin2 = 6;
int pin3 = 7;
int led = 2;
int sw = 3;
int state = LOW,cmp;
int reading;  
unsigned long current_time,start_time;

void setup() {
  Serial.begin(9600);
  pinMode(pin0,OUTPUT);
  pinMode(pin1,OUTPUT);
  pinMode(pin2,OUTPUT);
  pinMode(pin3,OUTPUT);
  pinMode(led,OUTPUT);
  pinMode(sw, INPUT_PULLUP);
  start_time = 0;
  cmp = 0;
}

void loop() {    
  current_time = millis();
  reading = digitalRead(sw);
  Serial.println(reading);

  if (reading == LOW) {
    start_time = current_time;
    cmp = 1;
    digitalWrite(led, HIGH);
    delay(3500);
  }

  if(cmp && current_time <= start_time+5500){
    digitalWrite(pin0,HIGH);
    digitalWrite(pin1,LOW);
    digitalWrite(pin2,HIGH);
    digitalWrite(pin3,LOW);
  }else{
      digitalWrite(pin0,LOW);
      digitalWrite(pin1,LOW);
      digitalWrite(pin2,LOW);
      digitalWrite(pin3,LOW);
      digitalWrite(led, LOW);
      cmp = 0;
  }
}