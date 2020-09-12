#include <bits/stdc++.h>
#include <assert.h>
using namespace std;

int main() {
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		vector<int> a(n);
		for (int &x : a) cin >> x;
		int i = n-1;
		while(i > 0) {
			i--;
			if (a[i] < a[i+1])
				break;	
		}
		int deci = i;
		if (i == 0) {
			cout << 0 << endl;
			continue;
		}
		while (i > 0) {
			i--;
			if (a[i] > a[i+1])
				break;
		}
		if (a[i] > a[i+1]) {
			cout << i + 1 <<endl;
			continue;
		}
		else if (i == 0) {
			cout << 0 << endl;
		}
		else {
			assert(false);
		}

	}
}