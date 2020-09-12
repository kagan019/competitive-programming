#include <bits/stdc++.h>
using namespace std;

int main() {
	int t; cin >> t;
	while(t--) {
		int n; cin >> n;
		vector<int> a(n);
		for (int &x : a) {
			cin >> x;
		}
		string last(100,'a');
		char newchar = 'a';
		cout << last << "\n";
		string next;
		for (int i = 0; i < n; i++) {
			next = last.substr(0, a[i]);
			newchar = (newchar-'a'+1)%15+'a';
			if(last[a[i]] == newchar)
				newchar = 'z';
			next.append(string(100-a[i]-1, newchar));
			cout << next << "\n";
			last = next;
		}
	}
}