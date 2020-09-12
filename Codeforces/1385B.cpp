#include <bits/stdc++.h>
using namespace std;

int main() {
	int t; cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector<int> c(n+1, -1);
		int used = 0;
		for (int i = 0; i < 2*n; i++) {
			int x; cin >> x;
			if (c[x] == -1) {
				c[x] = used;
				used++;
			}
		}
		vector<int> p(n, -1);
		for (int i = 1; i < c.size(); i++) {
			p[c[i]] = i;
		}
		for (int &x : p) {
			cout << x << " ";
		}
		cout << endl;
	}
}