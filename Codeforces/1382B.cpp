#include <bits/stdc++.h>
using namespace std;

int main() {
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		vector<int> piles(n);
		for (int &x : piles) cin >> x;
		vector<int> winner(n+1);
		winner[n] = 0;
		for(int i = n-1; i >= 0; i--) {
			if (winner[i+1] == 0)
				winner[i] = 1;
			else {
				if (piles[i] == 1)
					winner[i] = 0;
				else
					winner[i] = 1;
			}
		}
		if (winner[0])
			cout << "First\n";
		else
			cout << "Second\n";
	}
}