#include "nucleotide_count.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>



char *count(const char *dna_strand){
   char *count=malloc(30); 
   int a=0;
   int c=0;
   int g=0;
   int t=0;
   size_t len=strlen(dna_strand);
   for (size_t i=0;i<len;i++){
        if(dna_strand[i]!='A' && dna_strand[i]!='C' 
            && dna_strand[i]!='G' && dna_strand[i]!='T'){
                count[0]='\0';
                return count ;
            }
        
        if (dna_strand[i]=='A') a++;
        if (dna_strand[i]=='C') c++;
        if (dna_strand[i]=='G') g++;
        if (dna_strand[i]=='T') t++;
   }
   sprintf(count,"A:%d C:%d G:%d T:%d",a,c,g,t);
   return count;
}


//AI generated 
//char *result = malloc(40);
//
//int a = 0, c = 0, g = 0, t = 0;
//
//for (size_t i = 0; dna_strand[i] != '\0'; i++) {
//    switch (dna_strand[i]) {
//        case 'A': a++; break;
//        case 'C': c++; break;
//        case 'G': g++; break;
//        case 'T': t++; break;
//        default:
//            result[0] = '\0';
//            return result;
//    }
//}
//
//snprintf(result, 40, "A:%d C:%d G:%d T:%d", a, c, g, t);