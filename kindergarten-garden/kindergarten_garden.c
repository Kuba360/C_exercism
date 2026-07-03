#include "kindergarten_garden.h"
#include <string.h>


plants_t  plants(const char *diagram, const char *student){
    char *name[]={"Alice","Bob","Charlie","David","Eve","Fred","Ginny",
        "Harriet","Ileana","Joseph","Kincaid","Larry"};
    int id=0;
    plants_t p;

    for (int j=0;j<12;j++){
        if(strcmp(name[j],student)==0){
            id=j*2;
            break;
        }
    }
    size_t len=strlen(diagram);
    
    p.plants[0]=transform(diagram[id]);   
    p.plants[1]=transform(diagram[id+1]);   
    p.plants[2]=transform(diagram[id+((len+1)/2)]);
    p.plants[3]=transform(diagram[id+((len+1)/2)+1]);

    return p;
}


int transform(char x){
    switch(x){
        case 'C':
            return CLOVER;
        case 'G':
            return GRASS;
        case 'R':
            return RADISHES;
        case 'V':
            return VIOLETS;
        default:
            break;
    }
    return -1;
}


//AI generated 
//#include "kindergarten_garden.h"
//#include <string.h>
//
//static int transform(char x);
//
//plants_t plants(const char *diagram, const char *student)
//{
//    static const char *names[] = {
//        "Alice","Bob","Charlie","David","Eve","Fred","Ginny",
//        "Harriet","Ileana","Joseph","Kincaid","Larry"
//    };
//
//    int idx = 0;
//
//    for (int i = 0; i < 12; i++) {
//        if (strcmp(names[i], student) == 0) {
//            idx = i;
//            break;
//        }
//    }
//
//    const char *second_row = strchr(diagram, '\n') + 1;
//
//    plants_t p;
//
//    p.plants[0] = transform(diagram[2 * idx]);
//    p.plants[1] = transform(diagram[2 * idx + 1]);
//    p.plants[2] = transform(second_row[2 * idx]);
//    p.plants[3] = transform(second_row[2 * idx + 1]);
//
//    return p;
//}
//
//static int transform(char x)
//{
//    switch (x) {
//        case 'C': return CLOVER;
//        case 'G': return GRASS;
//        case 'R': return RADISHES;
//        case 'V': return VIOLETS;
//    }
//    return -1;
//}