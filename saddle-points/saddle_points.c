#include "saddle_points.h"
#include <stdlib.h>




saddle_points_t *saddle_points(size_t r, size_t c,uint8_t matrix[r][c]){

    if (r==0 || c==0) {
        saddle_points_t *sp = malloc(sizeof(saddle_points_t));
        if (sp == NULL) return NULL;
        sp->count = 0;
        return sp;
    }

    size_t count=0;
    int max[r];
    int min[c];
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
                count++;
            }
        }
    }

    saddle_points_t *sp=malloc(sizeof(saddle_points_t)+sizeof(saddle_point_t)*count);
    sp->count=count;
    if ( count==0){ return sp;}
    count=0;
    for (size_t i=0;i<r;i++){
        for (size_t j=0;j<c;j++){
            if(matrix[i][j]==max[i] && matrix[i][j]==min[j]){
                sp->points[count].row=i+1;
                sp->points[count].column=j+1;
                count++;
            }
        }
    }
    return sp;
}

void free_saddle_points(saddle_points_t *sp){
    free(sp);
}


// AI generated 
//#include "saddle_points.h"
//#include <stdlib.h>
//
//saddle_points_t *saddle_points(size_t r, size_t c, uint8_t matrix[r][c]){
//
//    if (r == 0 || c == 0) {
//        saddle_points_t *sp = malloc(sizeof(saddle_points_t));
//        if (sp == NULL) return NULL;
//        sp->count = 0;
//        return sp;
//    }
//
//    int max[r];
//    int min[c];
//
//    for (size_t i = 0; i < r; i++) max[i] = matrix[i][0];
//    for (size_t j = 0; j < c; j++) min[j] = matrix[0][j];
//
//    for (size_t i = 0; i < r; i++){
//        for (size_t j = 0; j < c; j++){
//            if (matrix[i][j] > max[i]) max[i] = matrix[i][j];
//            if (matrix[i][j] < min[j]) min[j] = matrix[i][j];
//        }
//    }
//
// 
//    saddle_points_t *sp = malloc(sizeof(saddle_points_t) + sizeof(saddle_point_t) * r * c);
//    if (sp == NULL) return NULL;
//
//    size_t count = 0;
//    for (size_t i = 0; i < r; i++){
//        for (size_t j = 0; j < c; j++){
//            if (matrix[i][j] == max[i] && matrix[i][j] == min[j]){
//                sp->points[count].row = i + 1;
//                sp->points[count].column = j + 1;
//                count++;
//            }
//        }
//    }
//    sp->count = count;
//
// 
//    saddle_points_t *trimmed = realloc(sp, sizeof(saddle_points_t) + sizeof(saddle_point_t) * count);
//    if (trimmed != NULL) {
//        sp = trimmed;
//    }
//
//    return sp;
//}
//
//void free_saddle_points(saddle_points_t *sp){
//    free(sp);
//}