#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b) {
	if (b > a)
		return gcd(b,a);
	if (b == 0) {
		return a;
	}
	return gcd(b, a%b);
}

int lcm(int a, int b) {
	return a*b/gcd(a,b);
}

int main() {
	int p, q, s;
	cin >> p >> q >> s;
	cout << (lcm(p,q) <= s ? "yes" : "no");
}