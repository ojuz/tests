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

const int N_ = 300505;

int n;
int A[N_+N_];

bool used[N_];
string tmptmp;

int read (InStream &ans, string imp) {
    string res = ans.readToken();tmptmp=res;
    if(res == imp) return -1;
    if(res.length() != n + n) ans.quitf(_wa,"");
    
    stack<int> stk[2];
    for(int i = 1; i <= n; i++) used[i] = false;
    for(int i = 0; i < n+n; i++) {
        if(res[i] != '^' && res[i] != 'v') ans.quitf(_wa, "");
        stack<int> &st = stk[(res[i] == '^')];
        
        if(!used[A[i]]) {
            st.push(A[i]); used[A[i]] = true;
        }else {
            if(st.empty() || st.top() != A[i]) {
                ans.quitf(_wa, "");
            }else {
                st.pop();
            }
        }
    }
    
    if(!stk[0].empty() || !stk[1].empty()) ans.quitf(_wa, "");
    return 1;
}

int main(int argc, char * argv[]) {
    registerTestlibCmd(argc, argv);
    
    n = inf.readInt();
    for(int i = 0; i < n+n; i++) {
        A[i] = inf.readInt();
    }
    
    int ja = read(ans, "INVALID");
    int pa = read(ouf, "IMPOSSIBLE");
    
    if(ja == -1 && pa == -1) {
        quitf(_ok, "");
    }else if(ja == -1 && pa == 1) {
        quitf(_fail, "OMG!!! judge's solution failed");
    }else if(ja == 1 && pa == 1) {
        quitf(_ok, "");
    }else if(ja == 1 && pa == -1) {
        quitf(_wa, "");
    }else {
        quitf(_fail, "something is wrong?");
    }
    return 0;
}
