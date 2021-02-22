#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ll n; cin >> n;

    vector<ll>a(n);
    ll s = 0;
    for (ll &x : a) {
        cin >> x;
        s += x;
    }
    if (s%2 == 1) {
        cout << "no" << endl;
        return 0;
    }
        
    int maxpstk = (1000 + n -1) / n;
    vector<vector<pair<ll,ll>>> moves(maxpstk+1,vector<pair<ll,ll>>());
    for (ll t = maxpstk; t > 0; t--) {
        vector<ll> subs(n);
        for (ll i = 0; i < a.size(); i++) {
            ll cando = a[i] / t; 
            subs[i] = cando;
        }
        while(true) {
            ll first = 0;
            while(first < subs.size() && subs[first] == 0) {
                first++;
            }
            if (first == subs.size())
                break;
            ll second = first+1;
            while(second < subs.size() && subs[second] == 0) {
                second++;
            }
            if (second == subs.size())
                break;
            ll take = min(subs[first],subs[second]);
            for (ll u = 0; u < take; u++) {
                moves[t].push_back({first,second});
            }
            subs[first] -= take;
            subs[second] -= take;
            a[first] -= take*t;
            a[second] -= take*t;

        }
    }

    //format answer
    bool flag = false;
    for (ll i = 0; i < a.size(); i++) {
        if (a[i] != 0) {
            cout << "no" << endl;
            return 0;
        }
    }

    cout << "yes" << endl;
    for (ll t = maxpstk; t > 0; t--) {
        for (ll k = 0; k < t; k++) {
            for (ll m = 0 ; m  < moves[t].size(); m++) {
                auto mym = moves[t][m];
                cout << (mym.first+1) << " " << (mym.second+1) << endl;
            }
        }
    }
}