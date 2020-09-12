#include <bits/stdc++.h>
using namespace std;

int main() {
    int m, n; cin >> m >> n;
    int p = min(m,n) * min(m,n);
    if (p % 2) {
        cout << "Akshat";
        return 0;
    }
    cout << "Malvika";
}