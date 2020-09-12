#include <bits/stdc++.h>
using namespace std;

int main() {
	int t; cin >> t;
	while(t--) {
		uint64_t n; cin >> n;
		vector<uint64_t> a(n);
		vector<uint64_t> b(n);
		uint64_t amin = 1000000001;
		uint64_t bmin = 1000000001;
		for (uint64_t &x : a)  { 
			cin >> x;
			if (x < amin) amin = x;
		}
		for (uint64_t &x : b)  {
			cin >> x;
			if (x < bmin) bmin = x;
		}
		uint64_t moves = 0;
		for (uint64_t i = 0; i < n; i++) {
			moves += max(a[i]-amin, b[i]-bmin);
		}
		cout << moves << "\n";

	}
}