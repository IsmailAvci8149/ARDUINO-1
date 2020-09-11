#define TRIG 2
#define ECHO 3
#define MOTOR 4
#define SES_HIZI 343.2
#define US_SINIR 5 //ultrasonic sınırı 5 cm

double zaman;
double echoZaman;
double mesafe;

int mesafeAl();

void setup(){
  //min 2sn, max 7sn. 
  pinMode(TRIG, OUTPUT);
  pinMode(ECHO, INPUT);
  pinMode(MOTOR, OUTPUT);
}

void loop(){
  mesafe = mesafeAl();
  
  while(mesafe < US_SINIR){
    delayMicroseconds(500);
    zaman += 0.0005;
    if(zaman < 2){
      digitalWrite(MOTOR, HIGH);
      continue;
    } else if(zaman > 7) digitalWrite(MOTOR, LOW);

    digitalWrite(MOTOR, HIGH);
    mesafe = mesafeAl();
  }
}

int mesafeAl(){
  digitalWrite(TRIG, HIGH);
  delay(1);
  digitalWrite(TRIG, LOW); 
  echoZaman = pulseIn(ECHO, HIGH);
  return SES_HIZI * (echoZaman / 2);
}
