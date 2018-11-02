#include <AFMotor.h>
#define PIN_L 2
#define Holes_Disc 23

volatile unsigned int pulses;
float rpm;
unsigned long timeOld;

AF_DCMotor motor1(1);
AF_DCMotor motor2(2);
AF_DCMotor motor3(3);
AF_DCMotor motor4(4);

const int trigPin = 32;
const int echoPin = 33;

const int speed_max = 250;
const int speed_min = 50;
const int dist_max = 70;
const int dist_min = 5;

long duration;
int distance;
char control_button[1];

void setup()
{
  pinMode(PIN_L, INPUT);
  pulses = 0;
  timeOld = 0;
  attachInterrupt(digitalPinToInterrupt(PIN_L), counter, FALLING);

  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  //Velocity(100);

  Serial.begin(57600);
  Serial1.begin(57600);
}

void loop()
{
  /*ultrasonic(trigPin, echoPin);
  Serial.print("distance: ");
  Serial.println(distance);
  */
  if (Serial1.available() > 0)
  {
    control_button[0] = Serial1.read();
    switch (control_button[0])
    {
      case 'w':
        Forward();
        break;
      case 'a':
        Left();
        break;
      case 's':
        Backward();
        break;
      case 'd':
        Right();
        break;
      case 'v':
        Stop();
        break;
    }
  }
  //FuzzyLogic();
}

void FuzzyLogic()
{
  Speed_Counter();
  float k = 45;
  float prev_vel = rpm;
  float current_vel = k * (pow(distance, 2) / prev_vel);
  int vel = int(current_vel);

  if (distance > dist_max)
    vel = speed_max;
  if (distance < dist_min)
    vel = speed_min;
  if (vel > speed_max)
    Velocity(speed_max);
  if (vel < speed_min)
    Velocity(speed_min);

  Velocity(vel);
  
  if (distance <= 10)
  {
    Stop();
  }
}

void ultrasonic(int trigPin, int echoPin)
{
  digitalWrite(trigPin, LOW);
  delay(10);

  digitalWrite(trigPin, HIGH);
  delay(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);

  distance = duration * 0.034 / 2;
}

void counter()
{
  pulses++;
}

void Speed_Counter()
{
  if (millis() - timeOld >= 1000)
  {
    detachInterrupt(digitalPinToInterrupt(PIN_L));
    rpm = (pulses * 60) / (Holes_Disc);

    timeOld = millis();
    pulses = 0;
    attachInterrupt(digitalPinToInterrupt(PIN_L), counter, FALLING);
  }
}

void Forward()
{
  motor1.run(BACKWARD);
  motor2.run(BACKWARD);
  motor3.run(FORWARD);
  motor4.run(FORWARD);
}
void Backward()
{
  motor1.run(FORWARD);
  motor2.run(FORWARD);
  motor3.run(BACKWARD);
  motor4.run(BACKWARD);
}
void Right()
{
  motor1.run(BACKWARD);
  motor2.run(FORWARD);
  motor3.run(BACKWARD);
  motor4.run(FORWARD);
}
void Left()
{
  motor1.run(FORWARD);
  motor2.run(BACKWARD);
  motor3.run(FORWARD);
  motor4.run(BACKWARD);
}
void Stop()
{
  motor1.run(RELEASE);
  motor2.run(RELEASE);
  motor3.run(RELEASE);
  motor4.run(RELEASE);
}

void Velocity(int vel)
{
  motor1.setSpeed(vel);
  motor2.setSpeed(vel);
  motor3.setSpeed(vel);
  motor4.setSpeed(vel);
}

