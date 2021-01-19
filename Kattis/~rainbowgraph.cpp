#include <bits/stdc++.h>
using namespace std;

struct post {
	int x;
	int y;
	
};
vector<post> posts;

struct edge {
	int p1, p2;
    char color;
    int weight;
};

unordered_set<char> bg{'B','G'};
unordered_set<char> rg{'R','G'};
bool roy(edge &ee) {
    return bg.find(ee.color) != bg.end();
}
bool biv(edge &ee) {
    return rg.find(ee.color) != rg.end();
}

vector<edge> e;
vector<int> rdisjoint;
vector<int> bdisjoint;
unordered_set<int> rs;
unordered_set<int> bs;

int find (vector<int> &disjoint,int v) {
	if (disjoint[v] == -1) return v;
	disjoint[v] = find(disjoint, disjoint[v]);
	return disjoint[v];
}

void rjoin(edge &ee) {
    if (!roy(ee)) return;
	int x = find(rdisjoint, ee.p1);
	int y = find(rdisjoint, ee.p2);
	if (x == y) {
		return;
	}
    rs.erase(rdisjoint[x]);
	rdisjoint[x] = y;
}
void bjoin(edge &ee) {
    if (!biv(ee)) return;
	int x = find(rdisjoint, ee.p1);
	int y = find(rdisjoint, ee.p2);
	if (x == y) {
		return;
	}
    bs.erase(bdisjoint[x]);
	bdisjoint[x] = y;
}
bool rcomplete() {
    return rs.size() == 1;
}
bool bcomplete() {
    return bs.size() == 1;
}



bool edgecmp(edge &a, edge &b) {
    return a.weight > b.weight;
}

int minsumweight(int k) {
    vector<edge> e2(e.begin(), e.end());
    sort(e2.begin(), e2.end(), edgecmp);
    int j = 0;
    vector<edge> rtbl;
    vector<edge> btbl;
    while(e2.size() && !rcomplete() && !bcomplete()) {
        edge ee = e2.back();
        e2.pop_back();
        if (roy(ee) && biv(ee)) {
            rjoin(ee);
            bjoin(ee);
        }
        else {
            if (roy(ee)) {
                rtbl.push_back(ee);
            }
            if (biv(ee)) {
                btbl.push_back(ee);
            }
        }
        j++;
    }
}

int main() {
    int n,m;
    cin >> n >> m;
    rdisjoint = vector<int>(n,-1);
    bdisjoint = vector<int>(n,-1);
    for (int i = 0; i < n; i++) {
        rs.insert(i);
        bs.insert(i);
    }
    for (int i = 0; i < m; i++) {
        int a, b, w; char c;
        cin >> a >> b >> w >> c;
        e.push_back(edge{a,b,c,w});
    }       
    for (int k = 1; k <= m; k++) {
        bool connected = false;
        int m = minsumweight(k);
        if (connected) {
            cout << m << endl;
        } else {
            cout << -1 << endl;
        }
    }
    
    
}