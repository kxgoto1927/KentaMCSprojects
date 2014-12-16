#include <stdio.h>
#include <stdlib.h>
#define TEST_DRIVER 0
void rand_words(int n);
void rand_words(int n){
	int i, j, ch;
	int k = 'z' - 'a' + 1;
	double x = RAND_MAX + 1.0;
	FILE *fid;
	fid = fopen("randwords.txt", "w");
	for (i=0; i<n; i++){
		for (j=0; j<8; j++){
			ch = 'a' + rand()*(k/x);
			fputc(ch,fid);
		}
		fputc(' ', fid);
		if(!((i+1)%8))
			fputc('\n', fid);
	}
	fclose(fid);
	return;

}
#if TEST_DRIVER
int main(){
	int n;
	puts("How many words?");
	scanf("%d", &n);
	rand_words(n);
	return 0;
}
#endif
