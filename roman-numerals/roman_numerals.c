#include "roman_numerals.h"
#include "stddef.h"
#include "stdlib.h"

char *to_roman_numeral(unsigned int number){
    if (number<1 || number >3999) return NULL;
    char *n=malloc(25);
    if (n==NULL) return NULL;
    int tab[4]={number/1000,(number/100)%10,(number/10)%100,number%10};
    size_t index=0;
    char tab1[4]={'M','C','X','I'};
    char tab2[3]={'D','L','V'};

    for (int i=0;i<4;i++){
       if(tab[i]==0){continue;}
       if(tab[i]<=3){
            for(size_t j=0;j<tab[i];j++){
                n[index++]=tab1[i];
            }
       }else if(tab[i]==4){
            n[index++]=tab1[i];
            n[index++]=tab2[i-1];
       }else if(tab[i]>4 && tab[i]<9){
            n[index++]=tab2[i-1];
            for(size_t j=0;j<tab[i]-5;i++){
                n[index++]=tab1[i];
            }
       }
    }


}