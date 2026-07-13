#include "saddle_points.h"
#include <stdlib.h>




saddle_points_t *saddle_points(size_t r, size_t c,uint8_t matrix[r][c]){
    if(r==0 || c==0){ return NULL;}
    size_t count;
    int max[r];
    int min[c];
    int x=0;
    for (size_t i=0;i<r;i++){
        max[i]=matrix[i][0];
        for (size_t j=1;j<c;j++){
            if(max[i]<matrix[i][j]){
                max[i]=matrix[i][j];
            }
        }
    }

    for (size_t i=0;i<c;i++){
        min[i]=matrix[0][i];
        for (size_t j=1;j<r;j++){
            if(min[i]>matrix[j][i]){
                min[i]=matrix[j][i];
            }
        }
    }

    for (size_t i=0;i<r;i++){
        for (size_t j=0;j<c;j++){
            if(matrix[i][j]==max[i] && matrix[i][j]==min[j]){
            }
        }
    }
    

}

void free_saddle_points(saddle_points_t *sp){
    free(sp);
}