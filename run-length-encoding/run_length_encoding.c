#include "run_length_encoding.h"
#include <string.h>
#include <stdlib.h>
#include <stddef.h>
#include <ctype.h>
#include <stdio.h>



char *encode(const char *text){
    if(!text) return NULL;
    int len=strlen(text);
    int n=1;
    char *enc=calloc(len+1,sizeof(char));
    int index=0;
    for(int i=0;i<len;i++){
        if(text[i]==text[i+1]){
            n++;
        }else{
            if(n==1){
                enc[index++]=text[i];
            }else if(n>1){
                index += sprintf(enc + index, "%d%c", n, text[i]);
            }
            n=1;
        }
    }
    enc[index]='\0';
    char *tmp=realloc(enc,index+1);
    if(tmp!=NULL){
        enc=tmp;
    }
    return enc;
}
char *decode(const char *data){
    int len=strlen(data);
    int count = 0;

    for (int i = 0; i < len;) {
        if (isdigit((unsigned char)data[i])) {
            int number = 0;

            while (i < len && isdigit((unsigned char)data[i])) {
                number = number * 10 + (data[i] - '0');
                i++;
            }

            count += number;
            i++;    
        } else {
            count++;
            i++;
        }
    }

    char * result=malloc(count+1);
    int index=0;

    for (int i = 0; i < len;) {
        if (isdigit((unsigned char)data[i])) {
            int number = 0;

            while (i < len && isdigit((unsigned char)data[i])) {
                number = number * 10 + (data[i] - '0');
                i++;
            }
            while(number){
                result[index++]=data[i];
                number--;
            }
            i++;    
        } else {
            result[index++]=data[i++];
        }
    }
    result[index]='\0';

    return result;
}
