#include <bits/stdc++.h>
using namespace std;

int main() {
	for(char a[1000] ; cin.getline(a,1000);) {
		istringstream iss(a);
		int n, m
		iss >> n >> m;
		vector<int> s(m);
		for (int &x : s) cin >> x;

		for (int &x : s) cout << x;
		cout << endl;

	}
}