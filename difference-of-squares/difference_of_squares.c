#include "difference_of_squares.h"


unsigned int sum_of_squares(unsigned int number);
unsigned int square_of_sum(unsigned int number);
unsigned int difference_of_squares(unsigned int number);



unsigned int sum_of_squares(unsigned int number){
    unsigned int sum1 =0;
    for(unsigned int i=1;i<=number;i++){
        sum1+=i*i;  
    }
    return sum1;
}
unsigned int square_of_sum(unsigned int number){
    unsigned int sum2 =0;
    for(unsigned int i=1;i<=number;i++){
        sum2+=i;
    }
    unsigned int sum3=sum2*sum2;
    return sum3;
}
unsigned int difference_of_squares(unsigned int number){
    return square_of_sum(number) - sum_of_squares(number);
}
