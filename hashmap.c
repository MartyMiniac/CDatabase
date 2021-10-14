#include "hashmap.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int hashString(char * s);

void hashmap_initHashap(hashmap ** h) {
    for(int i=0; i<HASHMAP_ARRAY_SIZE; i++) {
        h[i]=NULL;
    }
}

int hashString(char * s) {
    int sum=0;
    for(int i=0; s[i]!='\0'; i++) {
        sum+=(int)s[i];
    }

    return sum%HASHMAP_ARRAY_SIZE;
}

void hashmap_add(hashmap ** hm, char * key, char * value) {
    int index = hashString(key);
    if(hm[index]==NULL) {
        hm[index]=malloc(sizeof(hashmap));
        hm[index]->key=key;
        hm[index]->value=value;
        hm[index]->next=NULL;
    }
    else {
        hashmap * h = hm[index];

        if(strcmp(h->key, key)==0) {
            printf("\nHASHMAP_H ERROR: duplicate key not allowed\n");
            return;
        }

        while(h->next!=NULL) {
            if(strcmp(h->next->key, key)==0) {
                printf("\nHASHMAP_H ERROR: duplicate key not allowed\n");
                return;
            }
            h=h->next;
        }

        h->next=malloc(sizeof(hashmap));
        h->next->key=key;
        h->next->value=value;
        h->next->next=NULL;
    }
}

char * hashmap_get(hashmap ** hm, char * key) {    
    int index = hashString(key);
    hashmap * h = hm[index];
    while(h!=NULL) {
        if(strcmp(h->key, key)==0) {
            return h->value;
        }
        h=h->next;
    }

    printf("\nHASHMAP_H ERROR: key not found returned NULL");
    return NULL;
}

char * hashmap_deleteEntry(hashmap ** hm, char * key) {
    int index = hashString(key);
    if(hm[index]==NULL) {
        printf("\nHASHMAP_H ERROR: key not found returned NULL");
        return NULL;
    }
    else {
        hashmap * h = hm[index];
        if(strcmp(h->key, key)==0) {
            char * str = h->value;
            hm[index]=h->next;
            free(h);
            return str;
        }
        while(h->next!=NULL) {
            if(strcmp(h->next->key, key)==0) {
                hashmap * tmp = h->next;
                h->next=tmp->next;
                char * str = tmp->value;
                free(tmp);
                return str;
            }
            h=h->next;
        }        
        printf("\nHASHMAP_H ERROR: key not found returned NULL");
        return NULL;
    }
}