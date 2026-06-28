#include "sum_of_multiples.h"
#include <stdbool.h>



unsigned int sum(const unsigned int *factors, const size_t number_of_factors,
                 const unsigned int limit)
    { 
        unsigned int sum=0;
        unsigned int n=0;
        for (size_t i=0;i<number_of_factors;i++){
            if (factors[i]>=limit || factors[i]==0){continue;}
            n=factors[i];
            while(n<limit){
                int f=0;
                for (size_t j=i+1;j<=number_of_factors-1;j++){
                    if(factors[j]==0){break;}
                    if(n%factors[j]==0){f=1; break;}
                }
                if(f==0){sum+=n;}
                n+=factors[i];
            }
        }
       return sum; 
    }

//AI generated
//unsigned int sum(const unsigned int *factors, size_t number_of_factors,
//                 unsigned int limit) {
//    unsigned int total = 0;
//
//    for (unsigned int n = 1; n < limit; n++) {
//        for (size_t i = 0; i < number_of_factors; i++) {
//            if (factors[i] != 0 && n % factors[i] == 0) {
//                total += n;
//                break;  // żeby nie dodać n dwa razy
//            }
//        }
//    }
//    return total;
//}