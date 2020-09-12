#include <bits/stdc++.h>
using namespace std;

int main() {
	long long t; cin >> t;
	while (t--) {
		long long n,r;
		cin >> n >> r;

		long long z = min(r, n-1);
		cout << z*(z+1)/2 + (n-1 < r ? 1 : 0) << endl;
	}
}

/*
		long long s = 0;
		for (long long k = 1; k <= r; k++) {
			if (n > k) {
				s += k;
			}
			else if (n == k) {
				s += 1;
				break;
			}
		}
*/