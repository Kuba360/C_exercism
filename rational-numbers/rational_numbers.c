#include "rational_numbers.h"
#include <math.h>
#include <stdlib.h>

rational_t add(rational_t a,rational_t b){
    rational_t c;
    c.numerator=a.numerator*b.denominator+b.numerator*a.denominator;
    c.denominator=a.denominator*b.denominator;
    return reduce(c);
}
rational_t subtract(rational_t a,rational_t b){
    rational_t c;
    c.numerator=a.numerator*b.denominator-b.numerator*a.denominator;
    c.denominator=a.denominator*b.denominator;
    return reduce(c);
}
rational_t multiply(rational_t a,rational_t b){
    rational_t c;
    c.numerator = a.numerator*b.numerator;
    c.denominator=a.denominator*b.denominator;
    return reduce(c);
}
rational_t divide(rational_t a,rational_t b){
    rational_t c;
    c.numerator = a.numerator*b.denominator;
    c.denominator=a.denominator*b.numerator;
    return reduce(c);
}
rational_t absolute(rational_t a){
    rational_t c;
    c.numerator=abs(a.numerator);
    c.denominator=abs(a.denominator);
    return reduce(c);
}
rational_t exp_rational(rational_t a, int b){
    rational_t c;
    if(b==0){
        c.denominator=1;c.numerator=1; 
        return c;
    }else if(b<0){
        b=abs(b);
        c.numerator=ipow(a.denominator,b);
        c.denominator=ipow(a.numerator,b);
    }else{
        c.numerator=ipow(a.numerator,b);
        c.denominator=ipow(a.denominator,b);
    }
    return reduce(c);
}
float exp_real(int a,rational_t b){
    float c;
    c=root(pow(a,b.numerator),b.denominator);
    return c;
}

float root(float p, float q){
    return pow(p, 1.0f / q);
}

int ipow(int a, int b){
    int result=1;
    while(b!=0){
        result*=a;
        b--;
    }
    return result;
}

rational_t reduce(rational_t a){
    rational_t b=a;
    int x=a.numerator;
    int y=a.denominator;
    while(y!=0){
        int temp=y;
        y=x % y;
        x=temp;
    }
    int gcd=x;

    b.denominator/=gcd;
    b.numerator/=gcd;
    if(b.denominator<0){
        b.denominator*=-1;
        b.numerator*=-1;
    }
    return b;
}
