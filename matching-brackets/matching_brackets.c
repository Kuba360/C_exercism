#include "matching_brackets.h"
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

//{[()]}
bool is_paired(const char *input){
    char *t=malloc(strlen(input)+1);
    if (t==NULL) return false;
    size_t index=0;
    char s[6]={'{','}','[',']','(',')'};
    
    for(size_t i=0;input[i]!='\0';i++){
        for(size_t j=0;j<6;j++){
            if(input[i]==s[j]){
                t[index++]=s[j];
            }
        }
    }
    t[index]='\0';
    if(index%2==1){
        free(t);
        return false;
    }
    
    size_t y=0;
    for (size_t i=0;t[i]!='\0';i++){
        for(size_t j=0;j<6;j++){
            if(t[i]==s[j] && j%2==0){
                t[y++]=t[i];              
            }else if(t[i]==s[j] && j%2==1){
                if(y==0){
                    free(t);
                    return false;
                }else if(s[j]-t[y-1]==1 || s[j]-t[y-1]==2){   
                    y--;
                    continue;
                }else{
                    free(t);
                    return false;
                }
            }
        }
    }
    if(y!=0) return false;

    free(t);
    return true;
}


//AI generated 
//#include "matching_brackets.h"
//#include <stdbool.h>
//#include <string.h>
//
//bool is_paired(const char *input){
//    char stack[strlen(input) + 1];
//    size_t top = 0;
//
//    for (size_t i = 0; input[i] != '\0'; i++){
//        char c = input[i];
//        if (c == '{' || c == '[' || c == '('){
//            stack[top++] = c;
//        } else if (c == '}' || c == ']' || c == ')'){
//            if (top == 0){
//                return false;
//            }
//            char open = stack[--top];
//            if ((c == '}' && open != '{') ||
//                (c == ']' && open != '[') ||
//                (c == ')' && open != '(')){
//                return false;
//            }
//        }
//    }
//
//    return top == 0;
//}
