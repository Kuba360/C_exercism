#include "diamond.h"
#include <string.h>
#include <stdlib.h>

char **make_diamond(const char letter){
    int diff=letter-'A';
    int size=(diff)*2+1;
    char **diamond=calloc(size+1,sizeof(char *));
    diamond[size]=NULL;
    for(int i=0;i<size;i++){
        diamond[i]=calloc(size+1,sizeof(char));
        memset(diamond[i],' ',size);
        diamond[i][size]='\0';
        int distance=abs(diff-i);
        char current ='A'+(diff-distance);
        diamond[i][distance]=current;
        diamond[i][size-1-distance]=current;
    }
    return diamond;
}


void free_diamond(char **diamond){
    size_t i=0;
    while(diamond[i]!=NULL){
        free(diamond[i++]);
    }
    free(diamond);
}