#include <bits/stdc++.h>
using namespace std;

int main() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        unordered_map<long long,long long> debt;
        debt[0] = 1;
        int d = 0;
        long long sas = 0;
        for (int i = 0; i < n; i++) {
            char c; cin >> c;
            const int x = c - '0';
            d -= 1;
            d += x;
            if (debt.find(d) == debt.end())
                debt[d] = 0;
            sas += debt[d];
            debt[d]++;    
        }
        cout << sas << endl;
    }
}
