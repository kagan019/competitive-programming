#include <bits/stdc++.h>
using namespace std;

typedef long long ll; 
typedef pair<ll,ll> loc;
#define INF 10000000001 




int main() {
    ll m; ll n; cin >> m >> n;
    vector<vector<ll>> g(m,vector<ll>(n));
    
    for (auto &vv : g) {
        for (auto &x : vv) {
            cin >> x;
        }
    }
    
    vector<vector<ll>> maxladder(m,vector<ll>(n));
    maxladder[m-1][n-1] = 0;
    for (int i = n-2; i >= 0; i--) {
        const int x = max((int)(g[m-1][i+1]-g[m-1][i]),0);
        maxladder[m-1][i] = max(x, (int)maxladder[m-1][i+1]);
    }
    for (int i = m-2; i >= 0; i--) {
        const int x = max((int)(g[i+1][n-1]-g[i][n-1]),0);
        maxladder[i][n-1] = max(x, (int)maxladder[i+1][n-1]);
    }
    for (int i = m-2; i >= 0; i--) {
        for (int j = n-2; j>= 0; j--) {
            const int x = max((int)(g[i+1][j]-g[i][j]),0);
            const int y = max((int)(g[i][j+1]-g[i][j]),0);
            int a = max(x,(int)maxladder[i+1][j]);
            int b = max(y,(int)maxladder[i][j+1]);
            maxladder[i][j] = min(a,b);
        }
    }
    // for (auto &vv : maxladder) {
    //     for (auto x : vv) {
    //         cout << x << " ";
    //     }
    //     cout << endl;
    // }
    cout << maxladder[0][0] << endl;

}