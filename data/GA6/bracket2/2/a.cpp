#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

char fn[100];
char S[100];

int main() {
 srand(time(NULL));
 for(int d = 1; d <= 24; d++) {
 while(1){
  int chk,n,depth; // = 3 +  rand() % 7 + ((d / 5) * 10), d = 0;
  do { memset(S,0,sizeof S);
  n = 3 +  rand() % 7 + ((d / 5) * 10), depth = 0, chk = 0;
  //printf("   %d %d\n", n, d);
  for(int i = 0; i < n; i++) {
   if(depth == 0) S[i] = '(', ++depth, chk = 1;
   else { S[i] = rand() % 2 ? '(' : ')'; depth += (S[i] == '(') ? +1 : -1; }
  }
  for(int i = 0; i < depth; i++) S[i+n] = ')', S[i+n+1]=0;
  n += depth;
  }while(n > 50);
  printf("%s %d %d\n", S, strlen(S), chk);
  
  sprintf(fn, "%d.in", d);
  FILE *in = fopen(fn, "w");
  
  int l = rand() % (n-3) + 3;
  if(rand() & 2) {
    fprintf(in, "%s\n", S+l);
  }else {
    for(int i = n-1; i >= n-l; i--)  S[i] = 0;
    fprintf(in, "%s\n", S);
  }

  fclose(in);

  sprintf(fn, "./prog %d.in %d.out", d, d);
  system(fn);
  sprintf(fn, "%d.out", d);
  FILE *out = fopen(fn, "r");
  int res; fscanf(out, "%d", &res);
  if(1 <= res) {
    printf("  : res = %d\n", res);
    break;
  }


  fclose(out);
 }
//  printf("  : res = %d\n", res);
 }
 return 0;
}
