#include "eliuds_eggs.h"

int egg_count(unsigned int  x){
    unsigned int y=0;

// If input is odd then the last  bit must be 1.
    if(x%2!=0){
        y++;
        x-=1;
    }

    while(x!=0){
        unsigned int z=1;
        while(z<x){
             z <<= 1;
        }
        y++;
        if(z>x){
            x-=(z>>1);        
        }else{
            x-=z;
        }
    }
    return y;
}

// AI generated 
//int egg_count(unsigned int x) {
//    int y = 0;
//    while (x != 0) {
//        y += x & 1;    this line checks if last bit is '1', and increase y if thats true
//        x >>= 1;   this shifts all bits to the right 
//    }
//    return y;
//}
// 