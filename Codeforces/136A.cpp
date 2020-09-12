#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    int n_ = n;
    vector<int> p(n);
    while (n_--) {
        int k; cin >> k;
        p[k - 1] = n - n_;
    }
    for (int &h : p)
        cout << h << " ";
}