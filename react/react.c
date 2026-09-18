#include "react.h"
#include <stdlib.h>


struct reactor *create_reactor(void){
    struct reactor *r=calloc(1,sizeof(*r));
    return r;
}


void destroy_reactor(struct reactor *r){
    if(!r)return;

    for(int i=0;i<r->count;i++){
        struct cell *c=r->cell[i];

        struct callback_data *cd=c->callbacks;
        while(cd){
            struct callback_data*tmp=cd->next;
            free(cd);
            cd=tmp;
        }
        free(c->child);
        free(c->parent);
        free(c);
    }
    free(r->cell);
    free(r);
}

struct cell *create_input_cell(struct reactor *r, int initial_value){
    if(!r)return NULL;
    struct cell *c=calloc(1,sizeof(*c));
    if(!c)return NULL;
    c->compute_type=0;
    c->val=initial_value;

    struct cell **new_cell=realloc(r->cell,sizeof(*(r->cell))*(r->count+1));
    if(!new_cell){
        free(c);
        return NULL;
    }

    r->cell=new_cell;
    r->cell[r->count++]=c;
    return c;
}




struct cell *create_compute1_cell(struct reactor *r, struct cell *c, compute1 f){
    if(!r || !c || !f)return NULL;

    struct cell *nc=calloc(1,sizeof(*nc));
    if(!nc)return NULL;

    nc->compute_type=1;
    nc->val=f(c->val);
    nc->c1=f;

    nc->parent=malloc(sizeof(*(nc->parent)));
    if(!nc->parent){
        free(nc);
        return NULL;
    }
    nc->parent[0]=c;
    nc->p_count=1;

    struct cell ** new_children=realloc(c->child,sizeof(*(c->child))*(c->c_count+1));
    if(!new_children){
        free(nc->parent);
        free(nc);
        return NULL;
    }

    c->child=new_children;
    c->child[c->c_count++]=nc;

    struct cell **new_cell=realloc(r->cell,sizeof(*(r->cell))*(r->count+1));
    if(!new_cell){
        c->c_count--;
        free(nc->parent);
        free(nc);
        return NULL;
    }

    r->cell=new_cell;
    r->cell[r->count++]=nc;
    return nc;

}



struct cell *create_compute2_cell(struct reactor *r, struct cell *c_1,
                                  struct cell *c_2, compute2 f){
    if(!r || !c_1 || !c_2 || !f)return NULL;
    struct cell *nc=calloc(1,sizeof(*nc));
    if(!nc)return NULL;
    nc->compute_type=2;
    nc->val=f(c_1->val, c_2->val);
    nc->c2=f;
    
    nc->parent=malloc(2*sizeof(*(nc->parent)));
    if(!nc->parent){
        free(nc);
        return NULL;
    }
    nc->parent[0]=c_1;
    nc->parent[1]=c_2;
    nc->p_count=2;


    struct cell ** tmp1=realloc(c_1->child,sizeof(*(c_1->child))*(c_1->c_count+1));
    if(!tmp1){
        free(nc->parent);
        free(nc);
        return NULL;
    }
    c_1->child=tmp1;
    c_1->child[c_1->c_count++]=nc;

    struct cell ** tmp2=realloc(c_2->child,sizeof(*(c_2->child))*(c_2->c_count+1));
    if(!tmp2){
        c_1->c_count--;
        free(nc->parent);
        free(nc);
        return NULL;
    }
    c_2->child=tmp2;
    c_2->child[c_2->c_count++]=nc;

    struct cell **tmp3=realloc(r->cell,sizeof(*(r->cell))*(r->count+1));
    if(!tmp3){
        c_1->c_count--;
        c_2->c_count--;
        free(nc->parent);
        free(nc);
        return NULL;
    }

    r->cell=tmp3;
    r->cell[r->count++]=nc;
    return nc;
    }




int get_cell_value(struct cell *c){
    return c->val;
}



void set_cell_value(struct cell *c, int new_value){
    if(!c || c->val==new_value)return;

    struct cell *visited[256];
    int old_val[256];
    int count=0;

    collect_cells(c,visited,old_val,&count);

    c->val=new_value;

    recalculate_tree(c);

    for(int i=0;i<count;i++){
        struct cell *target=visited[i];
        if(target->compute_type!=0 && target->val!=old_val[i]){
            struct callback_data *cb=target->callbacks;
            while(cb){
                if(cb->callb_fn){
                    cb->callb_fn(cb->data,target->val);
                }
                cb=cb->next;
            }
        }
    }
}


callback_id add_callback(struct cell *c, void *d, callback cb){
    if(!c || !d)return -1;
    struct callback_data *cd=calloc(1,sizeof(*cd));
    if(!cd)return -1;
    cd->callb_fn=cb;
    cd->data=d;
    c->callback_count++;
    cd->id=c->callback_count;
    cd->next=c->callbacks;
    c->callbacks=cd;
    return cd->id;
}



void remove_callback(struct cell *c, callback_id cbid){
    if(!c || !c->callback_count)return;
    struct callback_data **curr=&(c->callbacks);

    while(*curr!=NULL){
        if((*curr)->id==cbid){
            struct callback_data *to_remove=*curr;

            *curr=to_remove->next;
            free(to_remove);
            c->callback_count--;
            return;
        }
        curr=&((*curr)->next);
    }
}



void update_cell(struct cell *c){
    int old=c->val;
    if(c->compute_type==1){
        c->val=c->c1(c->parent[0]->val);
    }else if(c->compute_type ==2){
        c->val=c->c2(c->parent[0]->val,c->parent[1]->val);
    }

    if(old==c->val)return;

    struct callback_data *cd=c->callbacks;
    while(cd){
        cd->callb_fn(cd->data,c->val);
        cd=cd->next;
    }
    
    for(int i=0;i<c->c_count;i++){
        update_cell(c->child[i]);
    }
}
void collect_cells(struct cell *c, struct cell **visited,int *old_val,int *count){
    if(!c)return;
    for(int i=0;i<*count;i++){
        if(c==visited[i])return;
    }
    visited[*count]=c;
    old_val[*count]=c->val;
    (*count)++;
    for(int i=0;i<c->c_count;i++){
        collect_cells(c->child[i],visited,old_val,count);
    }

}
void recalculate_tree(struct cell *c){
    for(int i=0;i<c->c_count;i++){
        struct cell *child=c->child[i];

        if(child->compute_type==1){
            child->val=child->c1(child->parent[0]->val);
        }else if(child->compute_type==2){
            child->val=child->c2(child->parent[0]->val,child->parent[1]->val);
        }
        recalculate_tree(child);
    }
}