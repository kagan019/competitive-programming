#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;

ull sub (ull a, ull b) {
    return (a > b) ? a-b : 0; 
}

int main() {
    int t; cin >> t;
    while(t--) {
        ull a; ull b; ull x; ull y; ull n;
        cin >> a >> b >> x >> y >> n;
        ull u = max(x,sub(a,n));
        ull v = max(y, sub(b, sub(n,sub(a,u))));
        ull w = max(y,sub(b,n));
        ull vv = max(x, sub(a,sub(n,sub(b,w))));
        cout << min(u*v,w*vv) << endl;
    }
}
