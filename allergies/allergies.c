#include "allergies.h"
#include <stdbool.h>



bool is_allergic_to(allergen_t a,int n){
    return n&(1<<a);
}

allergen_list_t get_allergens(int a){
    allergen_list_t x;
    x.count=0;
    for(int i=0;i<8;i++){
        if((a&1)==1){
            x.allergens[i]=true;
            x.count++;
        }
        a >>= 1;
    }
    return x;
}

//#include "allergies.h"
//#include <stdbool.h>
//
//bool is_allergic_to(allergen_t a, int n){
//    return (n & (1 << a)) != 0;
//}
//
//allergen_list_t get_allergens(int a){
//    allergen_list_t x;
//    x.count = 0;
//
//    for (int i = 0; i < ALLERGEN_COUNT; i++){
//        if (a & (1 << i)){
//            x.allergens[i] = true;
//            x.count++;
//        } else {
//            x.allergens[i] = false;
//        }
//    }
//
//    return x;
//}