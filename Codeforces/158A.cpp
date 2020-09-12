#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    int nr = 0;
    int kthplace = -1;
    int n_ = n;
    int j; 
    cin >> j;
    while(n_-- && (kthplace < 0 || kthplace == j)) {
        if (j > 0)   
            nr++;
        if (n_ == n - k)
            kthplace = j;
        cin >> j;

    } 
    cout << nr;
}