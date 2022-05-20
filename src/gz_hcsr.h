#ifndef __GZ_HCSR_H
#define __GZ_HCSR_H

#define V (double)0.0343909
#define GZ_HCSR_ECHO1  18
#define GZ_HCSR_TRIG1   5
#define GZ_HCSR_ECHO2   3
#define GZ_HCSR_TRIG2   4


void gz_hcsr_init() {
  pinMode(GZ_HCSR_ECHO1,INPUT);
  pinMode(GZ_HCSR_ECHO2,INPUT);
  pinMode(GZ_HCSR_TRIG1,OUTPUT);
  pinMode(GZ_HCSR_TRIG2,OUTPUT);

  digitalWrite(GZ_HCSR_TRIG2,LOW);
  digitalWrite(GZ_HCSR_TRIG1,LOW);
}

void gz_hcsr1_read(uint16_t* mesafe) {
    uint16_t sure1=0;
    digitalWrite(GZ_HCSR_TRIG1,HIGH);
    delayMicroseconds(1000);
    digitalWrite(GZ_HCSR_TRIG1,LOW);
    sure1 = pulseIn(GZ_HCSR_ECHO1,HIGH)/2;
    *mesafe = V * sure1;
}

void gz_hcsr2_read(uint16_t* mesafe) {
    int sure2=0;
    digitalWrite(GZ_HCSR_TRIG2,HIGH);
    delayMicroseconds(10);
    digitalWrite(GZ_HCSR_TRIG2,LOW);
    sure2 = pulseIn(GZ_HCSR_ECHO2,HIGH)/2;
    *mesafe = V * sure2;
    digitalWrite(GZ_HCSR_TRIG2,LOW);
}



#endif