#include "dnd_character.h"
#include <stdlib.h>
#include <time.h>
#include <math.h>
#define MIN(a, b) ((a) < (b) ? (a) : (b))



dnd_character_t make_dnd_character(void){
    srand(time(NULL));
    dnd_character_t hero;
    hero.strength=ability();
    hero.dexterity=ability();
    hero.constitution=ability();
    hero.intelligence=ability();
    hero.wisdom=ability();
    hero.charisma=ability();
    hero.hitpoints=10+modifier(hero.constitution);
    
    return hero;
}

int ability(void){
    int a1=rand()%6+1;
    int a2=rand()%6+1;
    int a3=rand()%6+1;
    int a4=rand()%6+1;
    int am=MIN(MIN(a1,a2),MIN(a3,a4));
    return a1+a2+a3+a4-am;
}
int modifier(int score){
    double c=(score-10)/2.0;
    return floor(c);
}

//int ability(void) {
//    int rolls[4], min = 7, sum = 0;
//    for (int i = 0; i < 4; i++) {
//        rolls[i] = rand() % 6 + 1;
//        if (rolls[i] < min) min = rolls[i];
//        sum += rolls[i];
//    }
//    return sum - min;
//}
