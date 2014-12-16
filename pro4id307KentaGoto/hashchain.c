#ifndef STDLIB_H
#include <stdlib.h>
#endif
#ifndef STRING_H
#ifndef STDIO_H
#include <string.h>
#endif
#include <stdio.h>
#endif
#ifndef ASSERT_H
#include <assert.h>
#endif
#include "hashchain.h"
int nextPrime(int tableSize);
HashTable newTable(int tableSize){
  HashTable H;
  int i;
  H = malloc(sizeof(struct hashtable));
  H->tableSize=nextPrime(tableSize);
  H->ht = malloc(sizeof(struct listnode) * H->tableSize);
  for(i=0;i<H->tableSize; i++)
    H->ht[i]=NULL;
  return H;
}

void clearTable(HashTable H){
  int i;
  Position t;
  for(i=0;i < H->tableSize; i++){
    while(H->ht[i]!=NULL){
      t = H->ht[i];
      H->ht[i] = t->next;
      free(t);
    }
  }
  return;
}

void destroyTable(HashTable H){
  clearTable(H);
  free(H->ht);
  return;
}

Position find(KType key, VType value, HashTable H){
  List L = NULL;
  L = H->ht[h(key,H->tableSize)];
  while(L != NULL && (0 !=strcmp(L->value, value))){
    L = L->next;
}
  return L; 
}
int evenp(int t){
	return (t%2-1);
}

int primep(int t){
  int a = 1;
  int r = t - 1;
  while(r){
    a = (a * r--) % t;
    if(!a) return 0;
  }
  return 1;
}


int nextPrime(int tableSize){
  if(primep(tableSize))
   return tableSize;
  if(evenp(tableSize))
    tableSize++;
  else
    tableSize+=2;
  while(!primep(tableSize))
    tableSize+=2;
  return tableSize;
}

void put(KType key, VType value, HashTable H){
  int ih;
  Position p, t;
  p = find(key,  value, H);
  if(p==NULL){
    t = malloc(sizeof(struct listnode));
    if(!t) {puts("Fatal Error:  out of space!"); assert(0);}
    t->key = key;
    t->value=value;
    ih=h(key,H->tableSize);
    t->next = H->ht[ih];
    H->ht[ih] = t;
  }
  return;
}

VType get(Position p){
	return p->value;
}

VType delete(KType key, VType value, HashTable H){
	return NULL;
}


