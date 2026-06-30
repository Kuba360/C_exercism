#include "reverse_string.h"
#include <string.h>
#include <stdlib.h>

char *reverse(const char *value){
  size_t len=strlen(value);
  char *tab=malloc((len+1)*sizeof(char));

    for (size_t i=0;i<len;i++){
        tab[i]=value[len-1-i];
    }
    tab[len]='\0';
    return tab;
}
