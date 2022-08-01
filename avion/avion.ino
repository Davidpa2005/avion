//Variables LED´s  //
int led_rojo1 = 27;
int led_rojo2 = 26;
int led_rojo3 = 24;
int led_verde1 = 28;
int led_verde2 = 29;
int led_blanca1 = 3;
int led_blanca2 = 5;
int led_amarillo1 = 25;




// Variables Sensor Luz //
int sensor = A0;
int valor = 0;

// Variables Pulsadores //
int pulsador1 = 36;
int estadopulsador1 = 0; 


//Variables Ultrasonidos//
int TRIG = 23;
int ECHO = 22;
long duracion;
int distancia;

//Variables servo//
#include<Servo.h>
Servo servo1 ;
Servo servo2;
int posicion = 0; 


//Variables del joistick//

int x ;
int ang_x ;
int Pin_x = A1;
int Pin_y = A2;
int y ;
int ang_y ;
int SW = 45 ;



void setup() {

// Pin LED´s //
pinMode(led_rojo1,OUTPUT);
pinMode(led_verde1,OUTPUT);
pinMode(led_rojo2, OUTPUT);
pinMode(led_verde2, OUTPUT);
pinMode(led_blanca1,OUTPUT);
pinMode(led_blanca2, OUTPUT);
pinMode(led_rojo3, OUTPUT);
pinMode(led_amarillo1, OUTPUT);



// Pin de Pulsadores //
pinMode(pulsador1, INPUT);


// Pin del Sensor de Luz //
pinMode(sensor, INPUT);
Serial.begin(9600);


//Pin del Sensor de Ultrasonidos
pinMode(TRIG, OUTPUT);
pinMode(ECHO, INPUT);
Serial.println(distancia);

//Pin de Servos//
servo1.attach(6);
servo2.attach(9);
servo1.write(90);


//Pin de Joistick//
Serial.begin(115200);
pinMode(SW, INPUT_PULLUP);



}

void loop() {
  
//Interuptor para que FUNCIONE TODO //  
estadopulsador1 = digitalRead(pulsador1); 
if (estadopulsador1 == LOW){ 
  
  x = analogRead(Pin_x);
  y = analogRead(Pin_y);

  ang_x = map( x, 0, 1023, 0, 180 );
  ang_y = map( y, 0, 1023, 0, 180 );
  
  
  Serial.println("XXXXXXX");
  Serial.println(ang_x);
  Serial.println("YYYYYYY");
  Serial.println(ang_y);
  

  
  servo1.write(ang_y);
  servo2.write(ang_x);
  
   
  //Condiciones del Sensor Ultrasonidos//
  digitalWrite(TRIG, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG, LOW);
  duracion = pulseIn(ECHO, HIGH);
  distancia = duracion * 0.034 / 2 ;
  
  if(distancia < 30 ){
    digitalWrite(led_rojo3, HIGH);
    delay(500);
    digitalWrite(led_rojo3, LOW);
    digitalWrite(led_amarillo1, HIGH);
    delay(500); 
    digitalWrite(led_amarillo1, LOW);
    
  }
  else{
    digitalWrite(led_amarillo1, LOW);
    digitalWrite(led_rojo3, LOW);
    }

  
  //Luz blanca se regulña por la intensidad de la luz //
  valor = analogRead(sensor);
  //Serial.println(valor);
  analogWrite(led_blanca1 , 255 - (valor / 2)); 
  analogWrite(led_blanca2, 255- (valor / 2)); 


// PARTE INTERMITENTE DE LOS LED VERDE Y ROJO //
  estadopulsador1 = digitalRead(pulsador1);
  if (estadopulsador1 == LOW){
    digitalWrite(led_rojo1, HIGH);
    digitalWrite(led_rojo2, HIGH);
    delay(500);
    digitalWrite(led_rojo1, LOW);
    digitalWrite(led_rojo2, LOW);
    digitalWrite(led_verde1, HIGH);
    digitalWrite(led_verde2, HIGH);
    delay(500);
    digitalWrite(led_verde1, LOW);
    digitalWrite(led_verde2, LOW);
   }
   else{
    digitalWrite(led_rojo1, LOW);
    digitalWrite(led_rojo2, LOW);
    digitalWrite(led_verde1, LOW);
    digitalWrite(led_verde2, LOW);
  }
}
else {
  digitalWrite(led_rojo1, LOW);  
  digitalWrite(led_rojo2, LOW);  
  digitalWrite(led_verde1, LOW);   
  digitalWrite(led_verde2, LOW); 
  digitalWrite(led_blanca1, LOW);  
  digitalWrite(led_blanca2, LOW);   

}




  
}
