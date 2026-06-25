#include "perfect_numbers.h"




int classify_number(int x){
    if (x<1){
        return ERROR;
    }
    int n=0;
    int d=1;
    while(x/2>=d){
        if(x%d==0){
            n+=d;
        }
        d++;
    }
    if(n==x){
        return PERFECT_NUMBER;
    }else if(n>x){
        return ABUNDANT_NUMBER;
    }else{
        return DEFICIENT_NUMBER;
    }

}
