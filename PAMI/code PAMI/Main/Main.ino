#define wheel1_1 6
#define wheel1_2 5
#define wheel2_1 10
#define wheel2_2 9

#define LED_R = 7
#define LED_G = 8
#define LED_B = 13

#define tirette 4
int tirette_etat = LOW 

void wait_before(){
  
  while(tirette_etat){
    tirette_etat = digitalread(tirette);
  }
}

void wait_go(){

}

void setup() {
  pinMode(wheel1_1, OUTPUT);
  pinMode(wheel1_2, OUTPUT);
  pinMode(wheel2_1, OUTPUT);
  pinMode(wheel2_2, OUTPUT);
  pinMode(tirette, INPUT);
  Pinmode(LED_R, OUTPUT);
  Pinmode(LED_G, OUTPUT);
  Pinmode(LED_B, OUTPUT);

  wait_before();
  wait_go();


}

void loop() {
  digitalWrite(wheel1_1,LOW);
  digitalWrite(wheel2_1,HIGH);
  digitalWrite(wheel1_2,HIGH);
  digitalWrite(wheel2_2,LOW);
}
