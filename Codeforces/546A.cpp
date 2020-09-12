#include <bits/stdc++.h>
using namespace std;

int main() {
    int k, n, w; cin >> k >> n >> w;
    int needs = (int)(k * (w + 1) * w/2.0);
    cout << max(needs - n, 0);
}