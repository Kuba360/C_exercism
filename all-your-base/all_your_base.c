#include "all_your_base.h"
#include <stdint.h>
#include <stddef.h>
#include <string.h>

int64_t ipow(int base, int p){
	int n=0;
	int64_t r=1;
	while(n!=p){
		r*=base;
		n++;
	}
	return r;
}

size_t rebase(int8_t digits[DIGITS_ARRAY_SIZE],int16_t input_base,int16_t output_base,size_t input_length){
	if(input_length<1) return 0;	
	if(input_base < 2 || output_base < 2) return 0;
        for(size_t i=0; i<input_length; i++) {
            if(digits[i] < 0 || digits[i] >= input_base) return 0;
        }
	int64_t n=0;
	size_t ol=0;
	for(int i=input_length-1;i>=0;i--){
		n+=ipow(input_base,(input_length-1-i))*digits[i];
	}
	memset(digits,0,DIGITS_ARRAY_SIZE*sizeof(int8_t));
	int64_t m=0;
	int i=0;
	while(n>=m){
		m+=ipow(output_base,i)*(output_base-1);
		i++;
	}	
	ol=i;
	m=0;
	size_t j=0;
	while (m != n) {
                int64_t power = ipow(output_base, ol - j - 1);
                int64_t digit = (n - m) / power;

                if (digit > 0) {
                        digits[j] = digit;
                        m += digit * power;
                }
                
                j++;
        }
        return ol;
}
	
// AI generated 
//#include "all_your_base.h"
//#include <stdint.h>
//#include <stddef.h>
//#include <string.h>
//
//size_t rebase(int8_t digits[DIGITS_ARRAY_SIZE], int16_t input_base, int16_t output_base, size_t input_length) {
//    if (input_base < 2 || output_base < 2 || input_length < 1) return 0;
//
//    int64_t total_value = 0;
//    for (size_t i = 0; i < input_length; i++) {
//        if (digits[i] < 0 || digits[i] >= input_base) return 0;
//        total_value = total_value * input_base + digits[i];
//    }
//
//    memset(digits, 0, DIGITS_ARRAY_SIZE * sizeof(int8_t));
//
//    if (total_value == 0) {
//        digits[0] = 0;
//        return 1;
//    }
//
//    int8_t temp_buffer[DIGITS_ARRAY_SIZE];
//    size_t count = 0;
//
//    while (total_value > 0) {
//        temp_buffer[count++] = total_value % output_base;
//        total_value /= output_base;
//    }
//
//    for (size_t i = 0; i < count; i++) {
//        digits[i] = temp_buffer[count - 1 - i];
//    }
//
//    return count;
//}
