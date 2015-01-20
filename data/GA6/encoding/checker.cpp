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

const int maxn = 2000;
int i, j, n;
ll ja, pa, a[maxn + 10];
string s, prv;

int main(int argc, char * argv[]) {
	registerTestlibCmd(argc, argv);

	n = inf.readLong();
	for (int i = 1; i <= n; i++) a[i] = inf.readLong();

	ll pr_ja = ans.readLong(); ans.readEoln();
	ja = 0;
	for (int i = 1; i <= n; i++) {
		s = ans.readString();
		ja = ja + a[i] * s.length();
	}

	if (ja != pr_ja) quitf(_fail, "judge's solution is wrong\n", pr_ja, ja);

	ll pr_pa = ouf.readLong(); ouf.readEoln();
	pa = 0;
	for (int i = 1; i <= n; i++) {
		s = ouf.readWord("[0-1]+"); ouf.readEoln();
		if (s.length() > n) quit(_wa, "H_i (코드)의 길이가 n보다 깁니다.");

		if (prv >= s) {
			quitf(_wa, "H_i가 H_(i+1)보다 사전순으로 앞에 있지 않습니다.");
		}
		else if (i > 1 && (prv.length() < s.length()) && (prv == s.substr(0, prv.length()))) {
			quitf(_wa, "H_i가 H_j의 접두사가 되는 쌍 (i, j)가 존재하면 안 됩니다.");
		}

		pa = pa + a[i] * s.length();
		prv = s;
	}


	if (pa != pr_pa) quitf(_fail, "출력한 답과 아래에 출력한 코드로 계산한 결과가 다르면 안 됩니다\n", pr_pa, pa);

	if (pa > ja) quitf(_wa, "", ja, pa);
	if (pa < ja) quitf(_fail, "", ja, pa);

	quitf(_ok, "", ja);

	return 0;
}