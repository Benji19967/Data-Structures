#include "singly_linked_list.h"

// #define NUM_BUCKETS 1000

typedef struct Hashmap {
  int num_elements;
  int num_buckets;
  Node *buckets[];
} Hashmap;

typedef struct HashmapKV {
  int key;
  int value;
} HashmapKV;

Hashmap *hashmap_new(int num_buckets);
int hashmap_hash(int key, int num_buckets);
void hashmap_insert(Hashmap *map, int key, int value);
HashmapKV *hashmap_get(Hashmap *map, int key);

void hashmap_print(Hashmap *map, int num_buckets);
