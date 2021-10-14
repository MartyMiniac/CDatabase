#include "hashmap.h"

hashmap * hm[HASHMAP_ARRAY_SIZE];
void datahandler_init() {
    hashmap_initHashap(hm);
}

void datahandler_addData(char * key, char * value) {
    hashmap_add(hm, key, value);
}

char * datahandler_getData(char * key) {
    return hashmap_get(hm, key);
}