#ifndef RAIL_FENCE_CIPHER_H
#define RAIL_FENCE_CIPHER_H

#include <stddef.h>

void one_row(char *text, char *enco, int *index, int rails, int r, int l,int begin);

char *encode(char *text, size_t rails);

char *decode(char *ciphertext, size_t rails);

#endif
