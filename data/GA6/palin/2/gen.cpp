#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char S[100025];
char fn[100];

int main() {
  for(int d = 4+12; d <= 12+3+12; d++) {
   sprintf(fn, "/var/www/judge/335/0/data/2/%d.in", d-3-12);
   FILE *in_2 = fopen(fn, "r");// "/var/www/judge/335/0/data/2/%d.in", d-3);
   fscanf(in_2, "%s", S); int n = strlen(S);
   sprintf(fn, "%d.in", d); n *= 2;
   FILE *in = fopen(fn, "w");
   fprintf(in, "%s%s\n%d\n", S, S, 10000);
   for(int q = 1; q <= 10000; q++) {
     int x = rand() % n, y = rand() % n;
     if(x > y) { int t = x; x = y; y = t; }
     fprintf(in, "%d %d\n", x+1, y+1);
   }
fclose(in);  
   sprintf(fn, "./prog %d.in %d.out", d, d);
   system(fn);
   printf("  : %d\n", d);
  }
  return 0;
}
