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

//AI version - main difference is in the type of variables
/*
#include "pythagorean_triplet.h"
 
#include <stdlib.h>
 
For a + b + c = sum and a^2 + b^2 = c^2, substituting
 * c = sum - a - b and solving for b gives a closed form:
 *
 *   b = sum * (sum - 2a) / (2 * (sum - a))
 *
 * so for every candidate 'a' in [1, sum/3) we can test in O(1)
 * whether a valid integer b > a exists, giving O(sum) total
 * instead of an O(sum^3) triple loop or O(sum^2) double loop.
 *
 * Returns true and fills *out_b, *out_c if 'a' yields a valid
 * triplet with a < b < c.
  
static int try_triplet(long s, long a, long *out_b, long *out_c)
{
    long denom = 2 * (s - a);
    if (denom == 0)
        return 0;
 
    long numer = s * (s - 2 * a);
    if (numer % denom != 0)
        return 0;
 
    long b = numer / denom;
    if (b <= a)
        return 0;
 
    long c = s - a - b;
    if (b >= c)
        return 0;
 
    *out_b = b;
    *out_c = c;
    return 1;
}
 
triplets_t *triplets_with_sum(int sum)
{
    long s = sum;
 
     First pass: count matches so we can allocate the flexible
     * array member with the exact required size. 
    int count = 0;
    for (long a = 1; 3 * a < s; ++a) {
        long b, c;
        if (try_triplet(s, a, &b, &c))
            count++;
    }
 
    triplets_t *result = malloc(sizeof(triplets_t) +
                                 (size_t)count * sizeof(triplet_t));
    if (!result)
        return NULL;
 
     Second pass: fill the now correctly-sized array.
    result->count = 0;
    for (long a = 1; 3 * a < s; ++a) {
        long b, c;
        if (!try_triplet(s, a, &b, &c))
            continue;
 
        result->triplets[result->count].a = (int)a;
        result->triplets[result->count].b = (int)b;
        result->triplets[result->count].c = (int)c;
        result->count++;
    }
 
    return result;
}
 
void free_triplets(triplets_t *t)
{
    free(t);
}
*/