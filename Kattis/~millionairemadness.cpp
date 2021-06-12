#include <bits/stdc++.h>
using namespace std;

typedef long long ll; 
typedef pair<ll,ll> loc;
#define INF 10000000001 


vector<pair<ll,ll>> nbrs(pair<ll,ll> &from, ll m, ll n, vector<vector<bool>> &visited) {
    const vector<pair<ll,ll>> dirs = {{1,0},{0,1}, {-1,0}, {0,-1}};
    vector<pair<ll,ll>> ret;
    for (auto d : dirs) {
        pair<ll,ll> nbr = {from.first + d.first, from.second + d.second};
        bool iny = 0 <= nbr.first && nbr.first < m;
        bool inx = 0 <= nbr.second && nbr.second < n;
        if (!inx || !iny) continue;
        if (!visited[nbr.first][nbr.second])    
            ret.push_back(nbr);
    } 
    return ret;
}

int main() {
    ll m; ll n; cin >> m >> n;
    vector<vector<ll>> g(m,vector<ll>(n));
    
    for (auto &vv : g) {
        for (auto &x : vv) {
            cin >> x;
        }
    }
    
    vector<vector<ll>> maxladder(m,vector<ll>(n, INF));
    maxladder[0][0] = 0;
    vector<vector<bool>> visited(m,vector<bool>(n, false));
    visited[0][0] = true;
    vector<pair<loc,ll>> heap;
    auto cmp = [&maxladder](pair<loc,ll> &a, pair<loc,ll> &b) {
        return a.second > b.second;
    };
    heap.push_back({{0,0},0});
    while (heap.size()) {
        pop_heap(heap.begin(), heap.end(), cmp);
        auto hx = heap.back();
        heap.pop_back();
        auto x = hx.first;
        

        visited[x.first][x.second] = true;
        for (auto nbr : nbrs(x,m,n,visited)) {
            maxladder[nbr.first][nbr.second] = min(
                maxladder[nbr.first][nbr.second], 
                max(maxladder[x.first][x.second],g[nbr.first][nbr.second] - g[x.first][x.second])
            );
            heap.push_back({nbr,maxladder[nbr.first][nbr.second]});
            push_heap(heap.begin(),heap.end(),cmp);
        }
    }
    cout << maxladder[m-1][n-1];
}