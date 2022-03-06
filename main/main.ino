#include "./include/led_bar.h"
#include "./include/msgeq7.h"

MSGEQ7 msgeq7;
LED_BAR led_bar;

void setup(){
  Serial.begin(9600);

  msgeq7.setup();
  led_bar.setup();
}

void loop(){
  msgeq7.get_data(led_bar);
}