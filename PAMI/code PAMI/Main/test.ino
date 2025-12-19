
void wait_before(){
  digitalWrite(LED_R, HIGH);
  while(tirette_etat){
    tirette_etat = digitalRead(tirette);
  }
  time_go = millis();
}

void wait_go(){
  while(millis()-time_go<time_wait || tirette_etat == LOW){
    digitalWrite(LED_R,HIGH);
    digitalWrite(LED_G, HIGH);
  }
}