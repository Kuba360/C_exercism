#include "armstrong_numbers.h"
#include <stdlib.h>

static int ipow(int base,int exp);

bool is_armstrong_number(int candidate) {
    int y = candidate;
    int n = 0;

    while (y >= 1) {
        n++;
        y /= 10;
    }

    int *tab = malloc(n * sizeof(int));
    y = candidate;
    int i = 0;
    while (y > 0) {
        tab[i++] = y % 10;  // wydobądź cyfrę
        y /= 10;
    }

    int arm_n = 0;
    for (int i = 0; i < n; i++) {
        arm_n += ipow(tab[i], n);
    }

    free(tab);
    return arm_n == candidate;
}

static int ipow(int base,int exp){
    int result=1;
    while(exp-->0){
        result*=base;
    }
    return result;
}