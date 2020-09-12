#include <bits/stdc++.h>
using namespace std;

int main() {
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        int odd = 0;
        int even = 0;
        while(n--) {
            int a; cin >> a;
            if (a % 2)
                odd++;
            else
                even++;
        }
        if ((odd + even) % 2) {
            if (odd > 0)
                cout << "YES\n";
            else
                cout << "NO\n";
        }
        else {
            if (even > 0 && odd > 0) {
                cout << "YES\n";
            }
            else
                cout << "NO\n";
        }

    }
}