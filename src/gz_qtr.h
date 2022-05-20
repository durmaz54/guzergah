#ifndef __GZ_QTR_H
#define __GZ_QTR_H

#include <QTRSensors.h>


QTRSensors qtr;
const uint8_t SensorCount = 8;
uint16_t sensorValues[SensorCount];
void gz_qtr_init(){
  
  qtr.setTypeAnalog();
  qtr.setSensorPins((const uint8_t[]){34, 35, 32, 33, 25, 26, 27, 14}, SensorCount);
  qtr.calibrate();
}

void gz_qtr_read(uint16_t* data){
  *data = qtr.readLineBlack(sensorValues);
}


#endif