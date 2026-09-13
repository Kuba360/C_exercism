#ifndef KNAPSACK_H
#define KNAPSACK_H

typedef struct {
   unsigned int weight;
   unsigned int value;
} item_t;
int maximum_value(unsigned int max_w,item_t *items,unsigned int count);

#endif
