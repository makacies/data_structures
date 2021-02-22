#ifndef _VECTOR_H
#define _VECTOR_H

#include <stdbool.h>
#include <stddef.h>

#define INITIAL_CAPACITY 10

typedef struct {
  int* items;
  size_t size;
  size_t capacity;
} Vector;

void vector_init(Vector* vector);
void vector_free(Vector* vector);
void vector_resize(Vector* vector, size_t capacity);
void vector_push(Vector* vector, int item);
bool vector_is_empty(Vector* vector);
// TODO:
// insert(index, item)
// delete(index)
// at() with bounds check
// shrink_to_fit()

#endif
