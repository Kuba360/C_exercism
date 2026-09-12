#include "binary_search_tree.h"
#include <stdlib.h> 

node_t *build_tree(int *tree_data, size_t tree_data_len){
    if(!tree_data || tree_data_len==0)return NULL;
    node_t *bt=calloc(1,sizeof(node_t));
    if(!bt)return NULL;
    bt->data=tree_data[0];
    int i=1;
    
    while((int)tree_data_len>i){
        int num=*(tree_data+i);
        node_t *pos=bt;
        node_t *parent=NULL;

        while(pos){
            parent=pos;
            pos=(num<=pos->data)?pos->left:pos->right;
        }
        node_t *new_node=calloc(1,sizeof(node_t));
        new_node->data=num;
        if(num<=parent->data){
            parent->left=new_node;
        }else{
            parent->right=new_node;
        }
        i++;
    }
    return bt;
}
void free_tree(node_t *tree){
    if(!tree)return;

    free_tree(tree->left);
    free_tree(tree->right);
    free(tree);
}
int *sorted_data(node_t *tree){
    if(!tree)return NULL;
    size_t n=count_nodes(tree);

    int *tab=calloc(n,sizeof(int));
    if(!tab)return NULL;

    int index=0;

    sort(tab,&index,tree,tree->data);

    return tab;
}

void sort(int* tab,int *index,node_t *node,int rootval){
    if(!node)return;


    sort(tab,index,node->left,rootval);
    tab[(*index)++]=node->data;
    sort(tab,index,node->right,rootval);
}

size_t count_nodes(node_t *tree){
    if(!tree)return 0;
    return 1+count_nodes(tree->left)+count_nodes(tree->right);
}