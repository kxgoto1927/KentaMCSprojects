#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <assert.h>
#include "hashchain.h"

#define NUMFUNS 9

int hashFunction=0;

struct htstats {
  int numElements;
  int tableSize;
  int hashFunction;
  float loadFactor;
  int* collisions;
  int maxCollisions;
  float PutGetTime;
};
/*local function declarations */
void rand_words(int numwords);
char * newString(int size);
int * newArrayi (int n);
KType* newArrays(int n);
void freeArrayi(int* a);
void printResults(struct htstats hs, struct htstats hfsummary[]);
int findArrayMaxi(int *a, int n);
void allSummary(struct htstats hfSummary[], int n);


int main(int argc, char **argv){
  int i, n, ifun;
  clock_t t1, t2;
  float dt;
  KType* data;
  HashTable H;
  Position p;
  KType key;
  VType value, v1;
  FILE * fid;
  struct htstats hs;
  struct htstats hfsummary[NUMFUNS];
  hs.numElements = atoi(argv[1]);
  hs.loadFactor = atoi(argv[2]);
  rand_words(hs.numElements);
  fid = fopen("randwords.txt", "r");
  if(!fid) puts("file not opened.");
  data = newArrays(hs.numElements);
  for(i=0; i<hs.numElements; i++)
    fscanf(fid, " %s", data[i]);
  n = hs.tableSize = (int)(hs.numElements/hs.loadFactor);
  for(ifun=0; ifun < NUMFUNS; ifun++){
    hashFunction = hs.hashFunction = ifun;
    hs.collisions = newArrayi(n);
    H = newTable(n);
    t1=clock();
    for(i=0;i<hs.numElements;i++){
      key=data[i];
      value=newString(8);
      strcpy(value,key);
      put(key,value,H);
      hs.collisions[h(key,n)]++;
    }
    for(i=0;i<hs.numElements;i++){
      p = find(data[i],data[i],H);
	v1 = get(p);
}
    t2=clock();
    dt = (float)(t2-t1)/CLOCKS_PER_SEC;
    hs.PutGetTime = dt;
    printResults(hs,hfsummary);
    destroyTable(H);
    freeArrayi(hs.collisions);
  }
  allSummary(hfsummary,NUMFUNS);
  return 0;
}
/* end main */

char* newString(int size){
  char *s;
  s = (char*)malloc(size * sizeof(char) + 1);
  if(!s){puts("Out of space!"); assert(0);}
  s[0] = '\0';
  return s;
}

int* newArrayi(int n){
  int * a, i;
  a = (int*)malloc(n*sizeof(int));
  if(!a) {puts("Out of space!"); assert(0);}
  for(i=0;i<n;i++)
    a[i]=0;
  return a;
}

KType* newArrays(int n){
  KType * a;
  int i;
  a = (KType * )malloc(n*sizeof(char*));
  if(!a){puts("Out of space!"); assert(0);}
  for(i=0;i<n;i++){
    a[i]=newString(8);
}
  return a;
}

void freeArrayi(int* a){
  free(a);
}


void printResults(struct htstats hs, struct htstats hfsummary[]){
  int i, n, answer;
  n = hs.tableSize;
  hs.maxCollisions = findArrayMaxi(hs.collisions,n);
  printf("numElements:\t\t%d\n"
	 "tableSize:\t%d\n"
	 "hashFunction:\t%d\n"
	 "loadFactor:\t%.2f\n"
	 "maxCollisions:%d\n"
	 "PutGetTime:\t%.3f seconds\n",
	 hs.numElements,
	 hs.tableSize,
	 hs.hashFunction,
	 hs.loadFactor,
	 hs.maxCollisions,
	 hs.PutGetTime);
  puts("print collision array? 1=yes, 0=no");
  scanf(" %d", &answer);
  if(answer){
    puts("Number of collisions at each hash index:");
    for(i=0;i<n;i++)
      printf("-%d",hs.collisions[i]);
  }
  puts("");
  puts("===========================new hash function=====================");
  hfsummary[hs.hashFunction]=hs;
  return;
}

int findArrayMaxi(int *a, int n){
  int i, max;
  max = a[0];
  for(i=1;i<n;i++)
    if(max < a[i])
      max = a[i];
  return max;
}

void allSummary(struct htstats hfsummary[], int n){
  int i;
  printf("numElements: %d\n", hfsummary[0].numElements);
  printf("tableSize: %d\n", hfsummary[0].tableSize);
  printf("loadFactor: %.2f\n", hfsummary[0].loadFactor);
  puts("hashFunction \t Max Collisions \t Put&GetTime(sec)");
  for(i=0;i<n;i++)
    printf("%d\t\t%d\t\t%.3f\n",
	   hfsummary[i].hashFunction,
	   hfsummary[i].maxCollisions,
	   hfsummary[i].PutGetTime);
  return;
}
