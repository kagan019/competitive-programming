#include <bits/stdc++.h>
using namespace std;

struct circle {
    int x, y, r;
};

bool intersect(circle &a, circle &b) {
    auto dx = a.x - b.x;
    auto dy = a.y - b.y;
    auto totr = a.r + b.r;
    return dx*dx + dy*dy < totr * totr;
}

class disjoint_union {
public:
    vector<int> parent;
    vector<int> rank;

    disjoint_union(int n) {
        parent = vector<int>(n);
        rank = vector<int>(n, 0);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    int find(int a) {
        return (a == parent[a])
            ? a 
            : (parent[a] = find(parent[a])); 
    }
    void merge(int a, int b) {
        auto fa = find(a);
        auto fb = find(b);
        auto mr = std::min(rank[fa],rank[fb]);
        if (mr == rank[fa]) {
            parent[fa] = fb;
            if (mr == rank[fb])        
                rank[fb]++;
        } else 
            parent[fb] = fa;
    }
    
};

int main() {
    int n; cin >> n;
    vector<circle> opp(n);
    for (auto &p : opp) {
        int x,y,r; cin >> x >> y >> r;
        p = {x,y,r};
    }
    disjoint_union dj = disjoint_union(n+2);
    for (int i = 0; i < opp.size(); i++) {
        if (1000 - opp[i].y < opp[i].r) {
            //touching the north edge
            dj.merge(0,i+2);
        }
        if (opp[i].y < opp[i].r) {
            //touching the south edge
            dj.merge(1,i+2);
        }
    }

    for (int i = 0; i < opp.size()-1; i++) {
        for (int j = i+1; j < opp.size(); j++) {
            if (intersect(opp[i],opp[j])) {
                dj.merge(i+2,j+2);
            }
        }
    }

    cout << fixed << setprecision(2);
    if (dj.find(0) == dj.find(1)) {
        cout << "IMPOSSIBLE" << endl;
        return 0;
    }

    float northentr = 1000;
    float northext = 1000;
    for (int i = 0; i < opp.size(); i++) {
        if (opp[i].x < opp[i].r) {
            //touching the west
            if (dj.find(0) == dj.find(i+2)) {
                //find northest point touching the west below circle
                float dx = opp[i].x;
                float intsct = -sqrt(opp[i].r*opp[i].r - dx*dx) + opp[i].y;
                assert(intsct > 0); // otherwise find(0) == find(1)
                northentr = std::min(northentr, intsct);
            }
        }
         if (1000 - opp[i].x < opp[i].r) {
            //touching the east
            if (dj.find(0) == dj.find(i+2)) {
                //find northest point touching the east below circle
                float dx = 1000-opp[i].x;
                float intsct = -sqrt(opp[i].r*opp[i].r - dx*dx) + opp[i].y;
                assert(intsct > 0); // otherwise find(0) == find(1)
                northext = std::min(northext, intsct);
            }
        }
    }
    cout << 0.00 << " " << (float)northentr << " " << 1000.00 << " " << (float)northext << endl;
}