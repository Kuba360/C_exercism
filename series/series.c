#include "series.h"
#include <string.h>
#include <ctype.h>
#include <stdlib.h>


slices_t slices(char *input_text, unsigned int substring_length){
    size_t len=strlen(input_text);
    if(len<substring_length || substring_length==0 || *input_text=='\0'){
        slices_t ns={0,NULL};
        return ns;
    }

    slices_t ns;
    ns.substring_count=len-substring_length+1;
    ns.substring=malloc(ns.substring_count*sizeof(char *));
    for(size_t i=0;i<ns.substring_count;i++){
        ns.substring[i]=malloc(substring_length*sizeof(char)+1);
        strncpy(ns.substring[i],input_text+i,substring_length);
        ns.substring[i][substring_length]='\0';
    }

    return ns;
}