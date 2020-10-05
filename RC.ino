//dmetrosk

//M1 M2
int enA = 5;
int in1 = 3;
int in2 = 4;

//M3 M4
int enB = 6;
int in3 = 7;
int in4 = 8;

int trigPin = 11;
int echoPin = 12;

long duration, cm;

void setup() {

  Serial.begin(9600);
  
  pinMode(enA, OUTPUT);
  pinMode(enB, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);

  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  digitalWrite(trigPin, LOW);
  delayMicroseconds(5);

}

void loop() {
 
  long x;
//x = getDistance();
//Serial.print("cm ");
//Serial.println(x);

  if(Serial.available())
  { 
    char c=Serial.read();  
    Serial.println(c);


 //Forward
 /*if(x<7)
 {
      digitalWrite(enA,HIGH);
      digitalWrite(enB,HIGH);
      
      digitalWrite(in1,LOW);
      digitalWrite(in2,HIGH);
      digitalWrite(in3,LOW);
      digitalWrite(in4,HIGH);
      return;
 }
 else{*/
    if(c=='1'){     
for(int m=70;m<255;m++)
     {  analogWrite(enA,m);
        analogWrite(enB,m);
      
      digitalWrite(enA,HIGH);
      digitalWrite(enB,HIGH);
      
      digitalWrite(in1,LOW);
      digitalWrite(in2,LOW);
      digitalWrite(in3,HIGH);
      digitalWrite(in4,LOW);
        Serial.println(m);
  delay(1000);
     } }
    else if(c=='3')
    {
      //Backward
       digitalWrite(enA,HIGH);
      digitalWrite(enB,HIGH);
      
      digitalWrite(in1,LOW);
      digitalWrite(in2,HIGH);
      digitalWrite(in3,LOW);
      digitalWrite(in4,HIGH);
    }
    else if(c=='2')
    {
      //Right
       digitalWrite(enA,HIGH);
      digitalWrite(enB,HIGH);
      
      digitalWrite(in1,LOW);
      digitalWrite(in2,HIGH);
      digitalWrite(in3,HIGH);
      digitalWrite(in4,LOW);
    }
    else if(c=='4')
    {
      //Left
       digitalWrite(enA,HIGH);
      digitalWrite(enB,HIGH);
      
      digitalWrite(in1,HIGH);
      digitalWrite(in2,LOW);
      digitalWrite(in3,LOW);
      digitalWrite(in4,HIGH);
    }
    else if(c=='0')
    {
      digitalWrite(enA,HIGH);
      digitalWrite(enB,HIGH);
      
      digitalWrite(in1,LOW);
      digitalWrite(in2,LOW);
      digitalWrite(in3,LOW);
      digitalWrite(in4,LOW);
    }
    return;
  }
 // }
  
}

long getDistance() {
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  cm=(duration/2)/29.1;
  return cm;
}


