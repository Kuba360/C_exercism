#include "secret_handshake.h"
#include "stdbool.h"
#include "stdlib.h"
#include "ctype.h"
#include "string.h"




const char **commands(size_t number){
    if(number>31) return NULL;
    const char **c=malloc(4*sizeof(char *));
    if (c==NULL) return NULL;
    bool tab[5]={0};
    char *code[4]={"wink","double blink","close your eyes","jump"};
    int i=4;
    while(number!=0){
        if(number&1){
            tab[i]=true;
        }else{
            tab[i]=false;
        }
        number>>=1;
        i--;
    }
    size_t index=0;
    for(int j=0;j<4;j++){
        if(tab[4-j]){
            char * buf=calloc(20,sizeof(char));
            strcpy(buf,code[j]);
            c[index++]=buf;
        }
    }
    for(size_t k=index;k<4;k++){
        c[k]=NULL;
    }
    if(tab[0]){
        for(size_t left=0, right=index; left<right; left++, right--){
            const char *tmp=c[left];
            c[left]=c[right-1];
            c[right-1]=tmp;
        }
    }
    return c;
}
