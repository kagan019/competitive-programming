#include <bits/stdc++.h>
using namespace std;

int main() {
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		string a;
		string b;
		cin >> a; cin >> b;
		int k = 0;
		for (int i = 0; i < a.size(); i++) {
			if (a[i] != b[i]) {
				if (i == 0) {
					k++;
				} else {
					k += 3;
				}
			}
		}
		cout << k << " ";
		for (int i = 0; i < a.size(); i++) {
			if (a[i] != b[i]) {
				if (i == 0) {
					cout << 1 << " ";
				} else {
					cout << i+1 << " " << 1 << " " << i+1 << " ";
					a[i] = b[i];
				}
			}
		}
		cout << "\n";
	
	}
}