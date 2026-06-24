#include "two_fer.h"
#include <stddef.h>
#include <string.h>


void two_fer(char *buffer, const char *name){
    if(name==NULL){
    strcpy(buffer,"One for you, one for me.");
    return;
    }
    strcpy(buffer,"One for ");
    strcat(buffer,name);
    strcat(buffer,", one for me.");
    
}

//#include "two_fer.h"
//#include <stdio.h>
//void two_fer(char *buffer, const char *name) {
//     sprintf(buffer, "One for %s, one for me.", name? name : "you");   
//}
// sprintf directly saves string into buffer.