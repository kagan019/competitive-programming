#include <bits/stdc++.h>
using namespace std;

// increment least significant digit of the first encountered pair of duplicates from the left. All less-significant digits than that one are reset to 0.
int inclsdupdig(int n) {
    int n_ = n;
    bool seen[10];
    for (int i = 0; i < 10; i++) {
        seen[i] = false;
    }
    int dig = (int)pow(10, (int)log10(n));
    while(dig) {
        int d = n_ / dig;
        if (seen[d]) {
            n -= n % dig;
            n += dig;
            return n;
        }
        seen[d] = true;
        n_ %= dig;
        dig /= 10;
    }
    return n;
}

int main() {
    int y; cin >> y;
    y++;
    int s = inclsdupdig(y);
    while(s != y) {
        y = s;
        s = inclsdupdig(y);
    }
    cout << s;
}