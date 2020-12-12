#include<bits/stdc++.h>
#include <math.h>
using namespace std;
 
typedef long long ll;
typedef long double ld;
# define forn for(ll i = 0; i < n; i++) 
# define pb push_back
# define sethas(set,x) (set.find(x) != set.end())
# define fill_matrix(matrix,size,value) (fill(*matrix, matrix + size, value)); 
# define triangle(n) (n*(n+1)/2)
# define PI 3.14159265
# define ceildiv(x,y) ((x + y - 1) / y)
//
//string(n,c)



struct post {
	int x;
	int y;
	int color = -1;
};
vector<post> posts;

struct edge {
	int p1, p2;
};

#define f(e) posts[(e).p1]
#define s(e) posts[(e).p2]

float sqdist(edge &a) {
	return pow((float)(f(a).x-s(a).x),2.0) + pow((float)(f(a).y-s(a).y),2.0);
}

bool ab4b(edge &a, edge &b) {
	return sqdist(a) < sqdist(b);
}

int find (vector<int> &disjoint,int v) {
	if (disjoint[v] == -1) return v;
	disjoint[v] = find(disjoint, disjoint[v]);
	return disjoint[v];
}

void join(vector<int> &disjoint, int src, int dest) {
	int x = find(disjoint, src);
	int y = find(disjoint, dest);
	if (x == y) {
		return;
	}
	//union disjoint[src] to disjoint[dest];
	disjoint[x] = y;
}

 

void solve () {
	int S, P;
	cin >> S >> P;
	posts = vector<post>(P);


	for (auto &x : posts)  {
		int a, b;
		cin >> a >> b;
		x = post{.x=a, .y=b};
	}


	vector<edge> edges;
	for (int i = 0; i < posts.size()-1; i++) {
		for (int j = i+1; j < posts.size(); j++) {
			edge e = {.p1=i, .p2=j};
			edges.push_back(e);
		}		
	}
	sort(edges.begin(), edges.end(), ab4b);
	
	
	// filter edges that connect nondisjoint sets
	int colors = 0;
	vector<edge *> selected;
	vector<int> disjoint(P,-1);
	for(edge &e : edges) { // check shorter edges first
		// if e connects two new points or is the first (shortest) that connects two disjoint clusters of points,
		// add that edge to selected
		
		if (find(disjoint, e.p1) != find(disjoint, e.p2)) {
			join(disjoint, e.p1, e.p2);
			selected.push_back(&e);
		}
		
	}

 	cout << sqrt(sqdist(*(selected[selected.size() - S]))) << endl;	
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(0);
    cout << fixed << setprecision(2);
	ll n;
    cin >> n;
    for (ll i = 0; i < n; ++i) {
        solve();
    }
}