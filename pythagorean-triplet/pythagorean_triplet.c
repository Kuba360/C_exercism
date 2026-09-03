#include "pythagorean_triplet.h"
#include <math.h>
#include <stdlib.h>
#include <stdio.h>

triplets_t * triplets_with_sum(int sum){
   
    double b;
    int temp_tab[200]={0};
    int index_tab=0;
    for(int i=1;i<=(int)sum/2;i++){

       b=sum*(sum/2.0-i)/(sum-i); //this equation was taken from two math relationships between a,b,c,sum
       int ib=(int)b;
       double c=sqrt(i*i+ib*ib);
       if(b>i && (fmod(b,1.0)==0.0) && (fmod(c,1.0)==0.0)){
            temp_tab[index_tab++]=i;
            temp_tab[index_tab++]=ib;
            temp_tab[index_tab++]=(int)c;
       }
    }
    int num_of_tri=index_tab/3;

    printf("sum=%d, count=%d\n", sum, num_of_tri);

    for (int x = 0; x < index_tab; x += 3) {
        printf("%d %d %d\n",
            temp_tab[x],
            temp_tab[x + 1],
            temp_tab[x + 2]);
    }
    
    triplets_t *new_t=malloc(sizeof(triplets_t)+num_of_tri*sizeof(triplet_t));
    if(new_t==NULL) return NULL;    
    new_t->count=num_of_tri;
    
    for(int l=0,k=0;l<num_of_tri;l++){
        new_t->triplets[l].a=temp_tab[k++];
        new_t->triplets[l].b=temp_tab[k++];
        new_t->triplets[l].c=temp_tab[k++];
    }
    return new_t;
}

void free_triplets(triplets_t * t){
    free(t);
}
