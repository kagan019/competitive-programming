#include<bits/stdc++.h>
using namespace std;

int main() {
	int t; cin >> t;
	while (t--) {
		long long a,b,n,m; 
		cin >> a >> b >> n >> m;
		bool ok = true;
		if (n+m > a+b)
			ok=false;
		if(a>b) {
			if (n - (a-b) )
				ok=false;
		} else {
			if (n < b-a)
				ok=false;
		}

		if(ok){
			cout << "Yes\n";
		}
		else {
			cout << "No\n"
		}
	}
}




/*

int a,b,n,m; cin >> a >> b >> n >> m;
		if (a+b < n+m) {
			cout << "No" << endl;
			return 0;
		}
		int lc = a
		int sc = b;
		if (a < b) {
			lc = b;
			sc = a;
		}


		
		if (n <= lc-sc) {
			else if (m < sc) {
				cout << "Yes" << endl;
				return 0;
			}
			else {
				cout << "No";
				return 0;
			}
		}
		else {
			if (n - (lc-sc) + m < sc) {
				cout << "Yes" << endl;
				return 0;
			}
			else {
				int p = n-(gc-sc);
				if () {

				}
			}
		}

if (a + b > n + m) {
			cout << "No";
			return 0;
		}
		if (lc - sc == 0) {
			cout << "Yes" << endl;
			return 0;
		}
		if (n <= lc-sc) {
			if (m <= sc) {
				cout << "Yes" << endl;
				return 0;
			}
			else {
				cout << "No" << endl;
				return 0;
			}
		}
		else {
			if (lc > n - (lc-sc) + m) {
				cout << "Yes" << endl;
				return 0;
			}
			else if (m - (sc - (n - (lc-sc))) < lc) {
				cout << "Yes" << endl;
			}
			else {
				cout << "No" << endl;
			}
		}
*/