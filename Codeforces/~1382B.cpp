#include <bits/stdc++.h>
using namespace std;

int main() {
	int t; cin >> t;
	while(t--) {
		int n; cin >> n;
		deque<int> a;
		for (int i = 0; i < n; i++) {
			int x; cin >> x;
			a.push_back(x);
		}
		bool first = true;

		while(a.size()) {
			if (a.front() == 1 
				|| a.size() % 2)
				a.pop_front();
			else
				a[0] = 1;
			first = !first;
		}
		if (first) {
			cout << "Second\n";
		}else {
			cout << "First\n";
		}
	}
}