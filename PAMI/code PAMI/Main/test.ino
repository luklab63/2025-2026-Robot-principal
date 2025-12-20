
void wait_before(){
  digitalWrite(LED_B, HIGH);
  while(tirette_etat== HIGH){
    tirette_etat = digitalRead(tirette);
  }
  time_go = millis();

}

void wait_go(){
  while(millis()-time_go<time_wait || digitalRead(tirette)==LOW){
    digitalWrite(LED_B,HIGH);
    digitalWrite(LED_G, HIGH);
  }
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