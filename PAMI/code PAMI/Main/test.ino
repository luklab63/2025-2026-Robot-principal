
void wait_before(){
  digitalWrite(LED_R, HIGH);
  while(tirette_etat== HIGH){
    tirette_etat = digitalRead(tirette);
  }
  digitalWrite(LED_R, LOW);
  time_go = millis();

}

void wait_go(){
  while(digitalRead(tirette) == LOW || millis()-time_go<time_wait  ){
    if(digitalRead(yellow_switch)){
      digitalWrite(LED_G,HIGH);
      digitalWrite(LED_B, LOW);
    }
    else {
      digitalWrite(LED_B, HIGH);
      digitalWrite(LED_G, LOW);
    }
      
  }
  digitalWrite(LED_B, LOW);
  digitalWrite(LED_G, LOW);
  digitalWrite(LED_R, HIGH);
}

void forward_move(){
    digitalWrite(wheel1_1,HIGH);
    digitalWrite(wheel2_1,LOW);
    digitalWrite(wheel1_2,LOW);
    digitalWrite(wheel2_2,HIGH);
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