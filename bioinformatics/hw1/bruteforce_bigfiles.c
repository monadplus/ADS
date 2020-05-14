#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#define ASIZE 256


int BF(char *x, int m, char *y, int n) { 
  char *yb,*ini; 
  /* Searching */ 
  long int found=0;
  ini=y;
  for (yb = y; y <= ini+n-m; ++y) 
    if (memcmp(x, y, m) == 0) found++; 
  //printf("j=%d \n",y - yb);
  return found;
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
    n+=BF(pattern,strlen(pattern),text,lbuffer);
    //fgets(text,lbuffer,f);
     fread(text,1,lbuffer,f);
  }
  n+=BF(pattern,strlen(pattern),text,lbuffer);
  printf("n=%ld\n",n);
  
  printf( "Time: %f s\n", (clock()-initemps)/(double)CLOCKS_PER_SEC );
  fclose(f);
  free(text);
  return 0;
}
