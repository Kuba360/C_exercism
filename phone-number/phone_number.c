#include "phone_number.h"
#include <stddef.h>
#include <string.h>
#include <stdlib.h>


char *phone_number_clean(const char *input){
    size_t len = strlen(input);
    char digits[len +1];
    int count=0;
    for (size_t i=0;input[i]!='\0';i++){
       if(input[i]>='0' && input[i]<='9'){
            digits[count]=input[i];
            count++;
       } 
    }
    digits[count]='\0';

    char *phone=malloc(11);
    if (phone==NULL) return NULL;
    strcpy(phone,"0000000000");

    char *cdigits=digits;
    if (count==11){
        if(digits[0]!='1'){
            return phone;
        }else{
            cdigits=digits+1;
        }
    }

    if(strlen(cdigits)==10 && cdigits[0]>='2' && cdigits[3]>='2'){
        strcpy(phone,cdigits);
        phone[10]='\0';
    }
    return phone;
}


//AI generated 
//#include "phone_number.h"
//#include <string.h>
//#include <stdlib.h>
//#include <ctype.h>
//
//char *phone_number_clean(const char *input){
//    size_t len = strlen(input);
//    char digits[len + 1];
//    size_t count = 0;
//
//    for (size_t i = 0; input[i] != '\0'; i++){
//        if (isdigit((unsigned char)input[i])) {
//            digits[count++] = input[i];
//        }
//    }
//    digits[count] = '\0';
//
//    char *phone = malloc(11);
//    if (phone == NULL) return NULL;
//    strcpy(phone, "0000000000");
//
//    const char *cdigits = digits;
//
//    if (count == 11) {
//        if (digits[0] != '1') return phone;
//        cdigits = digits + 1;
//        count = 10;
//    }
//
//    if (count == 10 && cdigits[0] >= '2' && cdigits[3] >= '2') {
//        memcpy(phone, cdigits, 10);
//    }
//
//    return phone;
//}