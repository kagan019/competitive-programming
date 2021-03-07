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

    vector<ll> tao;
    ll ans = 0;
    for(ll i = 0; i < n; i++) {
        if (ss[i] == 1) {
            tao.push_back(0);
        }
        if (ss[i] == 2) {
            if (!tao.size())
                continue;
            tao[tao.size()-1]++;
        }
        if (ss[i] == 3) {
            //how many songs that use that one
            ll twos = 0;
            for (int i = tao.size() -1; i >= 0; i--) {
                twos += tao[i];
                ans += (MOD+fastExpo(2,twos, MOD)-1) % MOD;
                ans %= MOD;
            }
        }
    }
    cout << ans << endl;

} 