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
int *sorted_data(node_t *tree);