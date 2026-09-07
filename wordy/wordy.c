#include "wordy.h"
#include <string.h>
#include <stddef.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdio.h>


bool is_number(char *string,int *x){
    int l=strlen(string);
    int i=0;
    bool negative=false;
    if(string[0]=='-'){
        string++;
        l--;
        negative=true;
    }
    while(i<l){
        if(string[i]=='?')break;
        if(!isdigit(string[i]))return false;
        *x=*x*10+(string[i]-'0');
        i++;
    }
    if(negative) (*x)*=-1;
    return true;
}

bool answer(const char *question, int *result){
    int len=(int)strlen(question);
    char *tmp=calloc(len+1,sizeof(char));
    strcpy(tmp,question);
    tmp[len]='\0';
    char *words[20];
    int n=0;
    char *word=strtok(tmp," ");
    while(word!=NULL){
        words[n++]=word;
        word=strtok(NULL," ");
    }
    int x=0;
    if(n<3 || strcmp(words[0],"What")!=0 || strcmp(words[1],"is")!=0 ||
                                            !is_number(words[2],&x))return false;

    int i=3;
    if(n==3){
        *result=x;
        return true;
    }
    while(i<n){
        int y=0;
        if(strcmp(words[i],"plus")==0){
            if(i+1>=n)return false;
            if(!is_number(words[i+1],&y))return false;
            x+=y;
            i+=2;

        }else if(strcmp(words[i],"minus")==0){
            if(i+1>=n)return false;
            if(!is_number(words[i+1],&y))return false;
            x-=y;
            i+=2;

        }else if(strcmp(words[i],"multiplied")==0){
            if(i+2>=n)return false;
            if(strcmp(words[i+1],"by")!=0)return false;
            if(!is_number(words[i+2],&y))return false;
            x*=y;
            i+=3;

        }else if(strcmp(words[i],"divided")==0){
            if(i+2>=n)return false;
            if(strcmp(words[i+1],"by")!=0)return false;
            if(!is_number(words[i+2],&y))return false;
            x/=y;
            i+=3;

        }else{
            return false;
        }
    }
    *result=x;
    return true;

}