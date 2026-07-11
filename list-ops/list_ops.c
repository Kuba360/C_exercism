#include "list_ops.h"
#include <stdlib.h>

list_t *new_list(size_t length, list_element_t elements[]){
    list_t *l=malloc(sizeof(list_t)+length*sizeof(list_element_t));
    if (l==NULL)return NULL;
    l->length=length;
    for(size_t i=0;i<length;i++){
        l->elements[i]=elements[i];
    }
    return l;
}


list_t *append_list(list_t *list1, list_t *list2){
    size_t total=list1->length+list2->length;
    list_t *l=malloc(sizeof(list_t)+total*sizeof(list_element_t));
    if (l==NULL)return NULL;
    l->length=total;
    for(size_t i=0;i<list1->length;i++){
        l->elements[i]=list1->elements[i];
    }
    for(size_t i=0;i<list2->length;i++){
        l->elements[list1->length+i]=list2->elements[i];
    }
    free(list1);
    free(list2);
    return l;
}


list_t *filter_list(list_t *list, bool (*filter)(list_element_t)){
    size_t count = 0;
    for (size_t i = 0; i < list->length; i++){
        if (filter(list->elements[i])) count++;
    }
    list_t *l=malloc(sizeof(list_t)+count*sizeof(list_element_t));
    if (l==NULL)return NULL;
    l->length=count;
    int r=0;
    for(size_t i=0;i<list->length;i++){
        if(filter(list->elements[i])==true){
            l->elements[r++]=list->elements[i];
        }
    }
    return l;
}

size_t length_list(list_t *list){
    return list->length;
}

list_t *reverse_list(list_t *list){
    list_t *l=malloc(sizeof(list_t)+list->length*sizeof(list_element_t));
    if (l==NULL)return NULL;
    l->length=list->length;
    for (size_t i=0;i<list->length;i++){
        l->elements[i]=list->elements[list->length-i-1];
    }
    free(list);
    return l;
}

void delete_list(list_t *list){
    free(list);
}
