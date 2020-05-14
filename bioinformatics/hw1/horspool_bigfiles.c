#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#define ASIZE 256

void preBmBc(char *x, int m, long int bmBc[]) {
   int i;
 
   for (i = 0; i < ASIZE; ++i)
      bmBc[i] = m;
   for (i = 0; i < m - 1; ++i)
      bmBc[x[i]] = m - i - 1;
}
long int HORSPOOL(char *x, int m, char *y, int n) {
  long int j, bmBc[ASIZE],num=0;
   char c;
   /* Preprocessing */
    preBmBc(x, m, bmBc);

   /* Searching */
   j = 0;
   while (j <= n - m) {
      c = y[j + m - 1];
      if (x[m - 1] == c && memcmp(x, y + j, m - 1) == 0)
	//printf("j=%d \n",j);
	num++;
      j += bmBc[c];
   }
   return num;
}

int main(int argc, char *argv[])
{

  FILE *f;
  char pattern[256];
  char filename[256];
  char *text;
  long int  n,lbuffer;
  clock_t initemps;
  if (argc==1){
    printf("    1:: file\n");
    printf("    2:: pattern\n");
    printf("    3::length of the buffer\n");
    exit(-1);
  }
  lbuffer=atoi(argv[3]);
  sprintf(pattern,"%s",argv[2]);
  sprintf(filename,"%s",argv[1]);
  printf("pattern: %s \n",pattern);
  text = (char *) malloc ((lbuffer+1) *sizeof(char));
  if (!(f = fopen(filename, "r"))) {
    fprintf (stderr, "I can't open the file: %s\n", filename);
    exit(1);
  }
  initemps=clock();
  n=0;
  fread(text,1,lbuffer,f); 
  //fgets(text,lbuffer,f);
  while (!feof(f)){
    //printf("text=%s\n",text);
    n+=HORSPOOL(pattern,strlen(pattern),text,lbuffer);
    //fgets(text,lbuffer,f);
     fread(text,1,lbuffer,f);
  }
  n+=HORSPOOL(pattern,strlen(pattern),text,lbuffer);
  printf("n=%ld\n",n);
  
  printf( "Time: %f s\n", (clock()-initemps)/(double)CLOCKS_PER_SEC );
  fclose(f);
  free(text);
  return 0;
}
