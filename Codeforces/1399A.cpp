#include <bits/stdc++.h>
using namespace std;

int main() {
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		vector<int> a(n);
		for (int &x : a) {
			cin >> x;
		}
		sort(a.begin(), a.end());
		int gaps = 0;
		for (int i = 1; i < n; i++) {
			if (a[i] - a[i-1] > 1)
				gaps++;
			if (gaps > 0) break;
		}
		if (gaps > 0)
			cout << "NO\n";
		else
			cout << "YES\n";
	}
}