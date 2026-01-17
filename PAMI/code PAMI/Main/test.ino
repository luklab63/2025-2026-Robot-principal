void ARU_ON(){
  while (digitalRead(ARU)) {
    digitalWrite(LED_R, HIGH);
    delay(100);
    digitalWrite(LED_R, LOW);
    delay(100);
  }
}

void wait_before(){
  while(tirette_etat== HIGH){
    if (digitalRead(yellow_switch)) {
      digitalWrite(LED_G, HIGH);
      digitalWrite(LED_B, LOW);
    }
    else if (digitalRead(blue_switch)) {
      digitalWrite(LED_B, HIGH);
      digitalWrite(LED_G, LOW);
    }

    tirette_etat = digitalRead(tirette);
  }
  digitalWrite(LED_B, LOW);
  digitalWrite(LED_G, LOW);
  time_go = millis();
}

void wait_go(){
  blink = millis();
  while(millis()-time_go<100  ){
    while(digitalRead(tirette) == LOW && millis()-time_go < time_wait){

      if (digitalRead(yellow_switch)) {

        delay(1000);
        digitalWrite(LED_G, HIGH);
        delay(1000);
        digitalWrite(LED_G, LOW);
        
      }

      else if (digitalRead(blue_switch)) {

        delay(1000);
        digitalWrite(LED_B, HIGH);
        delay(1000);
        digitalWrite(LED_B, LOW);

      }
    }
  }
  digitalWrite(LED_B, LOW);
  digitalWrite(LED_G, LOW);
  digitalWrite(LED_R, HIGH);
}

void forward_move(){
  
  get_angle();
  if (angle>20){
    Serial.println("angle>20");
    analogWrite(wheel1_1,fast_speed);
    analogWrite(wheel1_2,0);
    analogWrite(wheel2_2,slow_speed);
    analogWrite(wheel2_1,0);
  }
  else if (angle<20) {
    Serial.println("angle<20");
    analogWrite(wheel1_1,slow_speed);
    analogWrite(wheel1_2,0);
    analogWrite(wheel2_2,fast_speed);
    analogWrite(wheel2_1,0);
  }

}

void stop_move(){
  analogWrite(wheel1_1,0);
  analogWrite(wheel1_2,0);
  analogWrite(wheel2_2,0);
  analogWrite(wheel2_1,0);
}

void backward_move(){
  analogWrite(wheel1_1,0);
  analogWrite(wheel2_1,255);
  analogWrite(wheel1_2,255);
  analogWrite(wheel2_2,0);  
}

void MPU_init(){
  Wire.begin();

  Wire.beginTransmission(MPU_addr);

  Wire.write(0x6B);  // PWR_MGMT_1 register
  Wire.write(0);     // set to zero (wakes up the MPU-6050)

  Wire.endTransmission(true);
}

void get_gyro(){
  Wire.beginTransmission(MPU_addr);

  Wire.write(0x47);  // starting with register 0x3B (ACCEL_XOUT_H)

  Wire.endTransmission(false);

  Wire.requestFrom(MPU_addr, 14, true);  // request a total of 14 registers

  GyZ = Wire.read() << 8 | Wire.read();  // 0x47 (GYRO_ZOUT_H) & 0x48 (GYRO_ZOUT_L)
  //AcZ = Wire.read() << 8 | Wire.read();  // 0x3F (ACCEL_ZOUT_H) & 0x40 (ACCEL_ZOUT_L)

  Serial.print(" | GyZ = "); Serial.println(GyZ);
  //Serial.print(" | AcZ = "); Serial.println(AcZ);
  Serial.println();

}

void get_angle() {
  get_gyro();
  if (GyZ<550 && GyZ>150){
    angle = angle;
  }
  else if (GyZ>550) {
    angle= angle + GyZ -550;
  }
  else if (GyZ<150) {
    angle =angle + GyZ -150;
  }
  Serial.println(angle);
  delay(100);
}

void ARU_STOP(){
  digitalWrite(LED_G, LOW);

  digitalWrite(SERVO_PIN, HIGH);
  delayMicroseconds(map(30, 0, 180, MIN_PULSE, MAX_PULSE));
  digitalWrite(SERVO_PIN, LOW);

  digitalWrite(LED_R,HIGH);
  delay(300);

  digitalWrite(SERVO_PIN, HIGH);
  delayMicroseconds(map(90, 0, 180, MIN_PULSE, MAX_PULSE));
  digitalWrite(SERVO_PIN, LOW);

  digitalWrite(LED_R,LOW);
  delay(300);

  digitalWrite(SERVO_PIN, HIGH);
  delayMicroseconds(map(150, 0, 180, MIN_PULSE, MAX_PULSE));
  digitalWrite(SERVO_PIN, LOW);

  digitalWrite(LED_R,HIGH);
  delay(300);

  digitalWrite(SERVO_PIN, HIGH);
  delayMicroseconds(map(90, 0, 180, MIN_PULSE, MAX_PULSE));
  digitalWrite(SERVO_PIN, LOW);

  digitalWrite(LED_R,LOW);
  delay(300);

}

void init_ALL(){

  for (int i = 0; i<3; i++){ 
    pinMode(pins[i],OUTPUT); 
  }
  
  pinMode(tirette, INPUT);
  pinMode(blue_switch, INPUT);
  pinMode(yellow_switch, INPUT);
  pinMode(ARU, INPUT);
  MPU_init();
}

void servo(){
  digitalWrite(SERVO_PIN, HIGH);
  delayMicroseconds(map(90, 0, 180, MIN_PULSE, MAX_PULSE));
  digitalWrite(SERVO_PIN, LOW);

  digitalWrite(LED_B, HIGH);
  delay(100);
  digitalWrite(LED_G, HIGH);
  delay(100);
  digitalWrite(LED_R, HIGH);
  delay(100);

  digitalWrite(SERVO_PIN, HIGH);
  delayMicroseconds(map(30, 0, 180, MIN_PULSE, MAX_PULSE));
  digitalWrite(SERVO_PIN, LOW);

  delay(300);

  digitalWrite(SERVO_PIN, HIGH);
  delayMicroseconds(map(90, 0, 180, MIN_PULSE, MAX_PULSE));
  digitalWrite(SERVO_PIN, LOW);

  digitalWrite(LED_B, LOW);
  delay(100);
  digitalWrite(LED_G, LOW);
  delay(100);
  digitalWrite(LED_R, LOW);
  delay(100);

  digitalWrite(SERVO_PIN, HIGH);
  delayMicroseconds(map(150, 0, 180, MIN_PULSE, MAX_PULSE));
  digitalWrite(SERVO_PIN, LOW);

  delay(300);

}
