#include <bits/stdc++.h>
using namespace std;

int main() {
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		string s; cin >> s;
		vector<int> mode(n,1);
		vector<int> his[2];
		int k = 0;
		for (int i = 0; i < n; i++) {
			int x = s[i] - '0';

			if (!his[x].size()) {
				mode[i] = ++k;
			} else {
				mode[i] = his[x].back();
				his[x].pop_back();
			}

			his[!x].push_back(mode[i]);
		}
		cout << k << "\n";
		for(int x : mode)
			cout << x << " ";
		cout << "\n";
	} 
}

// 1100111
// 1221123