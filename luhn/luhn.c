#include "luhn.h"
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>


bool luhn(const char *num){

    char *n=malloc(strlen(num)+1);
    strcpy(n,num);
    int j=0;
    for (int i=0;n[i]!='\0';i++){
        if((n[i]<'0' || n[i]>'9')&&n[i]!=' '){free(n);return false;}
        if(n[i]!=' '){
           n[j] =n[i];
           j++;
        }
    }
    n[j]='\0';
    int sum=0;
    size_t len =strlen(n);
    if(len<=1){free(n);return false;}
    for (int i=len-2;i>=0;i-=2){
            int c=n[i]-'0';
            c*=2;
            if(c>9){c-=9;}
            n[i]=c+'0';
    }
    for (size_t i=0;i<len;i++){sum+=n[i]-'0';}

    free(n);
    return sum%10==0;
}
//AT generated 
//bool luhn(const char *num) {
//    int sum = 0;
//    int count = 0;
//
//    for (int i = strlen(num) - 1; i >= 0; i--) {
//        if (num[i] == ' ') continue;
//        if (num[i] < '0' || num[i] > '9') return false;
//
//        int c = num[i] - '0';
//        if (count % 2 == 1) {
//            c *= 2;
//            if (c > 9) c -= 9;
//        }
//        sum += c;
//        count++;
//    }
//    return count > 1 && sum % 10 == 0;
//}