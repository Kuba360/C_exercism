#include "darts.h"
#include <math.h>
//for this exercise I will use x^2+y^2=r^2 

float score(coordinate_t pos){
    float  r=sqrtf(pos.x*pos.x + pos.y*pos.y);
    if (r>10){
        return 0;
    }else if (5<r && r<=10){
        return 1;
    }else if (1<r && r<=5){
        return 5;
    }else if (r<=1){
        return 10;
    }
    return 0;
}