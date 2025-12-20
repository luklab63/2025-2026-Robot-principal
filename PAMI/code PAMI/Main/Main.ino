#define wheel1_1 6
#define wheel1_2 5
#define wheel2_1 10
#define wheel2_2 9

#define LED_G  7
#define LED_B  8
#define LED_R  12

int pins[]={6,5,10,9,7,8,12};

#define blue_switch 2
#define yellow_switch 3
#define tirette 4

#define time_wait 85000
int tirette_etat = HIGH ;
int time_go = 0;



void setup() {
  Serial.begin(9600);

  for (int i = 0; i<7; i++){ 
    pinMode(pins[i],OUTPUT); 
  }
  pinMode(tirette, INPUT);
  pinMode(blue_switch, INPUT);
  pinMode(yellow_switch, INPUT);

  wait_before();
  Serial.println(time_go);
  wait_go();
}

void loop() {
  if (digitalRead(yellow_switch)) {
    forward_move();
  }
  else {
    stop_move();
  }
}
