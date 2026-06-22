#include "collatz_conjecture.h"

int steps(int start){
    int n=0;
    if(start>=1){
        while(start!=1){
            if (start%2==0){
                start=start/2;
                n++;
            }else if(start%2!=0){
                start=start*3+1;
                n++;
            }
        }
    }else{
        return -1;
    }
    return n;
}