#include "testlib.h"
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
typedef double lf;
typedef long double llf;
typedef unsigned long long llu; 
typedef pair<int, int> pii;

using namespace std;

ll C;

int N, K;
const int N_ = 305, K_ = 305;
const ll MAXV = (ll)1e18;
ll Table[2][K_];

bool read (InStream &ans) {
	N = ans.readInt(1, 300, "N");
	ans.readSpace();
	K = ans.readInt(1, 300, "K");
	ans.readEoln();

	Table[0][0] = 1;
	for(int j = 1; j <= K; j++) Table[0][j] = 0;
	for(int i = 1; i <= N; i++) {
		int t = i & 1;
		int a = ans.readInt(1, K, "a_i");
		if(i + 1 <= N) ans.readSpace();
		for(int j = 0; j <= K; j++) {
			Table[t][j] = Table[!t][j];
			if(j >= a) Table[t][j] = min(Table[t][j] + Table[!t][j - a], MAXV);
		}
	}	

	if(Table[N & 1][K] != C) {
		ans.quitf(_wa, "the number of ways is not correct");
	}
	return true;
}

int main(int argc, char * argv[]) {
    registerTestlibCmd(argc, argv);

    C = inf.readLong(1, (ll)1e18, "C");
    
    bool ja = true;//read(ans);
    bool pa = read(ouf);

	if(ja && pa) {
		quitf(_ok, "");
	}else {
		quitf(_fail, "something is wrong?");
	}
    return 0;
}
