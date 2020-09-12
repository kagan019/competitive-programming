#include <bits/stdc++.h>
using namespace std;

int main () {
	int t; cin >> t;
	while(t--) {
		int n, k, l; cin >> n >> k >> l;
		vector<int> d(n);
		bool fail = false;
		for (int i = 0; i < d.size(); i++) {
			int g; cin >> g;
			d[i] = g - l + k; // have to wait until phase is between x and 2k-x to pass through
			if (d[i] > k) {
				fail = true;
			}
		}			
		if (n == 0) {
			cout << "Yes" << "\n";
			continue;
		}
		if (fail) {
			cout << "No" << "\n";
			continue;
		}

		int ph = d[0];
		// as ph increases to k, the water level decreases. as it increases to 2k-1, the water level increases
		for (int i = 0; i < d.size()-1; i++) {
			if (d[i] <= 0) {
				ph = d[i+1];		
				continue;
			}	
			
			if (ph < d[i+1]) {
				ph = d[i+1]-1;
			}
			ph++; ph %= 2*k;
			if (ph < d[i+1] || ph > 2*k - d[i+1]) {
				fail = true;
				break;
			}
			
		}
		if (!fail)
			cout << "Yes" << "\n";
		else 
			cout << "No" << "\n";
	}


}