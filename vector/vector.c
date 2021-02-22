#include "vector.h"

#include <stdlib.h>

void vector_init(Vector* vector) {
  vector->items = malloc(INITIAL_CAPACITY * sizeof(int));
  vector->size = 0;
  vector->capacity = INITIAL_CAPACITY;
}

void vector_free(Vector* vector) {
  free(vector->items);
}

void vector_resize(Vector* vector, size_t capacity) {
  vector->items = realloc(vector->items, capacity * sizeof(int));
  vector->capacity = capacity;
}

void vector_push(Vector* vector, int item) {
  if (vector->size >= vector->capacity) {
    vector_resize(vector, vector->capacity * 2);
  }

  vector->items[vector->size] = item;
  vector->size++;
}

bool vector_is_empty(Vector* vector) {
  return vector->size == 0;
}
