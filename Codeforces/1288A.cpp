#include <bits/stdc++.h>
using namespace std;

long distdig(long n) {
    long n_ = n;
    bool seen[10];
    for (long i = 0; i < 10; i++) {
        seen[i] = false;
    }
    long dig = (long)pow(10, (long)log10(n));
    while(dig) {
        long d = n_ / dig;
        if (seen[d]) {
            return dig;
        }
        seen[d] = true;
        n_ %= dig;
        dig /= 10;
    }
    return 0;
}

// increment least significant digit of the first encountered pair of duplicates from the left. All less-significant digits than that one are reset to 0.
long inclsdupdig(long n) {
    long dig = distdig(n);
    if (dig){
        n -= n % dig;
        n += dig;
        return n;
    }
    return n;
}

int main() {
    long l, r; cin >> l >> r;
    if (distdig(l) == 0) {
        cout << l;
        return 0;
    }
    long s = inclsdupdig(l);
    while(s != l) {
        l = s;
        s = inclsdupdig(l);
    }
    // s now equals the smallest number greater than l with distinct digits
    if (s > r)
        cout << -1;
    else
        cout << s;
}