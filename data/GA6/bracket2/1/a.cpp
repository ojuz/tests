#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

char fn[100];
char S[100];

int main() {
 srand(time(NULL));
 for(int d = 8; d <= 24; d++) {
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
  
  if(d % 3 == 0) { // 답 1
   if(rand()&1) fprintf(in, "%s\n", S+1);
   else { S[n-2] = 0; fprintf(in, "%s\n", S); }
  }else { // 답 2
   if(chk || rand()%3 == 0) {
    if(rand()&1) fprintf(in, "%s\n", S+2);
    else { S[n-2] = S[n-3] = 0; fprintf(in, "%s\n", S); }
   }else {
    S[n-2] = 0; fprintf(in, "%s\n", S+1);
   }
  }
  
  fclose(in);

  sprintf(fn, "./prog %d.in %d.out", d, d);
  system(fn);
  sprintf(fn, "%d.out", d);
  FILE *out = fopen(fn, "r");
  int res; fscanf(out, "%d", &res);
  if(1 <= res && res <= 2) break;
  fclose(out);
 }
 }
 return 0;
}
