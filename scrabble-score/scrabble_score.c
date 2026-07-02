#include "scrabble_score.h"
#include <stddef.h> 
#include <string.h> 
#include <ctype.h> 



unsigned int score(const char *word){
    int tab[]={1,3,3,2,1,4,2,4,1,8,5,1,3,1,1,3,10,1,1,1,1,4,4,8,4,10};
    size_t len =strlen(word);
    unsigned int s=0;

    if (len<1){return 0;}

    for(size_t i=0;i<len;i++){
        s+=tab[tolower(word[i])-'a'];
    }
    return s;

}
