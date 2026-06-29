#include "sieve.h"
#include <stdint.h>
#include <stddef.h>
#include <stdlib.h>
#include <stdbool.h>



uint32_t sieve(uint32_t limit, uint32_t *primes, size_t max_primes){
    bool *tab=calloc(limit+1,sizeof(bool));
    if (tab == NULL) return 0;

    size_t count=0;

    for(size_t i=2;i<=limit;i++){
        if(tab[i]==false){
            if (count >= max_primes) break;
            primes[count++]=i;
            uint32_t j = i * 2;
            while(j<=limit){
                tab[j]=true;
                j+=i;
            }
        }
    }
    free(tab);
    return count;
}