#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    int last = -1;
    int g = 0;
    while(n--) {
        int m; cin >> m;
        if (m != last) {
            last = m;
            g++;
        }
    }
    cout << g;
}