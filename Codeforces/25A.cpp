#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    int n_ = n;
    int swaps = 0;
    int last = -1;
    int lastswapi;
    while (n_-- && swaps < 2) {
        int i = n - n_;
        int k; cin >> k;
        if (k % 2 != last) {
            if (last >= 0) {
                swaps++;
            }
            lastswapi = i;
        }
        last = k % 2;
    }
    if (swaps == 1 && lastswapi == n) {
        std::cout << n;
        return 0;
    }
    std::cout << (lastswapi - 1);
}