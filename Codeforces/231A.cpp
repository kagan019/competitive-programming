#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    int ret = 0;
    while (n--) {
        int k = 0;
        int j;
        int t = 3;
        while (t--) {
            cin >> j;
            k += j;
        }
        if (k >=2 )
            ret += 1;
    }
    cout << ret;
}