#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    int r = 0;
    while (n--) {
        int p, q;
        cin >> p >> q;
        r += (int)(q-p >= 2);
    }
    cout << r;
}