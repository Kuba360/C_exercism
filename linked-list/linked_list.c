#include "linked_list.h"

struct list_node {
   struct list_node *prev, *next;
   ll_data_t data;
};

struct list {
   struct list_node *first, *last;
};


// constructs a new (empty) list
struct list *list_create(void){
  struct list* new_l=malloc(sizeof(struct list));
   if(!new_l)return NULL;
   *new_l=(struct list){0};
  return new_l;
}

// counts the items on a list
size_t list_count(const struct list *list){
   struct list_node *current=list->first;
   size_t count=0;
   while(current!=NULL){
      current=current->next;
      count++;
   }
   return count;
}

// inserts item at back of a list
void list_push(struct list *list, ll_data_t item_data){
   struct list_node *new_n=malloc(sizeof(struct list_node));
   if(!new_n)return NULL;
   new_n->prev=list->last;
   new_n->data=item_data;
   new_n->next=NULL;
   
   if(list->last){
      list->last->next=new_n;
   }else{
      list->first=new_n;
   }

   list->last=new_n;
}

// removes item from back of a list
ll_data_t list_pop(struct list *list);

// inserts item at front of a list
void list_unshift(struct list *list, ll_data_t item_data);

// removes item from front of a list
ll_data_t list_shift(struct list *list);

// deletes a node that holds the matching data
void list_delete(struct list *list, ll_data_t data);

// destroys an entire list
// list will be a dangling pointer after calling this method on it
void list_destroy(struct list *list);