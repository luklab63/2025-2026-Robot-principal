

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
  while(millis()-time_go<100  ){
    while(digitalRead(tirette) == LOW && millis()-time_go<time_wait  ){

      blink = millis();
      if (digitalRead(yellow_switch)) {
        if (millis()-blink > 1000) {
          if (blink_count == 0) {
            digitalWrite(LED_G, HIGH);
            blink_count = 1;
          }
          else if (blink_count == 0) {
            digitalWrite(LED_G, LOW);
            blink_count = 0;
          }
          blink =millis();
        }
      }


      else if (digitalRead(blue_switch)) {
        if (millis()-blink > 1000) {
          if (blink_count == 0) {
            digitalWrite(LED_B, HIGH);
            blink_count = 1;
          }
          else if (blink_count == 0) {
            digitalWrite(LED_B, LOW);
            blink_count = 0;
          }
          blink = millis();
        }
      }
  }
    }
    digitalWrite(LED_B, LOW);
    digitalWrite(LED_G, LOW);
    digitalWrite(LED_R, HIGH);
  }
}

void forward_move(){
  
  get_angle();
  if (angle>50){
    analogWrite(wheel1_1,255);
    digitalWrite(wheel1_2,LOW);
    analogWrite(wheel2_2,122);
    digitalWrite(wheel2_1,LOW);
  }
  else if (angle<50) {
    analogWrite(wheel1_1,122);
    digitalWrite(wheel1_2,LOW);
    analogWrite(wheel2_2,255);
    digitalWrite(wheel2_1,LOW);
  }
}

void stop_move(){
  digitalWrite(wheel1_1,LOW);
  digitalWrite(wheel2_1,LOW);
  digitalWrite(wheel1_2,LOW);
  digitalWrite(wheel2_2,LOW);
}

void backward_move(){
  digitalWrite(wheel1_1,LOW);
  digitalWrite(wheel2_1,HIGH);
  digitalWrite(wheel1_2,HIGH);
  digitalWrite(wheel2_2,LOW);  
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
  myservo.write(30);
  digitalWrite(LED_R,HIGH);
  delay(300);

  myservo.write(90);
  digitalWrite(LED_R,LOW);
  delay(300);

  myservo.write(150);
  digitalWrite(LED_R,HIGH);
  delay(300);

  myservo.write(90);
  digitalWrite(LED_R,LOW);
  delay(300);

}

void init_ALL(){
  Serial.begin(9600);

  for (int i = 0; i<7; i++){ 
    pinMode(pins[i],OUTPUT); 
  }
  pinMode(tirette, INPUT);
  pinMode(blue_switch, INPUT);
  pinMode(yellow_switch, INPUT);
  pinMode(ARU, INPUT);
  myservo.attach(SERVO);
  myservo.write(90);
  MPU_init();
}

void servo(){
  myservo.write(90);

  digitalWrite(LED_B, HIGH);
  delay(100);
  digitalWrite(LED_G, HIGH);
  delay(100);
  digitalWrite(LED_R, HIGH);
  delay(100);

  myservo.write(30);
  delay(300);
  myservo.write(90);

  digitalWrite(LED_B, LOW);
  delay(100);
  digitalWrite(LED_G, LOW);
  delay(100);
  digitalWrite(LED_R, LOW);
  delay(100);

  myservo.write(150);
  delay(300);

}