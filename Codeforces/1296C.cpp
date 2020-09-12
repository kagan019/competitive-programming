#include <bits/stdc++.h>
using namespace std;

struct pos {
    long x=0;
    long y=0;
};
struct index_range {
    long s; long e;
};


inline bool operator<(const pos& lhs, const pos& rhs) {
    return (lhs.x == rhs.x
        ? lhs.y < rhs.y 
        : lhs.x < rhs.x);
}
inline bool operator==(const pos& lhs, const pos& rhs) {
    return (lhs.x == rhs.x
        && lhs.y == rhs.y);
}



long dx(char c) {
    switch(c) {
        case 'L': return -1;
        case 'R': return 1;
    }
    return 0;
}
long dy(char c) {
    switch(c) {
        case 'D': return -1;
        case 'U': return 1;
    }
    return 0;
}

int main() {
    long t; cin >> t;
    while (t--) {
        long n; cin >> n;

        map<pos, long> p{make_pair(pos{0, 0}, 1)};
        vector<index_range> r;
        
        pos cur;
        long n_ = n;
        while(n_--) {
            char c; cin >> c;
            cur.x += dx(c);
            cur.y += dy(c);

            if (p.count(cur)) {
                r.push_back(index_range{p[cur], n-n_+1});
                p[cur] = n-n_+1;
            } else {
                p.emplace(pos{cur.x, cur.y}, n-n_+1);
            }
            
        }
        if (!r.size()) {
            cout << -1 << "\n";
            continue;
        }
        long min = r[0].e-r[0].s;
        index_range mr = r[0];
        for (index_range &a : r) {
            if (min > a.e-a.s) {
                min = a.e-a.s;
                mr = a;
            }
        }
        cout << mr.s << " " << mr.e-1 << "\n";
    }

        
}