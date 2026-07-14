#include "phone_number.h"
#include <stddef.h>
#include <string.h>


char *phone_number_clean(const char *input){
    size_t len = strlen(input);
    char digits[len +1];
    int count=0;
    for (size_t i=0;input[i]!='\0';i++){
       if(input[i]>='0' && input[i]<='9'){
            digits[count]=input[i];
            count++;
       } 
    }
    digits[count]='\0';
}