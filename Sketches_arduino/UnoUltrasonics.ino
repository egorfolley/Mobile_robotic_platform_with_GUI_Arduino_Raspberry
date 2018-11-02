const int trigPin_l = D2;
const int echoPin_l = D3;
const int trigPin_c = D11;
const int echoPin_c = D12;
const int trigPin_r = D6;
const int echoPin_r = D7;

long duration;
int distance_r, distance_l, distance_c;
String dist_l, dist_r, dist_c;

void setup()
{
  Serial.begin(57600);

  pinMode(trigPin_l, OUTPUT);
  pinMode(echoPin_l, INPUT);
  pinMode(trigPin_c, OUTPUT);
  pinMode(echoPin_c, INPUT);
  pinMode(trigPin_r, OUTPUT);
  pinMode(echoPin_r, INPUT);
}

void loop()
{
  ultrasonic(trigPin_l, echoPin_l);
  dist_l = String(distance_l, DEC);

  ultrasonic(trigPin_c, echoPin_c);
  dist_c = String(distance_c, DEC);

  ultrasonic(trigPin_r, echoPin_r);
  dist_r = String(distance_r, DEC);

  Serial.println(dist_l);
  Serial.println(dist_c);
  Serial.println(dist_r);
}

void ultrasonic(int trigPin, int echoPin)
{
  digitalWrite(trigPin, LOW);
  delay(10);

  digitalWrite(trigPin, HIGH);
  delay(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  if (trigPin == trigPin_l && echoPin == echoPin_l)
  {
    distance_l = duration * 0.034 / 2;
  }
  if (trigPin == trigPin_c && echoPin == echoPin_c)
  {
    distance_c = duration * 0.034 / 2;
  }
  if (trigPin == trigPin_r && echoPin == echoPin_r)
  {
    distance_r = duration * 0.034 / 2;
  }
}
