#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    while(k) {
        if (n % 10 == 0) {
            n /= 10;
            k--;
        }
        else {
            int g = min(k, n % 10);
            n -= g;
            k -= g;
        }

    }
    cout << n;
}