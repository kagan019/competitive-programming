#include <bits/stdc++.h>
using namespace std;

int gcf(int a, int b) {
    if (a < b) {
        return gcf(b, a);
    }
    if (b <= 0) {
        return -1;
    }
    if (a % b == 0)
        return b;
    return gcf(b, a % b);
}

int lcm(int a, int b) {
    return a * b / gcf(a, b);
}

int main() {
    int k, l, m, n, d;
    cin >> k >> l >> m >> n >> d;
    int dragons = d / k + d / l - d / lcm(k, l);
    dragons += d / m - d / lcm(m, k) - d / lcm(m, l) + d / lcm(m, lcm(l, k));
    dragons += d / n - d / lcm(n, k) - d / lcm(n, l) + d / lcm(n, lcm(l, k)) - d / lcm(n, m) + d / lcm(n, lcm(m, k)) + d / lcm(n, lcm(m, l)) - d / lcm(n, lcm(m, lcm(k, l)));
    cout << dragons;
}