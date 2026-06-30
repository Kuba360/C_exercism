#include "beer_song.h"
#include <stdint.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void recite(uint8_t start_bottles, uint8_t take_down, char **song){
        char *b=calloc(8,sizeof(char));
        strcpy(b,"bottles");
        for(size_t i=0;i<take_down*3;i+=3){     
                if(start_bottles==0){
                        sprintf(song[i],"No more bottles of beer on the wall, no more bottles of beer.");
                        sprintf(song[i+1],"Go to the store and buy some more, 99 bottles of beer on the wall.");
                        return;
                }
                if(start_bottles==1){strcpy(b,"bottle");}
                sprintf(song[i],"%d %s of beer on the wall, %d %s of beer.",start_bottles,b,start_bottles,b);
                start_bottles--;
                if(start_bottles==0){
                        sprintf(song[i+1],"Take it down and pass it around, no more bottles of beer on the wall.");
                        song[i+2][0]='\0';
                }else if(start_bottles==1){
                        sprintf(song[i+1],"Take one down and pass it around, 1 bottle of beer on the wall.");
                        song[i+2][0]='\0';
                }else{
                        sprintf(song[i+1],"Take one down and pass it around, %d bottles of beer on the wall.",start_bottles);
                        song[i+2][0]='\0';
                }
        }
        free(b);
}

//AI generated
//#include "beer_song.h"
//#include <stdint.h>
//#include <stdio.h>
//#include <string.h>
//
//void recite(uint8_t start_bottles, uint8_t take_down, char **song) {
//    size_t line_idx = 0;
//
//    for (uint8_t i = 0; i < take_down; i++) {
//        if (start_bottles == 0) {
//            sprintf(song[line_idx++], "No more bottles of beer on the wall, no more bottles of beer.");
//        } else {
//            sprintf(song[line_idx++], "%d %s of beer on the wall, %d %s of beer.", 
//                    start_bottles, 
//                    (start_bottles == 1) ? "bottle" : "bottles", 
//                    start_bottles, 
//                    (start_bottles == 1) ? "bottle" : "bottles");
//        }
//
//        if (start_bottles == 0) {
//            start_bottles = 99;
//        } else {
//            start_bottles--;
//        }
//
//        if (start_bottles == 99) {
//            sprintf(song[line_idx++], "Go to the store and buy some more, 99 bottles of beer on the wall.");
//        } else if (start_bottles == 0) {
//            sprintf(song[line_idx++], "Take it down and pass it around, no more bottles of beer on the wall.");
//        } else {
//            sprintf(song[line_idx++], "Take one down and pass it around, %d %s of beer on the wall.", 
//                    start_bottles, 
//                    (start_bottles == 1) ? "bottle" : "bottles");
//        }
//
//        if (i < take_down - 1) {
//            song[line_idx++][0] = '\0'; 
//        }
//    }
//}