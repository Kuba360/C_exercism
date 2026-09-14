#ifndef PALINDROME_PRODUCTS_H
#define PALINDROME_PRODUCTS_H

#define MAXERR 100

#include <stdbool.h>

typedef struct factors {
   int factor_a;
   int factor_b;
   struct factors *next;
} factor_t;

struct product {
   int smallest;
   int largest;
   factor_t *factors_sm;
   factor_t *factors_lg;
   char error[MAXERR];
};

typedef struct product product_t;

product_t *get_palindrome_product(int from, int to);
void free_product(product_t *p);
bool is_palindrome(int x);
void free_factor(factor_t *p);
void add_factor(factor_t **head, int a, int b);

#endif
