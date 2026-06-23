#include "hamming.h"
#include <stddef.h>

int compute(const char *lhs, const char *rhs) {
    if (lhs == NULL || rhs == NULL) {
        return -1;
    }
    // I forgot about checking if there is something in input
    int n = 0;
    
    while (*lhs != '\0' && *rhs != '\0') {
        if (*lhs != *rhs) {
            n++;
        }
        lhs++;
        rhs++;
    }

    if (*lhs != '\0' || *rhs != '\0') {
        return -1;
    }

    return n;
}
// It is more optimalize because it doesn't use strlen 
// I used strlen in definition of "for" loop - it calculate 
// the same length many times - it's pointless and costly 
// in respect of time.
