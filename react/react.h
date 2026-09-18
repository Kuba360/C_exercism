#ifndef REACT_H
#define REACT_H

struct reactor;
struct cell;

typedef int (*compute1)(int);
typedef int (*compute2)(int, int);

struct reactor *create_reactor(void);
// destroy_reactor should free all cells created under that reactor.
void destroy_reactor(struct reactor *r);

struct cell *create_input_cell(struct reactor *r, int initial_value);
struct cell *create_compute1_cell(struct reactor *r, struct cell *c, compute1);
struct cell *create_compute2_cell(struct reactor *r, struct cell *c,
                                  struct cell *c2, compute2);

int get_cell_value(struct cell *c);
void set_cell_value(struct cell *c, int new_value);

typedef void (*callback)(void *, int);
typedef int callback_id;

// The callback should be called with the same void * given in add_callback.
callback_id add_callback(struct cell *c, void *, callback);
void remove_callback(struct cell *c, callback_id);

//my code 
void update_cell(struct cell *c);
void collect_cells(struct cell *c, struct cell **visited,int *old_val,int *count);
void recalculate_tree(struct cell *c);

struct reactor{
    int count;
    struct cell **cell;
};
struct cell{
    int val;
    struct cell **child;
    int c_count;

    struct cell **parent;
    int p_count;
    
    compute1 c1;
    compute2 c2;
    int compute_type;
    
    struct callback_data *callbacks;
    int callback_count;
};

struct callback_data{
    void *data;
    callback callb_fn;
    callback_id id;
    struct callback_data *next;
};

#endif
