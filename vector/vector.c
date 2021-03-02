#include "vector.h"

#include <stdlib.h>
#include <string.h>

#define MAX(a, b) (((a) > (b)) ? (a) : (b))

void vector_init(Vector* vector, size_t item_size) {
  vector->items = malloc(INITIAL_CAPACITY * item_size);
  vector->item_size = item_size;
  vector->size = 0;
  vector->capacity = INITIAL_CAPACITY;
}

void vector_free(Vector* vector) {
  free(vector->items);
}

void vector_resize(Vector* vector, size_t capacity) {
  vector->items = realloc(vector->items, capacity * vector->item_size);
  vector->capacity = capacity;
}

void vector_push(Vector* vector, void* item) {
  if (vector->size >= vector->capacity) {
    vector_resize(vector, MAX(vector->capacity * 2, INITIAL_CAPACITY));
  }

  char* dest = (char*)(vector->items) + vector->size * vector->item_size;
  memcpy(dest, item, vector->item_size);
  ++vector->size;
}

bool vector_is_empty(Vector* vector) {
  return vector->size == 0;
}

void* vector_at(Vector* vector, size_t index) {
  if (index >= 0 && index < vector->size) {
    return &(((char*)vector->items)[index * vector->item_size]);
  }

  return NULL;
}

bool vector_insert(Vector* vector, void* item, size_t index) {
  if (index >= 0 && index < vector->size) {
    if (vector->size >= vector->capacity) {
      vector_resize(vector, vector->capacity * 2);
    }

    char* src = (char*)(vector->items) + index * vector->item_size;
    char* dest = src + vector->item_size;
    size_t count = (vector->size - index) * vector->item_size;
    memmove(dest, src, count);
    memcpy(src, item, vector->item_size);
    ++vector->size;

    return true;
  }

  return false;
}

bool vector_delete(Vector* vector, size_t index) {
  if (index >= 0 && index < vector->size) {
    if (index < vector->size - 1) {
      char* src = (char*)(vector->items) + (index + 1) * vector->item_size;
      char* dest = src - vector->item_size;
      size_t count = (vector->size - index + 1) * vector->item_size;
      memmove(dest, src, count);
    }

    --vector->size;
    return true;
  }

  return false;
}

void vector_shrink_to_fit(Vector* vector) {
  vector_resize(vector, vector->size);
}
