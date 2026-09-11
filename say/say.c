#include "say.h"
#include <stdlib.h>
#include <string.h>
static const char *ones[]={"one","two","three","four","five","six","seven","eight","nine"};
static const char *teen[]={"ten","eleven","twelve","thirteen","fourteen","fifteen","sixteen","seventeen","eighteen","nieneteen"};
static const char *teens[]={"twenty","thirty","forty","fifty","sixty","seventy","eighty","ninety"};
static const char *scales[]={"thousand","million","billion"};

int say(int64_t input, char **ans){
    if(input<0 || input>999999999999LL)return -1;
    if(input==0){
        *ans=malloc(5*sizeof(char));
        strcpy(*ans,"zero");
        return 0;
    }

    char buf[1000]="";
    int chunks[4]={0};
    for(int i=0;i<4;i++){
        chunks[i]=input%1000;
        input/=1000;
    }
    for(int i=3;i>=0;i--){
        if(chunks[i]){
            char *part=three_d(chunks[i]);
            if(part){
                if(strlen(buf)>0){
                    strcat(buf," ");
                }
                strcat(buf,part);
                if(i>0){
                    strcat(buf," ");
                    strcat(buf,scales[i-1]);
                }
                free(part);
            }
        }
    }
    *ans=malloc(strlen(buf)+1);
    if(!*ans)return -1;
    strcpy(*ans,buf);

    return 0;
}

char *three_d(int x){
    if(x==0)return NULL;
    char *result=calloc(60,sizeof(char));
    if(!result)return NULL;
    
    int h=x/100;
    int r=x%100;
    if(h>0){
        strcat(result,ones[h-1]);
        strcat(result," hundred");
    }

    if(r>0){
        if(h>0) strcat(result, " ");
        if(r<10){
            strcat(result,ones[r-1]);
        }else if(r<20){
            strcat(result,teen[r-10]);
        }else{
            strcat(result,teens[(r/10)-2]);
            if(r%10){
                strcat(result,"-");
                strcat(result,ones[(r%10)-1]);
            }
        }
    }
    return result;
}