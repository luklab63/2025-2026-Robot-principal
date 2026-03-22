#define MOTOR1_1_PIN 6
#define MOTOR1_2_PIN 5
#define MOTOR2_1_PIN 10
#define MOTOR2_2_PIN 9

#define LED_G_PIN 7
#define LED_B_PIN 8
#define LED_R_PIN 12

#define SERVO_PIN 11

int OUTPUTS_PINS[] = {
  MOTOR1_1_PIN,
  MOTOR1_2_PIN,
  MOTOR2_1_PIN,
  MOTOR2_2_PIN,

  LED_G_PIN,
  LED_B_PIN,
  LED_R_PIN,

  SERVO_PIN,
};

#define BLUE_SWITCH_PIN 2
#define YELLOW_SWITCH_PIN 3
#define TIRRETTE_PIN 4
#define ARU_PIN 13

int INPUTS_PINS[] = {
  BLUE_SWITCH_PIN,
  YELLOW_SWITCH_PIN,
  TIRRETTE_PIN,
  ARU_PIN,
};

#define SERVO_MIN_PULSE 500   // en microsecondes (1 ms)
#define SERVO_MAX_PULSE 2500  // en microsecondes (2 ms)

#define TIME_WAIT 85000  // mettre a 85000
#define TIME_FORWARD 2700

void setup() {
  Serial.begin(9600);

  delay(3000);

  Serial.println("Initializing");

  for (int i = 0; i < sizeof(OUTPUTS_PINS) / sizeof(int); i++){
    pinMode(OUTPUTS_PINS[i], OUTPUT); 
  }
  for (int i = 3; i < sizeof(INPUTS_PINS) / sizeof(int); i++){ 
    pinMode(INPUTS_PINS[i], INPUT); 
  }

  while (digitalRead(ARU_PIN) == HIGH){
    digitalWrite(LED_R_PIN, HIGH);
  }
  digitalWrite(LED_R_PIN, LOW);

  digitalWrite(SERVO_PIN, HIGH);
  delayMicroseconds(map(30, 0, 90, SERVO_MIN_PULSE, SERVO_MAX_PULSE));
  digitalWrite(SERVO_PIN, LOW);

  Serial.println("ARU_PIN off");

  while (digitalRead(TIRRETTE_PIN)) {
    digitalWrite(LED_B_PIN, HIGH);
    delay(100);
    digitalWrite(LED_B_PIN, LOW);
  }
  Serial.println("tirrette");
  delay(TIME_WAIT);
   Serial.println("Initialisation finished");

  unsigned long time_go = millis();
  while (millis() - time_go < TIME_FORWARD && digitalRead(ARU_PIN) == LOW){
    forward_move();
    Serial.println("moooooove");
  }

 
}

void loop() {
  stop_move();
  servo();
  Serial.println("Stoooooop");
  while (digitalRead(ARU_PIN)) {
    digitalWrite(LED_R_PIN, HIGH);
  }

}

void stop_move(){
  analogWrite(MOTOR1_1_PIN,0);
  analogWrite(MOTOR1_2_PIN,0);
  analogWrite(MOTOR2_2_PIN,0);
  analogWrite(MOTOR2_1_PIN,0);
}

void spin_move(){
  analogWrite(MOTOR1_1_PIN,255);
  analogWrite(MOTOR1_2_PIN,0);
  analogWrite(MOTOR2_2_PIN,0);
  analogWrite(MOTOR2_1_PIN,255);
}

void forward_move(){
  analogWrite(MOTOR1_1_PIN,255);
  analogWrite(MOTOR1_2_PIN,0);
  analogWrite(MOTOR2_2_PIN,255);
  analogWrite(MOTOR2_1_PIN,0); 
}

void servo(){
  digitalWrite(SERVO_PIN, HIGH);
  delayMicroseconds(map(90, 0, 180, SERVO_MIN_PULSE, SERVO_MAX_PULSE));
  digitalWrite(SERVO_PIN, LOW);

  digitalWrite(LED_B_PIN, HIGH);
  delay(100);
  digitalWrite(LED_G_PIN, HIGH);
  delay(100);
  digitalWrite(LED_R_PIN, HIGH);
  delay(100);

  digitalWrite(SERVO_PIN, HIGH);
  delayMicroseconds(map(30, 0, 180, SERVO_MIN_PULSE, SERVO_MAX_PULSE));
  digitalWrite(SERVO_PIN, LOW);

  delay(300);

  digitalWrite(SERVO_PIN, HIGH);
  delayMicroseconds(map(90, 0, 180, SERVO_MIN_PULSE, SERVO_MAX_PULSE));
  digitalWrite(SERVO_PIN, LOW);

  digitalWrite(LED_B_PIN, LOW);
  delay(100);
  digitalWrite(LED_G_PIN, LOW);
  delay(100);
  digitalWrite(LED_R_PIN, LOW);
  delay(100);

  digitalWrite(SERVO_PIN, HIGH);
  delayMicroseconds(map(150, 0, 180, SERVO_MIN_PULSE, SERVO_MAX_PULSE));
  digitalWrite(SERVO_PIN, LOW);

  delay(300);
}