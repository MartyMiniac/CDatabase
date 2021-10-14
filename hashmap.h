#ifndef HASHMAP_H
#define HASHMAP_H
#define HASHMAP_ARRAY_SIZE 10

typedef struct hashmap {
    char * key;
    char * value;
    struct hashmap * next;
} hashmap;

void hashmap_initHashap(hashmap ** h);
void hashmap_add(hashmap ** hm, char * key, char * value);
char * hashmap_get(hashmap ** hm, char * key);
char * hashmap_deleteEntry(hashmap ** hm, char * key);

#endif