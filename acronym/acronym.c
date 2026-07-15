#include "acronym.h"
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include <stdlib.h>

char *abbreviate(const char *phrase){
    if(phrase==NULL || strcmp(phrase,"")==0) return NULL;

    char *a=malloc(strlen(phrase)+1);
    if (a==NULL) return NULL;

    size_t index=0;
    if (isalpha(phrase[0])==true){
        a[index++]=toupper(phrase[0]);
    }
    for(size_t i=1;phrase[i]!='\0';i++){
       if(isalpha(phrase[i]) && !isalpha(phrase[i-1]) && phrase[i-1]!='\''){
        a[index++]=toupper(phrase[i]);
       }
    }
    a[index]='\0';
    char *trim=realloc(a,(index+1)*sizeof(char));
    if(trim!=NULL){
        a=trim;
    }

    return a;
}