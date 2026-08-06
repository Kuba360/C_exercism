#include "atbash_cipher.h"
#include <stddef.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

char atbash(char c)
{
    c = tolower((unsigned char)c);
    return 'z' - (c - 'a');
}

char *atbash_encode(const char *input){
    size_t len=strlen(input);
    char tab[0xffff];
    size_t index=0;
    int group=0;
    for(size_t i=0;i<len;i++){
        if(!isalnum(input[i])) continue;;

        if(group==5){
            tab[index++]=' ';
            group=0;
        }

        if(isdigit(input[i])){
            tab[index++]=input[i];
        }else{
            tab[index++]=atbash(input[i]);
        }
    group++;

    }
    if(tab[index-1]==' '){
        tab[index-1]='\0';
    }else{
        tab[index]='\0';
    }
    char *result=malloc(index+1);
    memcpy(result,tab,index+1);
    return result;
}
char *atbash_decode(const char *input){
    size_t len =strlen(input);
    char *result=malloc(len+1);
    size_t index=0;
    for (size_t i=0;i<len;i++){
        if(input[i]==' ')continue;
        if(isdigit(input[i])){
            result[index++]=input[i];
        }else{
            result[index++]=atbash(input[i]);
        }
    }
    result[index]='\0';
    return result;
}

