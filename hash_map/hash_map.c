#include "hash_map.h"

#include <stdlib.h>

void hashmap_init(HashMap* map) {
  // TODO: change malloc to calloc
  map->keys = malloc(INITIAL_CAPACITY * sizeof(char*));
  map->values = malloc(INITIAL_CAPACITY * sizeof(char*));
  map->size = 0;
  map->capacity = INITIAL_CAPACITY;
}

uint64_t hashmap_hash(HashMap* map, char* key) {
  return 0;
}

size_t hashmap_normalize(HashMap* map, uint64_t hash) {
  return hash % map->capacity;
}

void hashmap_insert(HashMap* map, char* key, char* value) {
  if (hashmap_load_factor(map) > RESIZE_THRESHOLD) {
    // TODO: realloc keys and values
    // TODO: reindex
  }

  uint64_t hash = hashmap_hash(map, key);
  size_t index = hashmap_normalize(map, hash);

  char* key_copy = malloc(strlen(key) + 1);
  strcpy(key_copy, key);

  char* value_copy = malloc(strlen(value) + 1);
  strcpy(value_copy, value);

  map->keys[index] = key_copy;
  map->values[index] = value_copy;

  map->size++;
}

double hashmap_load_factor(HashMap* map) {
  return map->size / map->capacity;
}

void hashmap_resize(HashMap* map, size_t capacity) {
  // TODO: implement it
}
