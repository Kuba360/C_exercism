#include "yacht.h"
#include <stdbool.h>

#define length 5

int score(dice_t dice, category_t category){
    int n=0;
    int c[7]={0};
    int sum=0;
    for (int i=0;i<length;i++){
        c[dice.faces[i]]++;
        sum+=dice.faces[i];
    }
    
    if(category<=5){return c[category+1]*(category+1);}

    switch (category){
        case FULL_HOUSE:
            bool n2=false;
            bool n3=false;
            for (int i=1;i<=length+1;i++){
                if (c[i]==3){n3=true;}
                if (c[i]==2){n2=true;}
            }
            if (n3&&n2){
                return sum;
            }else {return 0;}
        case FOUR_OF_A_KIND:
            for (int i=1;i<=length+1;i++){
                if(c[i]>=4){return 4*i;}
            }
            return 0;
        case LITTLE_STRAIGHT:
            for (int i=1;i<=length+1;i++){
                if(c[i]==1){n++;}
            }
            if(c[1]==1&&c[6]==0&&n==5){
                return 30;
            }else {return 0;}
        case BIG_STRAIGHT:
            for (int i=1;i<=length+1;i++){
                if(c[i]==1){n++;}
            }
            if(c[6]==1&&c[1]==0&&n==5){
                return 30;
            }else {return 0;}
        case YACHT:
            for (int i=1;i<=length+1;i++){
                if (c[i]==5){return 50;}
            }
            return 0;
        case CHOICE:
            return sum;

        default: return 0;
    }
}


//AI generated
//#include "yacht.h"
//#include <stdbool.h>
//
//#define NUM_FACES 6
//#define NUM_DICE 5
//
//int score(dice_t dice, category_t category) {
//    int counts[NUM_FACES + 1] = {0};
//    int sum = 0;
//
//    for (int i = 0; i < NUM_DICE; i++) {
//        counts[dice.faces[i]]++;
//        sum += dice.faces[i];
//    }
//
//    if (category >= ONES && category <= SIXES) {
//        return counts[category + 1] * (category + 1);
//    }
//
//    switch (category) {
//        case FULL_HOUSE: {
//            bool has_two = false, has_three = false;
//            for (int i = 1; i <= NUM_FACES; i++) {
//                if (counts[i] == 2) has_two = true;
//                if (counts[i] == 3) has_three = true;
//            }
//            return (has_two && has_three) ? sum : 0;
//        }
//
//        case FOUR_OF_A_KIND:
//            for (int i = 1; i <= NUM_FACES; i++) {
//                if (counts[i] >= 4) return 4 * i;
//            }
//            return 0;
//
//        case LITTLE_STRAIGHT:
//            return (counts[1] && counts[2] && counts[3] &&
//                    counts[4] && counts[5]) ? 30 : 0;
//
//        case BIG_STRAIGHT:
//            return (counts[2] && counts[3] && counts[4] &&
//                    counts[5] && counts[6]) ? 30 : 0;
//
//        case YACHT:
//            for (int i = 1; i <= NUM_FACES; i++) {
//                if (counts[i] == 5) return 50;
//            }
//            return 0;
//
//        case CHOICE:
//            return sum;
//
//        default:
//            return 0;
//    }
//}