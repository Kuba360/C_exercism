#ifndef CIRCULAR_BUFFER_H
#define CIRCULAR_BUFFER_H
#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>

typedef struct {
    size_t size;
    int *buffer;
    size_t head;    
    size_t tail;    
    bool full;
} circular_buffer_t;


typedef int buffer_value_t;

circular_buffer_t *new_circular_buffer(size_t capacity);
void delete_buffer(circular_buffer_t *buffer);
int16_t  read(circular_buffer_t *buffer, buffer_value_t *read_value);
int16_t write(circular_buffer_t *buffer, buffer_value_t v);
int16_t overwrite(circular_buffer_t *buffer, buffer_value_t v);
void clear_buffer(circular_buffer_t *buffer);


#endif
