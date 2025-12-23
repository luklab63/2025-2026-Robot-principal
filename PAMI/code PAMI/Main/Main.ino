// code pami pimment robotique 2025-2026
// luklab63 on github


#include <Wire.h>

#define MPU_addr 0x68  // I2C address of the MPU-6050
int16_t AcX, AcY, AcZ, Tmp, GyX, GyY, GyZ;
int angle = 0;

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
  MPU_init();

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
