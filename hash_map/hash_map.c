#include "hash_map.h"

#include <stdlib.h>

void hashmap_init(HashMap* map) {
  map->keys = malloc(INITIAL_CAPACITY * sizeof(char*));
  map->values = malloc(INITIAL_CAPACITY * sizeof(char*));
  map->size = 0;
  map->capacity = INITIAL_CAPACITY;
}

double hashmap_load_factor(HashMap* map) {
  return map->size / map->capacity;
}
