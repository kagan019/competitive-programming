#include <bits/stdc++.h>
using namespace std;

int main() {
    cout << setprecision(15);
    int n; cin >> n;
    double e = 1;
    double cur = 1;
    double denom = 1;
    for (int i = 1; i <= n; i++) {
        denom /= cur;
        e += denom;
        cur += 1.;

    }
    cout << e;
}