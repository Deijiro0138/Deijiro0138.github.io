#include "../include/msgeq7.h"

MSGEQ7::MSGEQ7(){}

void MSGEQ7::setup(){
    pinMode(strobe,OUTPUT);
    pinMode(reset,OUTPUT);
}

void MSGEQ7::get_data(LED_BAR &led_bar){
  digitalWrite(reset, HIGH);
  delay(5);
  digitalWrite(reset, LOW);

  for (int i=0; i<7; i++){
      digitalWrite(strobe,LOW);
      delayMicroseconds(35);

      spectrumRead_L[i] = analogRead(dataout_l);
      spectrumRead_R[i] = analogRead(dataout_r);

      digitalWrite(strobe,HIGH);
      
  }
  delay(1);
  led_bar.led_dynamic(spectrumRead_L,spectrumRead_R);
}
