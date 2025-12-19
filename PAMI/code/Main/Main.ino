#define wheel1_1 6
#define wheel1_2 5
#define wheel2_1 10
#define wheel2_2 9



void setup() {
  pinMode(wheel1_1, OUTPUT);
  pinMode(wheel1_2, OUTPUT);
  pinMode(wheel2_1, OUTPUT);
  pinMode(wheel2_2, OUTPUT);
}

void loop() {
  digitalWrite(wheel1_1,LOW);
  digitalWrite(wheel2_1,HIGH);
  digitalWrite(wheel1_2,HIGH);
  digitalWrite(wheel2_2,LOW);
}
