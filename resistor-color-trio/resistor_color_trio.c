#include "resistor_color_trio.h"
#include <math.h>

resistor_value_t color_code(resistor_band_t resistor[]){
    resistor_value_t r;
    r.value=resistor[0]*10+resistor[1];
    r.value*=pow(10,resistor[2]%3);
    switch(resistor[2]/3){
        case 0: r.unit=OHMS; break;
        case 1: r.unit=KILOOHMS; break;
        case 2: r.unit=MEGAOHMS; break;
        case 3: r.unit=GIGAOHMS; break;
    }
    if (r.value%1000==0&& r.value/1000>1 && r.unit==OHMS){
        r.value/=1000;
        r.unit=KILOOHMS;
    }
    return r;
}
//AI generated
//#include "resistor_color_trio.h"
//
//static int ipow(int base, int exp) {
//    int result = 1;
//    while (exp-- > 0) result *= base;
//    return result;
//}
//
//resistor_value_t color_code(resistor_band_t resistor[]) {
//    resistor_value_t r;
//    int value = (resistor[0] * 10 + resistor[1]) * ipow(10, resistor[2]);
//
//    if (value % 1000000000 == 0 && value > 0) {
//        r.value = value / 1000000000;
//        r.unit = GIGAOHMS;
//    } else if (value % 1000000 == 0 && value > 0) {
//        r.value = value / 1000000;
//        r.unit = MEGAOHMS;
//    } else if (value % 1000 == 0 && value > 0) {
//        r.value = value / 1000;
//        r.unit = KILOOHMS;
//    } else {
//        r.value = value;
//        r.unit = OHMS;
//    }
//    return r;
//}