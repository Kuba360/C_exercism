#include "pascals_triangle.h"
#include <stdlib.h>



void free_triangle(uint8_t **triangle, size_t rows){
    for(size_t i=0;i<rows;i++){
        free(triangle[i]);
    }
    free(triangle);
}

uint8_t **create_triangle(size_t rows){
    if(rows==0){
        uint8_t **t=malloc(1 * sizeof(uint8_t *));
        t[0]=calloc(1,sizeof(uint8_t));
        return t;

    }
    uint8_t **t=malloc(rows * sizeof(uint8_t *));
    if (t==NULL) return NULL;

    for (size_t i=0;i<rows;i++){
        t[i]=calloc(rows,sizeof(uint8_t));
        if (t[i]==NULL) return NULL;
    }
    
    t[0][0]=1;
    for (size_t i=1;i<rows;i++){
        t[i][0]=1;
        for (size_t j=1;j<=i;j++){
            t[i][j]=t[i-1][j-1]+t[i-1][j];
        }
    }
    return t;
}
