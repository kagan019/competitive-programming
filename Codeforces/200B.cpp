#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    int n_ = n;
    int sum = 0;
    while (n_--) {
        int k; cin >> k;
        sum += k;
    }
    cout << setprecision(8) << (double)sum / (double)(n);
}