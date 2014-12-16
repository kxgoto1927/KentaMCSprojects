#ifndef _HashChain_H
typedef char * KType;
typedef char * VType;

struct listnode;
typedef struct listnode *Position;
struct hashtable;
typedef struct hashtable *HashTable;


#define HASH_FUNCTION 1

HashTable newTable(int tableSize);
void clearTable(HashTable H);
void destroyTable(HashTable H);
Position find(KType key, VType value, HashTable H);
void put(KType key, VType value, HashTable H);
VType get(Position P);
VType delete(KType key, VType value, HashTable H);
int h(KType key, int tableSize);
int primep(int t);
int evenp(int t);

#endif
struct listnode {
  KType key;
  VType value;
  struct listnode * next;
};

typedef struct listnode * List;
struct hashtable{
  int tableSize;
  List * ht;
};
