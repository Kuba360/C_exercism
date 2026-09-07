#include "pig_latin.h"
#include <string.h>
#include <stdbool.h>

static const char vowels[]={'a','e','i','o','u'};

bool is_vowel(char c){
    bool vo=false;
    for(int i=0;i<5;i++){
        if(vowels[i]==c){
            vo=true;
            break;
        }
    return vo;
    }
}

char *translate(const char *phrase){
    int len=(int)strlen(phrase);
    char *new=calloc(len+1+2,sizeof(char));

    bool first_is_vowel=is_vowel(phrase[0]);

    if(first_is_vowel || strncmp(phrase,"xr",2)==0 || strncmp(phrase,"yt",2)==0){
        strcpy(new,phrase);
        new[len]='a';
        new[len+1]='y';
    }

    if(!first_is_vowel){
        char *p=str(phrase,"qu");
        int pos_qu=-1;
        if(p!=NULL){
            pos_qu=p-phrase;
        }

        int num_of_con=1;
        for(int i=1;i<len;i++){
            num_of_con++;
            if(is_vowel(phrase[i])){
                break;
            }
        }



    }
    
    new[len+2]='\0';
    return new;
}