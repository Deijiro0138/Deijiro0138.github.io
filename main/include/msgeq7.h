#ifndef MSGEQ7_h
#define MSGEQ7_h

#include "led_bar.h"
#define strobe 4
#define reset 5
#define dataout_l A0
#define dataout_r A1

class MSGEQ7{
    public:
    MSGEQ7();
    
    int spectrumRead_L[7] = {};
    int spectrumRead_R[7] = {};

    void setup();
    void get_data(LED_BAR &led_bar);

    private:
};

#endif