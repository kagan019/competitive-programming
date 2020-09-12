#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int main() {
    ll T; cin >> T;
    for(ll t = 1; t <= T; t++){
        ll n; cin >> n;
        vector<ll> x(n), y(n);
        for (ll &xi : x) cin >> xi;
        for (ll &yi : y) cin >> yi;
        sort(x.begin(), x.end(), [](ll a, ll b){ return a > b;});
        sort(y.begin(), y.end(), [](ll a, ll b){ return a < b;});

        long long sum = 0;
        for (ll i = 0; i < x.size(); i++){
            sum += x[i]*y[i];
        }
        cout << "Case #" << t << ": " << sum << "\n";
    }
}