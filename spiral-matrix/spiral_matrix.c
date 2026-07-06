#include "spiral_matrix.h"
#include <stdlib.h>


spiral_matrix_t *spiral_matrix_create(int x){
    spiral_matrix_t *m = malloc(sizeof(spiral_matrix_t));
    m->size=x;
    if (x<=0){ m->matrix=NULL; return m;}

    m->matrix=malloc(m->size*sizeof(int*));

    for (int i=0;i<m->size;i++){
        m->matrix[i]=malloc(m->size*sizeof(int));
    }
    int i=1, c=0, r=0;
    int y=0;

    while (i!=x*x+1){
        for (;c<x-y;++c){
            m->matrix[r][c]=i;
            i++;
        }
        c--;
        r++;
        for (;r<x-y;++r){
            m->matrix[r][c]=i;
            i++;
        }
        r--;
        c--;
        for(;c>=y;--c){
            m->matrix[r][c]=i;
            i++;
        }
        c++;
        r--;
        for(;r>y;--r){
            m->matrix[r][c]=i;
            i++;
        }
        r++;
        c++;
        y++;
    }
    return m;

}

void spiral_matrix_destroy(spiral_matrix_t *m){

    for (int i=0;i<m->size;i++){
        free(m->matrix[i]);
    }
    free(m->matrix);
    free(m);
}


//AI generated 
//#include "spiral_matrix.h"
//#include <stdlib.h>
//
//spiral_matrix_t *spiral_matrix_create(int x)
//{
//    spiral_matrix_t *m = malloc(sizeof(spiral_matrix_t));
//    m->size = x;
//
//    if (x <= 0) {
//        m->matrix = NULL;
//        return m;
//    }
//
//    m->matrix = malloc(x * sizeof(int *));
//    for (int i = 0; i < x; i++) {
//        m->matrix[i] = malloc(x * sizeof(int));
//    }
//
//    int dr[4] = {0, 1, 0, -1};
//    int dc[4] = {1, 0, -1, 0};
//
//    int r = 0, c = 0, dir = 0;
//
//    for (int val = 1; val <= x * x; val++) {
//        m->matrix[r][c] = val;
//
//        int nr = r + dr[dir];
//        int nc = c + dc[dir];
//
//        if (nr < 0 || nr >= x || nc < 0 || nc >= x || m->matrix[nr][nc] != 0) {
//            dir = (dir + 1) % 4;
//            nr = r + dr[dir];
//            nc = c + dc[dir];
//        }
//
//        r = nr;
//        c = nc;
//    }
//
//    return m;
//}
//
//void spiral_matrix_destroy(spiral_matrix_t *m)
//{
//    for (int i = 0; i < m->size; i++) {
//        free(m->matrix[i]);
//    }
//    free(m->matrix);
//    free(m);
//}