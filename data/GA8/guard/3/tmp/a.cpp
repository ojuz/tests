#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const int MAXA = 44;
int pn, primes[MAXA];
int divisor[MAXA];

int main() {
 for(int i = 2; i < MAXA; i++) {
  if(divisor[i] != 0) continue;
  divisor[i] = i;
  for(int j = i*i; j <= MAXA; j+=i) divisor[j] = i;
  primes[pn++] = i; printf("%d\n", i);
} char fn[1000];
 for(int d = 41; d <= 50; d++) {
  sprintf(fn, "%d.in", d);
  FILE *in = fopen(fn, "w");
  int n = 2222 - rand() % 100;
  fprintf(in, "%d\n", n);
  for(int i = 0; i < n; i++) {
   if(rand() % 100 == 0) fprintf(in, "%d", rand()%MAXA+1);
   else if(rand() % 50 == 0) fprintf(in, "1");
   else fprintf(in, "%d", primes[rand()%pn]);
   if(i == n-1) fputs("\n",in); else fprintf(in, " ");
  }
  fclose(in);
  sprintf(fn, "./guard %d.in %d.out", d, d);
  system(fn);
 } 
}
