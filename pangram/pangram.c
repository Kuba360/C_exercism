#include "pangram.h"
#include "stdbool.h"
#include "string.h"
#include "ctype.h"

bool is_pangram(const char *sentence){
    if (sentence == NULL) return false;
    const char *alphabet="abcdefghijklmnopqrstuvwxyz";
    int n=0;
    for (int i=0;i<26;i++){
        if(strchr(sentence,alphabet[i])==NULL &&
         strchr(sentence,toupper(alphabet[i]))==NULL){
            return 0;
        }else{
            n++;
        }
    }
    return (n==26)? 1:0;
}


//bool is_pangram(const char *sentence) {
//    if (sentence == NULL) return false;
//    const char *alphabet = "abcdefghijklmnopqrstuvwxyz";
//    for (int i = 0; i < 26; i++) {
//        if (strchr(sentence, alphabet[i]) == NULL &&
//            strchr(sentence, toupper(alphabet[i])) == NULL)
//            return false;
//    }
//    return true;
//}