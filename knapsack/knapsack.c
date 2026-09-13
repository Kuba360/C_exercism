#include "knapsack.h"
#include <stdlib.h>
int maximum_value(unsigned int max_w,item_t *items,unsigned int count){
    if(count<=0)return 0;
    unsigned int *tab=calloc(max_w+1,sizeof(unsigned int));
    if(!tab)return 0;

    for(unsigned int i=0;i<count;i++){

        for(unsigned int w=max_w;w>=items[i].weight;w--){
            unsigned int value_w_item=tab[w-items[i].weight]+items[i].value;
            if(value_w_item>tab[w]){
                tab[w]=value_w_item;
            }
        }
    }
    unsigned int result=tab[max_w];
    free(tab);
    return result;
}