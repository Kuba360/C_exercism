#include "isogram.h"
#include "stddef.h"
#include "ctype.h"


bool is_isogram(const char phrase[]){
    if (phrase==NULL){return false;}
    const char *alphabet="abcdefghijklmnopqrstuvwxyz";
    for (int i=0;i<26;i++){
        int c=0;
        int n=0;
        while(phrase[c]!='\0'){
                if(tolower(phrase[c])==alphabet[i]){
                    n++;
                }
                if (n==2){
                    return false;
                }
            c++;
        }
    }
    return true;
}

//AI generated versions 
//#include <stdbool.h>
//#include <ctype.h>
//#include <stddef.h>
//
//bool is_isogram(const char phrase[])
//{
//    if (phrase == NULL) {
//        return false;
//    }
//
//    bool seen[26] = { false };
//
//    for (int i = 0; phrase[i] != '\0'; i++) {
//        char c = tolower((unsigned char)phrase[i]);
//
//        if (c < 'a' || c > 'z') {
//            continue; // ignoruj znaki niebędące literami
//        }
//
//        int index = c - 'a';
//
//        if (seen[index]) {
//            return false; // litera już była
//        }
//
//        seen[index] = true;
//    }
//
//    return true;
//}

//Embedded style - 4 bytes variable instead of array
//#include <stdbool.h>
//#include <ctype.h>
//#include <stddef.h>
//#include <stdint.h>
//
//bool is_isogram(const char phrase[])
//{
//    if (phrase == NULL) {
//        return false;
//    }
//
//    uint32_t mask = 0;
//
//    for (int i = 0; phrase[i] != '\0'; i++) {
//        char c = tolower((unsigned char)phrase[i]);
//
//        if (c < 'a' || c > 'z') {
//            continue;
//        }
//
//        int index = c - 'a';
//
//        // czy litera już była?
//        if (mask & (1u << index)) {
//            return false;
//        }
//
//        // zapamiętaj literę
//        mask |= (1u << index);
//    }
//
//    return true;
//}
