#include "grains.h"

uint64_t total(void);


uint64_t total(void){
    return ~0ULL;
}

uint64_t square(uint8_t index){
    if(index==0){return 0;}
    uint64_t y=1;
    for(int i=2;i<=index;i++){
        y*=2;
    }
    return y;
}
    






