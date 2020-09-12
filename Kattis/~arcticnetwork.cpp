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

void join(vector<vector<int>> &disjoint, int src, int dest) {
	//union disjoint[src] to disjoint[dest];
	for (int &i : disjoint[src]) {
		posts[i].color = dest;
	}
	disjoint[dest].insert(disjoint[dest].end(),disjoint[src].begin(),disjoint[src].end());
	disjoint[src].clear();
	disjoint[src].resize(0);
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
	int joint = 0; // posts of color x must be in set at index x. color -1 means not in here
	for(edge &e : edges) { // check shorter edges first
		// if e connects two new points or is the first (shortest) that connects two disjoint clusters of points,
		// add that edge to selected
		// keep track of disjoint to know how many are in the lowest color group


		if (f(e).color == -1 && s(e).color == -1) {
			selected.push_back(&e);
			colors++;
			f(e).color = colors;
			s(e).color = colors;
			disjoint.resize(colors+1);
			disjoint[colors] = vector<int>({e.p1, e.p2});
		}
		else if (f(e).color != s(e).color) {
			selected.push_back(&e);
			int lc = f(e).color > s(e).color ? e.p1 : e.p2; 
			int sc = f(e).color < s(e).color ? e.p1 : e.p2; 
			if (posts[sc].color == -1) {
				//add posts[sc] to posts[lc]'s color set
				posts[sc].color = posts[lc].color;
				disjoint[posts[sc].color].push_back(sc);
			}
			else {
				//add posts[lc], and every other post with 
				//the same color as posts[lc] 
				// to posts[sc]'s color set
				join(disjoint, lc, sc);
			}
		}
	}

 	cout << sqrt(sqdist(*(selected[selected.size() - S]))) << endl;	
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(0);
    cout << fixed << setprecision(2);
    ll n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        solve();
    }
}