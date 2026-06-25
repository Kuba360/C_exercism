#include <stdio.h>
#include <stddef.h>
#include <string.h>
#define BUFFER_SIZE (100)

void main(void){
    char r[BUFFER_SIZE];
    char *n="Jan";
    strcpy(r,n);
    printf("%s",r);
}




