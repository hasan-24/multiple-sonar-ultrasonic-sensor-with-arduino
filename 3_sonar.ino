#define trigPin1 A0 //trigger pin of sonar sensor 1
#define echoPin1 A1 //echo pin of sonar sensor 1
#define trigPin2 A2 //trigger pin of sonar sensor 2
#define echoPin2 A3 //echo pin of sonar sensor 2
#define trigPin3 A4 //trigger pin of sonar sensor 3
#define echoPin3 A5 //echo pin of sonar sensor 3

long duration, distance, sensor1,sensor2,sensor3;

void setup()
{
Serial.begin (9600);
pinMode(trigPin1, OUTPUT);
pinMode(echoPin1, INPUT);
pinMode(trigPin2, OUTPUT);
pinMode(echoPin2, INPUT);
pinMode(trigPin3, OUTPUT);
pinMode(echoPin3, INPUT);
}

void loop() {
SonarSensor(trigPin1, echoPin1);
sensor1 = distance;
SonarSensor(trigPin2, echoPin2);
sensor2 = distance;
SonarSensor(trigPin3, echoPin3);
sensor3 = distance;

Serial.print("Sensor 1 distance: ");
Serial.print(sensor1);
Serial.print(" cm away.");
Serial.print("Sensor 2 distance: ");
Serial.print(sensor2);
Serial.print(" cm away.");
Serial.print("Sensor 3 distance: ");
Serial.println(sensor3);
delay(1000);
}

void SonarSensor(int trigPin,int echoPin)
{
digitalWrite(trigPin, LOW);
delayMicroseconds(2);
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);
duration = pulseIn(echoPin, HIGH);
distance = (duration/2) / 29.1;

}
