#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, h;
    cin >> n >> h;
    int w = 0;
    while(n--) {
        int k; cin >> k;
        if (k > h)
            w += 2;
        else
            w += 1;
    }
    cout << w;
}