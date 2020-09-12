#include <bits/stdc++.h>
using namespace std;

int main() {
	int t; cin >> t;
	while(t--) {
		int n; cin >> n;
		vector<int> w(51,0);
		for (int i = 0; i < n; i++) { 
			int x; cin >> x;
			w[x]++;

		}
		vector<int> sums(101, 0);
		for (int i = 1; i <= 50; i++) {
			for (int j = i; j <= 50; j++) {
				if (j == i) {
					sums[j+i] += w[j]/2; 
				} else {
					sums[j+i] += min(w[j],w[i]);
				}
			}
		}
		int m = 0;
		for (int x : sums) {
			if (x > m)
				m = x;
		}
		cout << m << "\n";

	}
}