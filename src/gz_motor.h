#ifndef __GZ_MOTOR_H
#define __GZ_MOTOR_H
#include "Arduino.h"

#define MOTOR1_IN1      1
#define MOTOR1_IN2      1
#define MOTOR1_ENA      2
#define MOTOR2_IN1      1
#define MOTOR2_IN2      1
#define MOTOR2_ENB      0
#define MOTOR1          1
#define MOTOR2          2
#define MOTOR_PWM_FREQ  5000    
#define MOTOR_RESOLUTION       8 // çözünürlük 8 bit
#define MOTOR1_CHANNEL      0
#define MOTOR2_CHANNEL       1


void gz_motor_init(){
    pinMode(MOTOR1_IN1, OUTPUT);
    pinMode(MOTOR1_IN2, OUTPUT);
    pinMode(MOTOR1_ENA, OUTPUT);
    pinMode(MOTOR2_IN1, OUTPUT);
    pinMode(MOTOR2_IN2, OUTPUT);
    pinMode(MOTOR2_ENB, OUTPUT);
    
    ledcSetup(MOTOR1_CHANNEL, MOTOR_PWM_FREQ, MOTOR_RESOLUTION);
    ledcSetup(MOTOR2_CHANNEL, MOTOR_PWM_FREQ, MOTOR_RESOLUTION);
    
    ledcAttachPin(MOTOR1_ENA, MOTOR1_CHANNEL);
    ledcAttachPin(MOTOR2_ENB, MOTOR2_CHANNEL);

}

void gz_motor_write(uint8_t mtr, int16_t speed){

    if(speed > 255){
        speed= 255;
    }
    else if(speed < -255){
        speed=-255;
    }
    if(speed < 0){
        speed *= -1;
        if(mtr==MOTOR1){
        ledcWrite(MOTOR1_CHANNEL, speed);
        digitalWrite(MOTOR1_IN1, LOW);
        digitalWrite(MOTOR1_IN2, HIGH);
    }
    else if(mtr==MOTOR2){
        ledcWrite(MOTOR2_CHANNEL, speed);
        
        digitalWrite(MOTOR2_IN1, LOW);
        digitalWrite(MOTOR2_IN2, HIGH);
    }

    }
    else{
    if(mtr==MOTOR1){
        ledcWrite(MOTOR1_CHANNEL, speed);
        digitalWrite(MOTOR1_IN1, HIGH);
        Serial.println(speed);
        digitalWrite(MOTOR1_IN2, LOW);
    }
    else if(mtr==MOTOR2){
        ledcWrite(MOTOR2_CHANNEL, speed);
        digitalWrite(MOTOR2_IN1, HIGH);
        digitalWrite(MOTOR2_IN2, LOW);
    }
    }
    

}


void gz_motor_brake(){
    digitalWrite(MOTOR2_IN1, HIGH);
    digitalWrite(MOTOR2_IN2, HIGH);
    digitalWrite(MOTOR2_IN1, HIGH);
    digitalWrite(MOTOR2_IN2, HIGH);
}



#endif