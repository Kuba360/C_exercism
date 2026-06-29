#include "rotational_cipher.h"
#include <string.h>
#include <stdlib.h>



char *rotate(const char *text, int shift_key){
    size_t len = strlen(text);
    char *r = malloc(len + 1);
    if (r == NULL) return NULL;

    for (size_t i = 0; i < len; i++) {
        if (text[i] >= 'a' && text[i] <= 'z') {
            r[i] = (text[i] - 'a' + shift_key) % 26 + 'a';
        } else if (text[i] >= 'A' && text[i] <= 'Z') {
            r[i] = (text[i] - 'A' + shift_key) % 26 + 'A';
        } else {
            r[i] = text[i];
        }
    }
    r[len] = '\0';
    return r;
}



// my code  
// char is a number between -128 and 127. So when I taken 
// 'z' (123) and added eg 13,  then 135 became -121 and my IF statement
// didn't work.
//char *rotate(const char *text, int shift_key){
//    size_t len=strlen(text);
//    char *r=malloc(len+1);
//    for (size_t i=0;i<len;i++){
//        if((text[i]>='a'&& text[i]<='z') || (text[i]>='A' && text[i]<='Z')){
//            r[i]=text[i]+shift_key;
//            if(r[i]>'z' && text[i]<'z'){r[i]-=26;}
//            if(r[i]>'z' && text[i]<'z'){r[i]-=26;}
//        }else {
//            r[i]=text[i];
//        }
//    }
//    r[len]='\0';
//    return r;
//}