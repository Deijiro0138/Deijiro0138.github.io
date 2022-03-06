#include "../include/led_bar.h"
#include "Tlc5940.h"

LED_BAR::LED_BAR(){}

void LED_BAR::setup(){
    Tlc.init();
    pinMode(BAR_L,OUTPUT);
    pinMode(BAR_R,OUTPUT);
    for (int ch=0; ch<7; ch++){
        pinMode(ch,OUTPUT);
    }
}

void LED_BAR::led_blinking(int data[7]){
    Tlc.clear();
    for (TLC_CHANNEL_TYPE ch=0; ch<10; ch++){
        if (data[ch] >= band[ch]){
            Tlc.set(ch,MAX_BRIGHTNESS);
        }else{
            break;
        }
    }
    Tlc.update();
}

void LED_BAR::led_dynamic(int data_L[7],int data_R[7]){
    for (int i=0; i<2; i++){
        digitalWrite(bar_side[i%2],HIGH);
        digitalWrite(bar_side[(i+1)%2],LOW);
        for (int ch=0; ch<7; ch++){
            digitalWrite(bar_side[ch],HIGH);
            digitalWrite(bar_side[(ch+1)%7],LOW);
            digitalWrite(bar_side[(ch+2)%7],LOW);
            digitalWrite(bar_side[(ch+3)%7],LOW);
            digitalWrite(bar_side[(ch+4)%7],LOW);
            digitalWrite(bar_side[(ch+5)%7],LOW);
            digitalWrite(bar_side[(ch+6)%7],LOW);

            if (i == 0){
                led_blinking(data_R);
            }else{
                led_blinking(data_L);
            }
        }
        delay(5);
    }
}

