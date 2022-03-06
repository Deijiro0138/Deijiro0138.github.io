#ifndef LED_BAR_h
#define LED_BAR_h
#include "Tlc5940.h"

#define BAR_L 11
#define BAR_R 10
#define MAX_BRIGHTNESS 4095

class LED_BAR{
    public:
    LED_BAR();

    const int band[10] = {203,256,322,406,512,645,813,1024,1290,1625};
    const int8_t bar_num[7] = {12,13,14,15,5,6,7};
    const int bar_side[2] = {11,10};
    void setup();
    void led_blinking(int data[7]);
    void led_dynamic(int data_L[7], int data_R[7]);

    private:
};

#endif