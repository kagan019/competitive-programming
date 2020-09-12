//Square Dance.cpp

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ll T; cin >> T;
    for (ll cn = 1; cn <= T; cn++){
        ll R; ll C;
        cin >> R >> C;
        vector<vector<ll>> df(R, vector<ll>(C));
        for (ll i = 0; i < R; i++) {
            for (ll &x : df[i])
                cin >> x;
        }
        ll ioc = 0;
        vector<pair<ll,ll>> elim;
        bool updated = true;
                        // sum,count (for averaging)
        vector<vector<pair<ll,ll>>> sumcn;
        while(updated) {
            elim.clear();
            elim.resize(0);
            sumcn = vector<vector<pair<ll,ll>>>(R, vector<pair<ll,ll>>(C, make_pair(0,0)));
            updated = false;

            ll ior = 0;
            for (auto &x : df) {
                for (ll &y : x) {
                    ior += y;
                }
            }
            ioc += ior;

            for (auto &x : sumcn) {
                for (auto &y : x) {
                    y = make_pair(0, 0);
                }
            }
            
            auto lastleft = make_pair(-1, -1);
            vector<pair<ll, ll>> lastup(C, make_pair(-1, -1));
            for (ll r = 0; r < R; r++) {
                for (ll c = 0; c < C; c++) {
                    if (df[r][c]){
                        if (lastleft.first >= 0) {
                            auto x = sumcn[lastleft.first][lastleft.second];
                            sumcn[lastleft.first][lastleft.second] = make_pair(x.first + df[r][c], x.second + 1);
                            auto x2 = df[lastleft.first][lastleft.second];
                            sumcn[r][c] = make_pair(sumcn[r][c].first + x2, sumcn[r][c].second + 1);
                        }
                        if (lastup[c].first >= 0) {
                            auto x = sumcn[lastup[c].first][lastup[c].second];
                            sumcn[lastup[c].first][lastup[c].second] = make_pair(x.first + df[r][c], x.second + 1);
                            auto x2 = df[lastup[c].first][lastup[c].second];
                            sumcn[r][c] = make_pair(sumcn[r][c].first + x2, sumcn[r][c].second + 1);
                        }
                        lastleft = make_pair(r,c);
                        lastup[c] = make_pair(r,c);
                    }
                }
                lastleft = make_pair(-1, -1);
            }
            
            for (ll i = 0; i < R; i++) {
                for(ll j = 0; j < C; j++) {
                    pair<ll,ll> y = sumcn[i][j];
                    if (y.second > 0) {
                        ll x = df[i][j];
                        if ((double)x < (double)y.first/(double)y.second) {
                            elim.push_back(make_pair(i,j));
                        }
                    }
                }
                
            }
            
            for (auto &p : elim){
                updated = true;
                df[p.first][p.second] = 0;
            }
        }
        
        cout << "Case #" << cn << ": " << ioc << endl; 
    }
}