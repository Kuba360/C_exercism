#include "nth_prime.h"
#include <stdint.h>
#include <stdbool.h>

#define LIMIT 120000

uint32_t nth(uint32_t n){
	if(n<1) return 0;
	bool tab[LIMIT]={0};
	uint32_t  m=0;
	uint32_t i=2;
	while (m!=n){
		if(tab[i]==false){
			m++;
			tab[i]=true;
			uint32_t j=2*i;
			while(j<=(LIMIT-1)){
				tab[j]=true;
				j+=i;
			}
		}
		i++;
	}
	return i-=1;
}


