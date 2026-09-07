#include "pig_latin.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

static const char vowels[]={'a','e','i','o','u'};

bool is_vowel(char c){
    bool vo=false;
    for(int i=0;i<5;i++){
        if(vowels[i]==c){
            vo=true;
            break;
        }
    }
    return vo;
}

char *translate_word(const char *phrase){
    int len=(int)strlen(phrase);
    char *new=calloc(len+1+2,sizeof(char));

    bool first_is_vowel=is_vowel(phrase[0]);

    if(first_is_vowel || strncmp(phrase,"xr",2)==0 || strncmp(phrase,"yt",2)==0){
        strcpy(new,phrase);
    }

    if(!first_is_vowel){
        char *p=strstr(phrase,"qu");
        int pos_qu=-1;
        if(p!=NULL){
            pos_qu=p-phrase;
            bool qu=true;
            for(int i=0;i<pos_qu;i++){
                if(is_vowel(phrase[i])){
                    qu=false;
                }
            }
            if(qu){
                int lenght=len-(pos_qu+2);
                memcpy(new,phrase+pos_qu+2,lenght);
                memcpy(new+lenght,phrase,pos_qu+2);
            }
        }
        if(!strlen(new)){
            int num_of_con=0;
            int y_pos=-1;
            for(int i=0;i<len;i++){
                if(is_vowel(phrase[i])){
                    break;
                }
                if(phrase[i]=='y' && i!=0){
                    y_pos=i;
                    printf("Y position is=%d\n",y_pos);
                    break;
                }
                
                num_of_con++;
            }
            int distance=(y_pos==num_of_con)? y_pos: num_of_con;
            printf("distance: %d\n",distance);
            strncpy(new,phrase+distance,len-distance);
            memcpy(new+len-distance,phrase,distance);
        }
    }

    new[len]='a';
    new[len+1]='y';
    new[len+2]='\0';
    return new;
}


char *translate(const char *phrase){
    int len=strlen(phrase);
    char *result=calloc(len*2+1,sizeof(char));

    int i=0;
    int out=0;
    while(i<len){
        char word[100];
        int j=0;

        while(phrase[i]!=' ' && phrase[i]!='\0'){
            word[j++]=phrase[i++];
        }
        word[j]='\0';
        
        char *translated=translate_word(word);
        strcpy(result+out,translated);
        out+=strlen(translated);
        free(translated);
        if(phrase[i]==' '){
            result[out++]=' ';
            i++;
        }
    }
    result[out]='\0';
    return result;
    
}