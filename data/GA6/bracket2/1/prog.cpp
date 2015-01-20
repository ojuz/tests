#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <memory.h> 
#include <math.h> 
#include <assert.h> 
#include <stack> 
#include <queue> 
#include <map> 
#include <set> 
#include <algorithm> 
#include <string> 
#include <functional> 
#include <vector> 
#include <deque> 
#include <utility> 
#include <bitset> 
#include <limits.h>  
#include <time.h>

using namespace std; 
typedef long long ll; 
typedef unsigned long long llu; 
typedef double lf;
typedef unsigned int uint;
typedef long double llf;
typedef pair<int, int> pii;

char S[50];
int res;

int main(int argc, char *argv[]) {
	freopen(argv[1], "r", stdin);
	freopen(argv[2], "w", stdout);

	scanf("%s", S);
	int n = strlen(S);

	res = (int)1e9;
	for(int l = 0; l <= n; l++) {
		for(int r = 0; r <= n; r++) {
			int depth = +l;
			bool chk = true;
			for(int i = 0; i < n && chk; i++) {
				depth += (S[i] == '(') ? +1 : -1;
				if(depth < 0) chk = false;
			}
			depth -= r;
			if(depth == 0 && chk) res = min(res, l + r);
		}
	}

	printf("%d\n", res);

	return 0;
}
