#include "largest_series_product.h"
#include <string.h>
#include <ctype.h>


int64_t largest_series_product(char *digits, size_t span){
    size_t len=strlen(digits);
    if(span<1 || !len || span>len)return -1;
    size_t x=0;
    for(size_t i=0;i<=len-span;i++){
        size_t y=1;
        for(size_t j=i;j<i+span;j++){
            if(!isdigit(digits[j])) return -1;
            y*=digits[j]-'0';
        }
        x=(y>x)?y:x;
    }
    return x;
}