/*********************************************************
  Project Title: Noise Detector For a Noise Free Zone
  Organisation: Soham Academy Of Human Excellence
  Website: https://ria.sohamacademy.org/
**********************************************************/

int senpin = A0;
int buzzer = 8;
int light = 13;
long val = 0;
long average = 0;
int threshold = 100;

String answ;

void setup() {
  pinMode(senpin, INPUT);
  pinMode (light, OUTPUT);
  pinMode(buzzer, OUTPUT);
  Serial.begin(9600);
  Serial.print("Noise Detector");
  }

void loop() {
  sensor();
}


void sensor() {
  for (int i = 0; i < 160; i++) {
    average = average + analogRead(senpin);
  }
  val = average / 160;
  average = 0;
  delay (10);
  Serial.print("\t");
  Serial.print(val);
  Serial.print("\t");
  Serial.print("--------");
  Serial.println(threshold);
  if (val >= 520) {
    digitalWrite(light, HIGH);
    digitalWrite(buzzer, HIGH);
    delay (2000);
    digitalWrite(light, LOW);
    digitalWrite(buzzer, LOW);
  }
}
