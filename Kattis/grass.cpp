#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

double effective_rad(ll r1, ll w) {
    return sqrt((double)(r1*r1)-(double)(w*w/4.0));
}


int main() {
    ll T = 35;
    while(T--) {
        string line;
        getline(cin, line);
        if (line.empty())
            break;
        stringstream ss(line, ios_base::in);
        ll n, l, w;
        ss >> n >> l >> w;
        //build the list of sprinklers, and sort them by position
        
        vector<pair<ll,double>> s;
        for (ll i =0; i < n; i++){
            string line;
            getline(cin, line); // assume line not empty
            ll x, y; 
            stringstream sss(line, ios_base::in);
            sss >> x >> y;
            if (2*y >= w) {
                s.push_back(make_pair(x,effective_rad(y,w)));
            }
        }
        sort(s.begin(),s.end(),[&w](auto a, auto b) {
            return a.first - a.second < b.first - b.second;
        });
        //sorted from leftmost reach ascending, to detect when there is no overlap with the left end of the strip

        // greedy: grab the next sprinkler that reaches as far away as possible from the current. Add to the counter when found.
        ll curind = -1;
        ll nextind;
        ll maxind;
        ll num_sprink = 0;
        bool fail = false;
        while (curind < 0 || s[curind].first + s[curind].second < l) {
            nextind = curind;
            maxind = curind;
            while ((curind < 0 
                    && s[nextind+1].first - s[nextind+1].second <= 0) 
                || (curind >= 0 
                    && nextind+1 < s.size() 
                    && s[nextind+1].first - s[nextind+1].second <= s[curind].first + s[curind].second)){
                nextind++;
                if (maxind < 0
                    || (maxind >= 0 
                        && s[nextind].first + s[nextind].second >= s[maxind].first + s[maxind].second)) {
                    maxind = nextind;
                }
            }
            // maxind is the farthest reaching sprinkler whose radius overlaps enough with curind's radius
            if (maxind == curind) {
                fail=true;
                break;
            }
            curind = maxind;
            num_sprink++;
        }
        if (!fail) {
            if (s[curind].first - s[curind].second <= 0)
                cout << 1 << "\n";
            else
                cout << num_sprink << "\n";
        }
        else
            cout << -1 << "\n";
    }    
}