#ifndef ZEBRA_PUZZLE_H
#define ZEBRA_PUZZLE_H
#include <stdbool.h>

typedef struct {
   const char *drinks_water;
   const char *owns_zebra;
} solution_t;


bool next_to(int a, int b);

solution_t solve_puzzle(void);

#endif
