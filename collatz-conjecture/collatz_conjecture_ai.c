#include "collatz_conjecture.h"

int steps(int start) {
    if (start <= 0) {
        return ERROR_VALUE;
    }
// if start is inappropriate then n wont be even created - it's faster
    int n = 0;

    while (start != 1) {
        if (start % 2 == 0) {
            start /= 2;   // it is shorter
        } else {
            start = start * 3 + 1;
        }
        n++;
    }

    return n;
}