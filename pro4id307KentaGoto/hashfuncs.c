#include "hashchain.h"
#ifndef STDIO_H
#include <stdio.h>
#endif
#ifndef ASSERT_H
#include <assert.h>
#endif
#include <math.h>
#include <time.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>


extern int hashFunction;
static int h0(KType key, int tableSize);
static int h1(KType key, int tableSize);
static int h2(KType key, int tableSize);
static int h3(KType key, int tableSize);
static int h4(KType key, int tableSize);
static int h5(KType key, int tableSize);
static int h6(KType key, int tableSize);
static int h7(KType key, int tableSize);
static int h8(KType key, int tableSize);

int h(KType key, int tableSize){
  int (*hf)(KType, int);
  switch(hashFunction){
  case 0: hf=h0; break;
  case 1: hf=h1; break;
  case 2: hf=h2; break;
  case 3: hf=h3; break;
  case 4: hf=h4; break;
  case 5: hf=h5; break;
  case 6: hf=h6; break;
  case 7: hf=h7; break;
  case 8: hf=h8; break;
  default:
    puts("ERROR:bad hash function choice!");
    assert(0);
  }
    return hf(key,tableSize);
}

static int h0(KType key, int tableSize){
  return key[0] % tableSize;
}

static int h1(KType k, int tableSize){
  int base = 31;
  unsigned int h = 0;
  for(;*k !='\0';k++)
    h = (h*base + *k);
  return h % tableSize;
}

static int h2(KType k, int tableSize){
  int base = 31;
  int h = 0;
  for(;*k !='\0';k++)
    h = (h*base + *k)%tableSize;
  return h;
}
static int h3(KType k, int tableSize){
  unsigned int h = 0;
  while(*k != '\0')
    h = (h<<5) + *k++;
  return h % tableSize;
}
static int h4(KType k, int tableSize){
  unsigned int h = 0;
  while(*k != '\0')
    h = ((h<<5) + *k++) % tableSize;
  return h;
}
static int h5(KType k, int tableSize){
  unsigned int h = 0;
  while(*k != '\0')
    h += *k++;
  return h % tableSize;
}
static int h6(KType k, int tableSize){
  return (k[0] + 27*k[1] + 729*k[2])%tableSize;
}

union hh {
  unsigned number;
  char s[4];
};

/* Bad hash function */
static int h7(KType k, int tableSize){
  int i = 0;
  int c = 0;
  union hh u;
  u.number = 0;
  for(; k[i] != '\0'; i++){
    c = i % 4;
    while(c){
      int index = i - c;
      u.s[c] *= k[i];
      u.s[c] += k[index] << 2;
      u.s[c--] += k[i] & 0xAA;
    }
    u.number *= 31;
  }
  return u.number % tableSize;
}
/* Good hash function */
static int h8(KType k, int tableSize){
  int i = 0;

	 char buf[64];
  unsigned int out=0;

  for(; i< 8; i++){
    if(k[i]!='\0'){
    	int j = 0;
      for(; j < 8; j++){
	buf[i*8 + j] = (k[i]&(1<<j))>0;
      }
  }
  }
  errno=0;
  for(; i<64; i++){
    out += (buf[i]<<i);
  }

  return out % tableSize;


}


