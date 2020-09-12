#include <bits/stdc++.h>
using namespace std;

int main() {
	int t; cin >> t;
	while(t--) {
		int x, y, z;
		cin >> x >> y >> z;
		int a, b, c;
		if (x == y) {
			if (z > x) {
				cout << "NO" <<endl;
				continue;
			}
			a = x;
			b = z;
			c = b;

		}
		else if (x == z) {
			if (y > x) {
				cout << "NO" <<endl;
				continue;
			}
			b = x;
			a = y;
			c = a;
		}
		else if (y == z) {
			if (x > z) {
				cout << "NO" <<endl;
				continue;
			}
			c = y;
			a = x;
			b = a;

		} else {
			cout << "NO" << endl;
			continue;
		}

		if (a < 1 || b < 1 || c < 1) {
			cout << "NO" << endl;
			continue;
		}
		cout << "YES" << endl;
		cout << a << " " << b << " " << c << endl;
	}
}