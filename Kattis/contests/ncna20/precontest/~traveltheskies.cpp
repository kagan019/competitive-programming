#include <bits/stdc++.h>
using namespace std;

struct Edge {
    int u; int v;
    int cap;
};

int main() {
    int k; int n; int m;
    vector<Edge> edgeset;
    for (int i = 0; i < m; i++) {
        int nu; int nv; int ncap;
        cin >> nu >> nv >> ncap;
        edgeset.push_back({nu,nv,ncap});
    }
    
}