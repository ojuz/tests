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

using namespace std; 
typedef long long ll; 
typedef unsigned long long llu; 
typedef double lf;
typedef unsigned int uint;
typedef long double llf;
typedef pair<int, int> pii;

const int N_ = 2225, SZ = 2222;
const int PN = 15;
const int P[] = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47};
const int MOD = (int)1e9 + 7;

int N, freq[SZ+10];
ll Table[1 << PN], Table_prev[1 << PN];
int A[SZ+10], D[SZ+10];
ll res = 0;
ll ones = 0;

int main(int argc, char* argv[]) {
freopen(argv[1],"r",stdin);
freopen(argv[2],"w",stdout);
	scanf("%d", &N);
	for(int i = 1; i <= N; i++) {
		int x; scanf("%d", &x);
		++freq[x];
	}

	for(int n = 1; n <= SZ; n++) D[n] = n;
	for(int i = 0; i < PN; i++) {
		for(int n = P[i]; n <= SZ; n += P[i]) {
			A[n] |= 1<<i;
			while(D[n] % P[i] == 0) D[n] /= P[i];
		}
	}

	Table[0] = 1;
	for(int i = 0; i < freq[1]; i++) Table[0] = (Table[0] * 2) % MOD;
	for(int n = 2; n <= SZ; n++) if(freq[n] != 0 && D[n] == 1) {
		for(int state = 0; state < (1<<PN); state++) if((state & A[n]) == 0) {
			ll &v = Table[state | A[n]];
			v += Table[state] * freq[n]; v %= MOD;
		}
	}
	
	for(int d = P[PN-1]+1; d <= SZ; d++) if(A[d] == 0) {
		for(int state = 0; state < (1<<PN); state++) Table_prev[state] = Table[state];
		for(int n = d, k = 1; n <= SZ; n += d, k++) if(freq[n] != 0) {
			for(int state = 0; state < (1<<PN); state++) if((state & A[k]) == 0) {
				ll &v = Table[state | A[k]];
				v += Table_prev[state] * freq[n]; v %= MOD;
			}
		}
	}

	res = 0;
	for(int state = 0; state < (1<<PN); state++) res = (res + Table[state]) % MOD;
	res -= (N + 1);
	res = (res + MOD) % MOD;

	printf("%lld\n", res);
	return 0;
}
