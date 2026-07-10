#include "circular_buffer.h"
#include <errno.h>
#include <stdlib.h>



circular_buffer_t *new_circular_buffer(size_t capacity){
    circular_buffer_t *b=malloc(sizeof(circular_buffer_t));
    if(b==NULL) return NULL;
    b->buffer=calloc(capacity,sizeof(int));
    if(b->buffer==NULL){
        free(b); 
        return NULL;
    }
    b->size=capacity;
    b->full=false;
    b->head=0;
    b->tail=0;
    return b;
}



void delete_buffer(circular_buffer_t *b){
    free(b->buffer);
    free(b);
}

int16_t  read(circular_buffer_t *b, buffer_value_t *read_value){
    if(b->full==false && b->head==b->tail){
        errno=ENODATA;
        return EXIT_FAILURE;
    }
    *read_value=b->buffer[b->tail];
    b->tail=(b->tail+1)%b->size;
    b->full=false;
    return EXIT_SUCCESS;
}
int16_t write(circular_buffer_t *b, buffer_value_t v){
    if(b->full==true){
        errno=ENOBUFS;
        return EXIT_FAILURE;
    }
    b->buffer[b->head]=v;
    b->head=(b->head+1)%b->size;
    if(b->head==b->tail){b->full=true;}
    return EXIT_SUCCESS;
}
int16_t overwrite(circular_buffer_t *b, buffer_value_t v){
    if(b->full==false){
        return write(b,v);
    }else{
        b->buffer[b->tail]=v;
        b->tail=(b->tail+1)%b->size;
        b->head=(b->head+1)%b->size;
        b->full=true;
        return EXIT_SUCCESS;
    }
}


void clear_buffer(circular_buffer_t *b){
    b->head=0;
    b->tail=0;
    b->full=false;
}