#include <bits/stdc++.h>
using namespace std;


typedef long long whole;

struct water{
    whole first;
    whole second;
    whole flow;
};



namespace std
{
    template<> struct hash<water>
    {
        std::size_t operator()(water const& s) const noexcept
        {
            std::size_t h1 = std::hash<long long>{}(s.first);
            std::size_t h2 = std::hash<long long>{}(s.second);
            return h1 ^ (h2 << 1); // or use boost::hash_combine
        }
    };
}


int main() {
    whole w,h;
    cin >> w >> h;
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

    auto cmph = [&mtx](water &a, water &b) -> bool {
        return mtx[a.first][a.second] > mtx[b.first][b.second];
    };

    vector<water> hh;
    hh.push_back(water{i,j,mtx[i][j]});
    vector<water> dir{
        {-1,-1},{-1,0},{-1,1},
        {0,-1},        {-1,1},
        {1,-1}, {1,0}, {1,1}
    };
    vector<vector<bool>> searched(h,vector(w,false));
    whole s = 0;
    while(hh.size()) {
        pop_heap(hh.begin(),hh.end(),cmph);
        auto pop = hh.back();
        hh.pop_back();
        s += -pop.flow;
        for (water &p : dir) {
            whole ni = pop.first+p.first;
            whole nj = pop.second+p.second;
            if (ni < 0 || ni >= h
             || nj < 0 || nj >= w
             || mtx[ni][nj] >= 0)
                continue;
            water newpos{
                pop.first+p.first, 
                pop.second+p.second,
                max(mtx[ni][nj], pop.flow)
            };
            if (searched[i][j] == false) {
                searched[i][j] = true;
                hh.push_back(newpos);
                push_heap(hh.begin(),hh.end(),cmph);
            }
        }

    }
    cout << s;
}