//Initialization of leds and Photoresistors
int ledPin1 = 6;
int pResistor1 = A0;
int ledPin2 = 9;
int pResistor2 = A1;
int ledPin3 = 10;
int pResistor3 = A2;
int ledPin4 = 11;
int pResistor4 = A3;
//Intervals of distance
int value1;
int value2;
int value3;
int value4;

int brightness;    // how bright the LED is
int intensity;
int fadeAmount = 5;  

long duration; // variable for the duration of sound wave travel
int distance;
int trigPin = 2;
int echoPin = 3;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(ledPin1, OUTPUT);
  pinMode(pResistor1, INPUT);
  pinMode(ledPin2, OUTPUT);
  pinMode(pResistor2, INPUT);
  pinMode(ledPin3, OUTPUT);
  pinMode(pResistor3, INPUT);
  pinMode(ledPin4, OUTPUT);
  pinMode(pResistor4, INPUT);
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an OUTPUT
  pinMode(echoPin, INPUT); // Sets the echoPin as an INPUT

}

void loop() {
  // put your main code here, to run repeatedly:
 value1 = analogRead(pResistor1);
 value2 = analogRead(pResistor2);
 value3 = analogRead(pResistor3);
 value4 = analogRead(pResistor4);

  //DISTANCE
  digitalWrite(trigPin, LOW);
  delay(200);
  // Sets the trigPin HIGH (ACTIVE) for 200 miliseconds
  digitalWrite(trigPin, HIGH);
  delay(100);
  digitalWrite(trigPin, LOW);
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH);
  // Calculating the distance
  distance = (duration-10) * 0.034 / 2; // Speed of sound wave divided by 2 (go and back)
  // Displays the distance on the Serial Monitor
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

    brightness = distance + fadeAmount;

  // reverse the direction of the fading at the ends of the fade:
  if (brightness <= 0 || brightness >= 255) {
    fadeAmount = -fadeAmount;
  }

  //Brightness depending on distance
  analogWrite(ledPin1, map(brightness, 0,40,255,0));
  analogWrite(ledPin2, map(brightness, 0,40,255,0));
  analogWrite(ledPin3, map(brightness, 0,40,255,0));
  analogWrite(ledPin4, map(brightness, 0,40,255,0));


 //Leds turning off becasue of the pResistors
 if(value1 < 200){
    digitalWrite(ledPin1, LOW);  //Turn led off
  }

  if(value2 < 200){
    digitalWrite(ledPin2, LOW);  //Turn led off
  }
  if(value3 < 200){
    digitalWrite(ledPin3, LOW);  //Turn led off
  }
  if(value4 < 200){
    digitalWrite(ledPin4, LOW);  //Turn led off
  }

  delay(500); //Small delay
}
