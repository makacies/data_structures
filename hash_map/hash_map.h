#ifndef _HASH_MAP_H
#define _HASH_MAP_H

#include <stdint.h>

#define INITIAL_CAPACITY 100

typedef struct {
  char** keys;
  char** values;
  size_t size;
  size_t capacity;
} HashMap;

void hashmap_init(HashMap* map);
void hashmap_free(HashMap** map);
uint64_t hashmap_hash(HashMap* map, char* key);
size_t hashmap_normalize(HashMap* map, uint64_t hash);
void hashmap_insert(HashMap* map, char* key, char* value);
void hashmap_remove(HashMap* map, char* key);
char* hashmap_at(HashMap* map, char* key);
double hashmap_load_factor(HashMap* map);

#endif
