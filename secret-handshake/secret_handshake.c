#include "secret_handshake.h"
#include "stdbool.h"




const char **commands(size_t number){
    if(number<1 || number>31) return NULL;
    bool tab[5]={0};
    int i=4;
    while(number!=0){
        tab[i]=number|1;
        number>>=1;
    }
}