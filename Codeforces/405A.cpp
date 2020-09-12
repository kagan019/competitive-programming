#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    int colcnt[100];
    int j = 100;
    while (j--) {
        colcnt[j] = 0;
    }
    while(n--) {
        int k; cin >> k;
        colcnt[k-1]++;
    }

    for(int i = 0; i < 100; i++) {
        for(int i_ = colcnt[i]; i_; i_--) {
            cout << (i + 1) << " ";
        }
    }
}