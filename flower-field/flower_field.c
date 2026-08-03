#include "flower_field.h"
#include <stddef.h>
#include <stdlib.h>
#include <string.h>

char **annotate(const char **garden, const size_t rows){
    if(!garden) return NULL;
    char **new_field=calloc(rows+1,sizeof(char *));
    int rows2=rows;
    int  row_len=strlen(*garden);
    for(int  i=0;i<rows2;i++){
        new_field[i]=calloc(row_len+1,sizeof(char));
        for(int  j=0;j<row_len;j++){
            if(garden[i][j]=='*'){
                new_field[i][j]='*';
                continue;
            }
            int  n_flower=0;
            for(int k=-1;k<=1;k++){
                for(int l=-1;l<=1;l++){
                    if(i+k<0 || i+k>=rows2 || j+l<0 || j+l>=row_len
                    || (k==0&&l==0)) continue;
                    if(garden[i+k][j+l]=='*') n_flower++;
                }
            }
            if (n_flower==0){
                 new_field[i][j]=' ';
              }else{
                new_field[i][j]=n_flower+'0';
              }
        }
        new_field[i][row_len]='\0';
    }
    return new_field;
}
void free_annotation(char **annotation){
    int  i=0;
    while(annotation[i]){
        free(annotation[i]);
        i++;
    }
    free(annotation);
}