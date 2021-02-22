#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll fastExpo(ll a, ll k, ll p) {
    int res = 1;
    while (k != 0) {
        if ((k & 1) == 1) {
            res *= a;
            res %= p;
        }
        k >>= 1;
        a *= a;
        a %= p;
    }
    return res;
}

int main(){
    const ll MOD = 1000000007;
    int n; cin >> n;
    vector<int> ss(n);
    for (int &x : ss)
        cin >> x;

    vector<ll> twosb4threes;
    ll ans = 0;
    for(ll i = n-1; i >= 0; i--) {
        if (ss[i] == 3) {
            twosb4threes.push_back(0);
        }
        if (ss[i] == 2) {
            if (twosb4threes.size() == 0)
                continue;
            twosb4threes[twosb4threes.size()-1]++;
        }
        if (ss[i] == 1) {
            //how many songs that use that one
            ll twos = 0;
            for (ll threescmp = twosb4threes.size()-1; threescmp >= 0 ; threescmp--) {
                twos += twosb4threes[threescmp];
                ans += (MOD + fastExpo(2,twos,MOD)-1) % MOD;
                ans %= MOD;
            }
            
        }
    }
    cout << ans << endl;

} 