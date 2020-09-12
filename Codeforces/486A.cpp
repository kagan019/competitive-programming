#include <bits/stdc++.h>
using namespace std;

int main() {
    long long n; cin >> n;
    long long f = n/2;
    if (n % 2)
        f -= n;
    cout << f;
}