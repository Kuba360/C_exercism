#include "crypto_square.h"
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdio.h>


char *ciphertext(const char *input){
    //if(input[0]=='\0')return "";
    int len=(int)strlen(input);
    char *norm_input=calloc(len+1,sizeof(char));
    if(!norm_input)return NULL;
    if(!len){
        norm_input[0]='\0';
        return norm_input;
    }
    int index=0;
    for(int i=0;i<len;i++){
        if(isalpha(input[i])){
            norm_input[index++]=tolower(input[i]);
        }else if(isdigit(input[i])){
            norm_input[index++]=input[i];
        }
    }
    norm_input[index]='\0';
    int r=1,c=1;
    while(c*r<index){
        r++;
        c++;
    }
    if(c*(r-1)>=index)r--;
    printf("len= %d, index= %d, r= %d, c= %d\n",len,index,r,c);
    char *result=calloc(index+2*c+1,sizeof(char));
    if(!result){
        free(norm_input);
        return NULL;
    }
    int re_index=0;


    for(int i=0;i<c;i++){
        int chars_in_col = 0;
        int j=i;
        while(j<index){
            result[re_index++]=norm_input[j];
            j+=c;
            chars_in_col++;
        }
        if(i<c-1){
            result[re_index++]=' ';
        }
        if (chars_in_col<r && chars_in_col>0) {
            result[re_index++] = ' ';
        }
    }

    free(norm_input);
    result[re_index]='\0';
    return result;
}