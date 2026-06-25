#include "raindrops.h"
#include <string.h>
#include <stdio.h>

void convert(char result[], int drops){

    if(drops%3==0){
        strcat(result,"Pling");
    }

    if(drops%5==0){
        strcat(result,"Plang");
    }
    
    if(drops%7==0){
        strcat(result,"Plong");
    }
    if(drops%3!=0 && drops%5!=0 && drops%7!=0){
        sprintf(result,"%d",drops);
    }
}


//void convert(char result[], int drops) {
//    result[0] = '\0';
//    
//    if (drops % 3 == 0) strcat(result, "Pling");
//    if (drops % 5 == 0) strcat(result, "Plang");
//    if (drops % 7 == 0) strcat(result, "Plong");
//    
//    if (result[0] == '\0')
//        sprintf(result, "%d", drops);
//}