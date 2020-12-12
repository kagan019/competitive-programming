#include <bits/stdc++.h>
using namespace std;

struct point {
    float x, y;
};

struct edge {
    point a, b;
    float distsq;
};

float dsq(edge &m) {
    const float dx = (m.a.x-m.b.x);
    const float dy = (m.a.y-m.b.y);
    return dx*dx + dy*dy;
}

int main() {
    cout << setprecision(3) << fixed;
    int n; cin >> n;
    while(n--) {
        int m; cin >> m;
        vector<point> vv;
        for(int i = 0; i < m; i++) {
            float a, b;
            vv.push_back({a,b});
        }
    }
}