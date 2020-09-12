#include <bits/stdc++.h>
using namespace std;

int main() {
	int cs = 1;
	for(char a[1000] ; cin.getline(a,1000);) {
		istringstream iss(a);
		int n;
		iss >> n;
		cout << "Case " << cs << ": " << (int)(ceil(log10(3.0f) + n*log10(3.0f/2.0f))) << "\n";
		cs++;
	}
}