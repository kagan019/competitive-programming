#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    int mincap = 0;
    int intram = 0;
    while (n--) {
        int p, m;
        cin >> p >> m;
        intram = intram - p + m;
        mincap = max(mincap, intram);
    }
    cout << mincap;
}