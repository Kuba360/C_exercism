#include "linked_list.h"
#include <stdlib.h>

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
   if(!new_n)return;
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
ll_data_t list_pop(struct list *list){
   if(list->last==0)return 0;

   struct list_node * tmp=list->last;
   ll_data_t x=tmp->data;

   if(list->first==list->last){
      list->first=NULL;
      list->last=NULL;
   }else{
      list->last=tmp->prev;
      list->last->next=NULL;
   }
   free(tmp);
   return x;
}

// inserts item at front of a list
void list_unshift(struct list *list, ll_data_t item_data){
   struct list_node *new_n=malloc(sizeof(struct list_node));
   if(!new_n)return;
   new_n->data=item_data;
   new_n->next=list->first;
   new_n->prev=NULL;

   if(list->first){
      list->first->prev=new_n;
   }else{
      list->last=new_n;
   }
   list->first=new_n;
}

// removes item from front of a list
ll_data_t list_shift(struct list *list){
   if(list->last==0)return 0;

   struct list_node * tmp=list->first;
   ll_data_t x=tmp->data;

   if(list->first==list->last){
      list->first=NULL;
      list->last=NULL;
   }else{
      list->first=tmp->next;
      list->first->prev=NULL;
   }
   free(tmp);
   return x;

}

// deletes a node that holds the matching data
void list_delete(struct list *list, ll_data_t data){
   struct list_node *current_n=list->first;

   while(current_n!=NULL && current_n->data!=data){
      current_n=current_n->next;
   }
   if(current_n==NULL)return;
   
   if(current_n->prev!=NULL){
      current_n->prev->next=current_n->next;
   }else{
      list->first=current_n->next;
   }

   if(current_n->next!=NULL){
      current_n->next->prev=current_n->prev;
   }else{
      list->last=current_n->prev;
   }

   free(current_n);
}

// destroys an entire list
// list will be a dangling pointer after calling this method on it
void list_destroy(struct list *list){
   struct list_node *current_n=list->first;

   while(current_n!=NULL){
      struct list_node *tmp=current_n->next;
      free(current_n);
      current_n=tmp;
   }
   free(list);
}