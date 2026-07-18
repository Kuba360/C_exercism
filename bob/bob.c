#include "bob.h"
#include "ctype.h"
#include "string.h"
#include "stddef.h"
#include "stdbool.h"



char *hey_bob(char *greeting){
    if (greeting == NULL) return "Fine. Be that way!";
    bool space=true;
    bool yell=true;
    bool letter=false;
    size_t len=strlen(greeting);
    for (size_t i=0;greeting[i]!='\0';i++){
        if(!isspace(greeting[i])){
            space=false;
            break;
        }
    }
    for (size_t j=0;greeting[j]!='\0';j++){
        if(!isupper(greeting[j]) && isalpha(greeting[j])){
            yell=false;
            break;
        }
    }
    for (size_t k=0;greeting[k]!='\0';k++){
        if(isalpha(greeting[k])){
            letter=true;
            break;
        }
    }
    if(!letter){
        yell=false;
    }
    while(len>0 && isspace(greeting[len-1])){
        len--;
    }
    bool question = (len > 0 && greeting[len-1] == '?'); 
    
    if(question && !yell){
        char *bob="Sure.";
        return bob;
    }else if(!question && yell && letter){
        char *bob="Whoa, chill out!";
        return bob;
    }else if(question && yell && letter){
        char *bob="Calm down, I know what I'm doing!";
        return bob;
    }else if(space && !letter){
        char *bob="Fine. Be that way!";
        return bob;
    }else{
        char *bob="Whatever.";
        return bob;
    }
}

//AI generated
//#include "bob.h"
//#include <ctype.h>
//#include <string.h>
//
//char *hey_bob(char *greeting){
//    if (greeting == NULL) return "Fine. Be that way!";
//
//    bool has_letter = false;
//    bool has_lower = false;
//    size_t end = 0;
//
//    for (size_t i = 0; greeting[i] != '\0'; i++){
//        unsigned char ch = (unsigned char)greeting[i];
//        if (!isspace(ch)) {
//            end = i + 1;  // ostatnia pozycja "treści" (nie-whitespace)
//        }
//        if (isalpha(ch)) {
//            has_letter = true;
//            if (islower(ch)) has_lower = true;
//        }
//    }
//
//    bool is_question = (end > 0 && greeting[end - 1] == '?');
//    bool is_yelling = has_letter && !has_lower;
//    bool is_silence = (end == 0);
//
//    if (is_silence)              return "Fine. Be that way!";
//    if (is_yelling && is_question) return "Calm down, I know what I'm doing!";
//    if (is_yelling)               return "Whoa, chill out!";
//    if (is_question)              return "Sure.";
//    return "Whatever.";
//}