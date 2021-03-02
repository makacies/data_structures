#ifndef _VECTOR_H
#define _VECTOR_H

#include <stdbool.h>
#include <stddef.h>

#define INITIAL_CAPACITY 10

typedef struct {
  void* items;
  size_t item_size;
  size_t size;
  size_t capacity;
} Vector;

void vector_init(Vector* vector, size_t item_size);
void vector_free(Vector* vector);
void vector_resize(Vector* vector, size_t capacity);
void vector_push(Vector* vector, void* item);
void* vector_at(Vector* vector, size_t index);
bool vector_is_empty(Vector* vector);
bool vector_insert(Vector* vector, void* item, size_t index);
bool vector_delete(Vector* vector, size_t index);
void vector_shrink_to_fit(Vector* vector);

#endif
