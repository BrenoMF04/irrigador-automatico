#include <ESP32Servo.h>

const int sensorPin = 15;
const int servoPin = 19;
const int ledPin = 18;

const int umidadeMinima = 1600;

Servo myservo;

void setup(){
  Serial.begin(115200);
  pinMode(ledPin, OUTPUT);
  pinMode(15, INPUT);
  myservo.attach(servoPin);
}

void loop(){
  int umidade = analogRead(15);
  Serial.print("Valor da umidade: ");
  Serial.println(umidade);

  if(umidade < umidadeMinima){
    digitalWrite(ledPin, HIGH);
  for(int pos = 0; pos<= 180; pos++){
    myservo.write(pos);
    delay(5);
  }
    for(int pos = 180; pos >= 0; pos--){
      myservo.write(pos);
      delay(5);
    }
  }else{
    digitalWrite(ledPin, LOW);
    myservo.write(90);
  }
  delay(100);
} 