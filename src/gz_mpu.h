#ifndef __GZ_MPU_H
#define __GZ_MPU_H

#include "Wire.h"
#include "MPU6050_light.h"

#define SCL1     22
#define SDA1     21

MPU6050 mpu(Wire);

void gz_mpu_init(){
    Wire.begin(SDA1, SCL1); 
    mpu.begin();
    mpu.calcOffsets(true,true);
}

void gz_mpu_read(int16_t* yaw){
    mpu.update();
    *yaw = (int16_t)mpu.getAngleZ();
}

#endif