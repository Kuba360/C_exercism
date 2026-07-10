#ifndef RATIONAL_NUMBERS_H
#define RATIONAL_NUMBERS_H


typedef struct
{
    int numerator;
    int denominator;
}rational_t;

rational_t add(rational_t a,rational_t b);
rational_t subtract(rational_t a,rational_t b);
rational_t multiply(rational_t a,rational_t b);
rational_t divide(rational_t a,rational_t b);
rational_t absolute(rational_t a);
rational_t exp_rational(rational_t a, int b);
float exp_real(int a,rational_t b);
rational_t reduce(rational_t a);
int ipow(int a,int b);
float root(float p, float q);


#endif
