// code pami pimment robotique 2025-2026
// luklab63 on github

#include "test.hpp"

#include <Wire.h>

//#define MPU_addr 0x68  // I2C address of the MPU-6050
//int16_t AcX, AcY, AcZ, Tmp, GyX, GyY, GyZ;
//int angle = 0;

#define wheel1_1 6
#define wheel1_2 5
#define wheel2_1 10
#define wheel2_2 9

#define fast_speed 255 // si c pas 255 ca ne marche pas 
#define slow_speed 122 // la sa ne chage rien si on change la vitesse

#define LED_G  7
#define LED_B  8
#define LED_R  12

#define SERVO_PIN 11
#define MIN_PULSE 500   // en microsecondes (1 ms)
#define MAX_PULSE 2500  // en microsecondes (2 ms)

int pins[]={7,8,12,2,3,4,13};

#define blue_switch 2
#define yellow_switch 3
#define tirette 4
#define ARU 13

#define time_wait 2000  // mettre a 8500
int tirette_etat = HIGH ;
int time_go = 0;
//int mpu_0 =0;

void setup() {
  
  Serial.begin(9600);

  init_ALL();
  
  //ARU_ON();
  //wait_before();
  //Serial.println(time_go);
  //wait_go();               //   /!\ ne pas oublier de uncomment quand pas besoin de test
  
  //MPU_moyen();
  //Serial.print(time_go);


  //angle = 0;
  time_go = millis();
  Serial.println(time_go);
  
  while (digitalRead(ARU)==LOW && millis()-time_go < 3500) {
    if (digitalRead(yellow_switch)) {
      forward_move();
    }
    else {
      stop_move();
    }
  }
}

void loop() {

}
