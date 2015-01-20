#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<string>
#include<algorithm>
#include<fstream>
#include<sstream>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<deque>
#include<cassert>
#include<complex>
using namespace std;

#define LL long long

const int MaxN = 300020;

char str[MaxN], S[MaxN];

int len, n;

int T[MaxN];

void CalcPal()
{
	int j = 0;
	T[j] = 0;
	for(int k = 1; k < n; ++ k)
	{
		int p = j + T[j];
		if(k <= p)
		{
			int i = j - (k - j);
			T[k] = min(p - k, T[i]);
			if(k + T[i] < p) continue;
		} else T[k] = 0;
		for(; T[k] < k && T[k] + k < n - 1 && S[k - T[k] - 1] == S[k + T[k] + 1]; ++ T[k]);
		j = k;
	}
}

int odd[MaxN], even[MaxN];
int N;

void InitPalindrome() {
	n = 0;
	for(int i=1;i<=len;++i)
	{
		S[n ++] = '$';
		S[n ++] = str[i];
	}
	S[n ++] = '$';
	
	CalcPal();
	
	for(int i = 1; i <= N; ++ i) {
	  odd[i] = T[2 * i - 1] + 1 >> 1;
	  even[i] = T[2 * i] >> 1;
	}
}

struct BIT {
  LL tar[MaxN];
  int n;
  void init(int _n) {
    n = _n;
    fill(tar, tar + 1 + n, 0);
  }
  void add(int p, int x) {
    for(; p <= n; p += p& -p)
      tar[p] += x;
  }
  LL get(int p) { // sum{x <= p} value[x]
    LL ret=0;
    for(; p > 0; p -= p&-p)
      ret+=tar[p];
    return ret;
  }
}X, Y;

struct Query {
  int L, R, id, len, mid;
  LL ans;
  void read(int _id) {
    id = _id;
    scanf("%d %d", &L, &R);
    len = R - L + 1;
    mid = L + R >> 1;
    int allow = len + 1 >> 1;
    if(len & 1)
      ans = min(allow, odd[mid]);
    else
      ans = - min(allow, even[mid]);
  }
  
  int cur_L, cur_R;
}D[MaxN];
int Q;
vector<int> arr[MaxN];
LL g[MaxN], f[MaxN], h[MaxN];

void Solve_Left() {
  // Radix Sort
  for(int i=0;i<=N;++i)arr[i].clear();
  for(int i=0;i<Q;++i)
    if(D[i].len > 1)
      arr[D[i].cur_R].push_back(i);
  // init f_v
  f[0]=0;
  for(int i=1;i<=N;++i)
    f[i] = f[i - 1] + odd[i] + even[i];
  // init f_l
  g[0]=0;
  for(int i=1;i<=N;++i) {
    g[i] = g[i - 1]
          + (i - odd[i] + 1)
          + (even[i] > 0 ? i - even[i] + 1 : 0);
  }
  // init h
  h[0]=0;
  for(int i=1;i<=N;++i) {
    h[i] = h[i - 1] + 1 + (even[i] > 0);
  }
  // init BIT
  X.init(N); Y.init(N);
  // compute
  for(int i=1;i<=N;++i) {
    // insert palindrome
    // odd
    X.add(i - odd[i] + 1, 1);
    Y.add(i - odd[i] + 1, i - odd[i] + 1);
    // even
    if(even[i] > 0) {
      X.add(i - even[i] + 1, 1);
      Y.add(i - even[i] + 1, i - even[i] + 1);
    }
    
    vector<int>& lst = arr[i];
    for(int j=0;j<lst.size();++j) {
      int k = lst[j];
      int R = D[k].cur_R, L = D[k].cur_L;
      LL &ans=D[k].ans;
      ans += f[R]-f[L - 1];
      ans += h[L-1] * L - g[L-1];
      ans += Y.get(L - 1);
      ans -= L * X.get(L - 1);
    }
    
  }
}

void Solve() {
  for(int i=0;i<Q;++i) {
    D[i].cur_L = D[i].L;
    D[i].cur_R = (D[i].len & 1 ? D[i].mid - 1 : D[i].mid);
  }
  Solve_Left();
  
  reverse(odd + 1, odd + 1 + N);
  reverse(even, even + 1 + N);
  for(int i=0;i<Q;++i) {
    D[i].cur_L = N - D[i].R + 1;
    D[i].cur_R = N - (D[i].mid + 1) + 1;
  }
  Solve_Left();
}

int main(int argc, char *argv[])
{
	freopen(argv[1],"r",stdin);
	freopen(argv[2],"w",stdout);
	
	scanf("%s", str + 1);
	N = len = strlen(str + 1);
	
	InitPalindrome();

  scanf("%d", &Q);
  for(int i=0;i<Q;++i)
    D[i].read(i);

  Solve();
  
  for(int i=0;i<Q;++i)
    printf("%lld\n", D[i].ans);
}
