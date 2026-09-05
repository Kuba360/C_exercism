#include "word_count.h"
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>


int count_words(const char *sentence, word_count_word_t *words){
    size_t i=0;
    int index=0;
    while(sentence[i]!='\0'){
        if(!isalnum(sentence[i])){
            i++;
            continue;
        }

        size_t j=i;
        while(sentence[j]!=0 &&(isalnum(sentence[j]) ||
         (sentence[j]=='\'' && isalpha(sentence[j+1])))){
            j++;
        }
        if(i!=j){
            char tmp[MAX_WORD_LENGTH];
            strncpy(tmp,sentence+i,j-i);
            tmp[j-i]='\0';
            for(size_t l=0;tmp[l]!='\0';l++){
                tmp[l]=tolower(tmp[l]);
            }
            printf(" %s\n",tmp);
            bool old=false;
            for(int k=0;k<index;k++){
                if(strcmp(words[k].text,tmp)==0){
                    words[k].count++;
                    old=true;
                    break;
                }
            }
            if(!old){
                words[index].count=1;
                strncpy(words[index].text,tmp,j-i);
                words[index++].text[j - i] = '\0';
            }
        }


        i=j;
    }
    return index;
}