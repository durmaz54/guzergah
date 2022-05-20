#include "Arduino.h"
#include "gz_hcsr.h"
#include "gz_qtr.h"
#include "gz_motor.h"

//defines
#define RXD2    16 
#define TXD2    17  

//variables
char data[10];

struct SensorSet{
    uint16_t hcsr1, hcsr2;
    int16_t lm1, lm2;
    uint16_t encoder1, encoder2;
    uint16_t qtr[8];
    int16_t yaw;
}SensorSet;


 void setup() {
    delay(1000);
    Serial.begin(9600);
    Serial2.begin(9600, SERIAL_8N1, RXD2, TXD2);
    pinMode(14, INPUT);
    gz_hcsr_init();
    gz_qtr_init();
    gz_motor_init();
 }

 void loop() {
   gz_motor_write(MOTOR1,255);
   gz_motor_write(MOTOR2,100);
   delay(10);
 }


