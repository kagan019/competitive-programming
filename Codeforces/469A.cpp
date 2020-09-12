#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    set<int> s;

    int p; cin >> p;
    while (p--) {
        int k; cin >> k;
        s.insert(k);
    }
    int q; cin >> q;
    while (q--) {
        int k; cin >> k;
        s.insert(k);
    }
    cout << (s.size() == n ? "I become the guy." : "Oh, my keyboard!");
}