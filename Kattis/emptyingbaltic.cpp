#include <bits/stdc++.h>
using namespace std;


typedef long long whole;

struct water{
    whole first;
    whole second;
    whole flow;
};



int main() {
    whole w,h;
    cin >> h >> w;
    vector<vector<whole>> mtx(h,vector<whole>(w));
    for (vector<whole> &vv : mtx) {
        for (whole &x : vv) {
            cin >> x;
        }
    }
    whole i,j;
    cin >> i >> j;
    i -= 1; j -= 1;
    if (mtx[i][j] >= 0) {
        cout << 0;
        return 0;
    }

    auto cmph = [](water &a, water &b) -> bool {
        return a.flow >= b.flow;
    };

    priority_queue<water,std::vector<water>, decltype(cmph)> hh(cmph);
    hh.push(water{i,j,mtx[i][j]});
    vector<pair<whole,whole>> dir{
        {-1,-1},{-1,0},{-1,1},
        {0,-1},        {0,1},
        {1,-1}, {1,0}, {1,1}
    };
    vector<vector<bool>> searched(h,vector(w,false));
    searched[i][j] = true;
    whole s = 0;
    while(hh.size()) {
        water pop = hh.top();
        hh.pop();
        s += -pop.flow;
        for (pair<whole,whole> &p : dir) {
            whole ni = pop.first+p.first;
            whole nj = pop.second+p.second;
            
            if (ni < 0 || ni >= h
             || nj < 0 || nj >= w 
             || searched[ni][nj])
                continue;
            searched[ni][nj] = true;
            if (mtx[ni][nj] >= 0)
                continue;
            water newpos{
                ni, 
                nj,
                max(mtx[ni][nj], pop.flow)
            };
            
            hh.push(newpos);
        }

    }
    cout << s;
}