#include "queen_attack.h"
#include <math.h>
#include <stdlib.h>

#define M_PI 3.14159265358979323846


attack_status_t can_attack(position_t queen_1, position_t queen_2){
    attack_status_t x;
    if(queen_1.row>7 ||queen_1.column>7 ||
       queen_2.row>7 || queen_2.column>7){
        return INVALID_POSITION;
    }
    if(queen_1.row==queen_2.row && queen_1.column==queen_2.column){
        return INVALID_POSITION;
    }
    int dx=queen_1.row-queen_2.row;
    int dy=queen_1.column-queen_2.column;
    double angle=atan2(dy,dx);
    int angle_deg = abs((int)round(angle * 180.0 / M_PI));

    // first if is for checking if the queens are on the same rows or columns
    if(queen_1.row==queen_2.row || queen_1.column==queen_2.column){
        x=CAN_ATTACK;
    //second is for diagonal 
    // I think it would be valid to check if a vecotr between two points is 
    // 45 degreee to the beginning 
    } else if(angle_deg==45 || angle_deg==135){
        x=CAN_ATTACK; 
    } else{
        x=CAN_NOT_ATTACK;
    }

    return x;
}
