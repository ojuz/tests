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
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;

const ll INF = (ll)1e18 + 5;

ll mul (ll a, ll b) {
    if(a >= INF || b >= INF) return INF;
    if((double)INF / a < b) return INF;
    return a * b;
}

pll solve (ll a, ll b, ll p, ll q) {
    if(a * b == 0) return pll(0, 0);
    
    pll last = solve(b, a%b, p, q);
    if(a >= b) {
        return pll(
                   min(last.first + p, last.second + mul(q, a/b)),
                   last.first + min(p + p, mul(q, (a/b)))
                   );
    }else {
        return pll(last.second, last.first);
    }
    
}

char str[1000];

int main() {
    freopen("31.in", "r", stdin);
    freopen("31.out", "w", stdout);
    
    int TC; scanf("%d", &TC);
    while(TC--) {
        ll a, b, p, q;
        assert(scanf("%lld%lld%lld%lld", &a, &b, &p, &q) == 4);
        printf("%lld\n", solve(a, b, p, q).first);
    }
    assert(scanf("%s",str) != 1);
    return 0;
}
