#include <bits/stdc++.h>
using namespace std;

int main() {
    int m, n;
    cin >> m >> n;
    if (m % 2 == 0) {
        cout << m/2 * n;
        return 0;
    }
    if (n % 2 == 0) {
        cout << n/2 * m;
        return 0;
    }
    cout << (m-1)/2 * n + n/2;
}