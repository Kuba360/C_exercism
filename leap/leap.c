#include "leap.h"

bool leap_year (int year){

    bool y;
    if (year%4==0){
        if (year%100==0){
            if (year%400==0){
               y=1; 
            }else{
                y=0;
            }
        }else{
            y=1;
        }
    }else{
        y=0;
    }



    return y;
}