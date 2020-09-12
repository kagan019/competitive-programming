#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    int n_ = n;
    int minpos;
    int maxpos;
    int min = 101;
    int max = -1;
    while(n_--) {
        int k; cin >> k;
        if (k > max) {
            max = k;
            maxpos = n - n_ - 1;
        }
        if (k <= min) {
            min = k;
            minpos = n - n_ - 1;
        }
    }
    int toleft = maxpos;
    int toright = n - minpos - 1;
    int swaps = toleft + toright;
    if (toleft + toright >= n) {
        swaps -= 1;
    }
    cout << swaps;


}