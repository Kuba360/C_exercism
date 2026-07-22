#include "etl.h"
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int convert(const legacy_map *input, const size_t input_len, new_map **output){
    int lg=0;
    for(size_t i=0;i<input_len;i++){
        lg+=strlen(input[i].keys);
    }
    *output=malloc(sizeof(new_map)*lg);

    char x='a';
    int index=0;
    for(size_t j=0;j<26;j++){
       for(size_t k=0;k<input_len;k++){
            for(size_t l=0;input[k].keys[l]!='\0';l++){
                if(x==tolower(input[k].keys[l])){
                    (*output)[index].key=x;
                    (*output)[index++].value=input[k].value;
                }
            }
       }
        x++;
    }
    return lg;
}