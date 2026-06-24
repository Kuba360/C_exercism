#include "binary.h"
#include <string.h> 

int convert(const char *input){
    size_t len= strlen(input);

    for (size_t i=0;i<len;i++){
        if (input[i]!='1' && input[i]!='0'){
            return INVALID;
        }
    }
    int a=0;
    int c=1;
    for (size_t i=0;i<len;i++){
        if (input[i]=='1'){
            for(size_t j=1;j<len-i;j++){
                c*=2;
            }
        a+=c;
        }
        c=1;
    }
    return a;
}
//AI genrated version
// << 1 means move bits to the left - multiplying by 2 
// thats pretty clever 
// |1 adds bit '1' at the end. 
//int convert(const char *input) {
//    int result = 0;
//
//    for (size_t i = 0; input[i] != '\0'; i++) {
//        if (input[i] != '1' && input[i] != '0') return INVALID;
//        result <<= 1;
//        if (input[i] == '1') result |= 1;
//    }
//    return result;
//}
