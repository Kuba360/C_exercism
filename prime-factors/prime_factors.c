#include "prime_factors.h"
#include <stdint.h>
#include <stddef.h>

//#define MAXFACTORS 10

size_t find_factors(uint64_t n, uint64_t factors[static MAXFACTORS]){
	int p=2;
	size_t c=0;
	while(n!=1){
		if(n%p==0){
			n/=p;
			factors[c++]=p;
		}else{
			p++;
		}
	}
	return c;
}
