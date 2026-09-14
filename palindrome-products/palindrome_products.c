#include "palindrome_products.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <limits.h>


product_t *get_palindrome_product(int from, int to){
    product_t *pal=calloc(1,sizeof(*pal));
    if(!pal)return NULL;

    if(from>to){
        snprintf(pal->error,MAXERR,"invalid input: min is %d and max is %d",from,to);
        return pal;
    }

    pal->smallest=INT_MAX;
    pal->largest=INT_MIN;

    for(int i=from;i<=to;i++){
        for(int j=i;j<=to;j++){
            int p=i*j;
            bool palindrome=is_palindrome(p);

            if(palindrome){
                if(p<pal->smallest){
                    free_factor(pal->factors_sm);
                    pal->factors_sm=NULL;
                    add_factor(&(pal->factors_sm),i,j);
                    pal->smallest=p;
                }else if(p==pal->smallest){
                    add_factor(&(pal->factors_sm),i,j);
                }
                

                if(p>pal->largest){
                    free_factor(pal->factors_lg);
                    pal->factors_lg=NULL;
                    add_factor(&(pal->factors_lg),i,j);
                    pal->largest=p;
                }else if(p==pal->largest){
                    add_factor(&(pal->factors_lg),i,j);
                }

            }

        }

    }
    if(pal->smallest==INT_MAX){
        pal->smallest=0;
        pal->largest=0;
        snprintf(pal->error,MAXERR,"no palindrome with factors in the range %d to %d",from,to);
    }
    return pal;
}

bool is_palindrome(int x){
    if(x<0)return false;
    int reversed=0;
    int tmp=x;

    while(tmp!=0){
        reversed=reversed*10 + tmp%10;
        tmp/=10;
    }
    return x==reversed;

}

void free_product(product_t *p){
    free_factor(p->factors_lg);
    free_factor(p->factors_sm);
    free(p);
}
void free_factor(factor_t *f){
    if(!f)return;
    free_factor(f->next);
    free(f);
}

void add_factor(factor_t **head, int a, int b){
    factor_t *node=calloc(1,sizeof(*node));
    if(!node)return;
    node->factor_a=a;
    node->factor_b=b;
    node->next=*head;
    *head=node;
}