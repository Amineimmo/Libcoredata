#ifndef DYNARRAY_H
#define DYNARRAY_H

#include <stddef.h>

struct dynamic_array
{
    size_t length;    // number of ints stored
    size_t capacity;  // number of ints the block can hold
    int *data;        // heap block of capacity ints (NULL when capacity is 0)
};

struct dynamic_array create_arr(size_t capacity);
struct dynamic_array empty_arr(void);
void destroy_arr(struct dynamic_array *arr);
int push(struct dynamic_array *arr, int value);
int pop(struct dynamic_array *arr, int *out);

#endif