#include <bits/stdc++.h>

using namespace std;
int main() {
    cout << setprecision(9);
    long long k,w,l;
    cin >> k >> w >> l;
    // 2l/w /(2^(k+2)-2^k-2-1) = tanbeta
    long long gg = (1<<(k+1))-1-2+(1<<k);
    long long num = 2*l;
    long long denom = w*gg;
    double ans = atan2((double)num,(double)denom);

    cout << (ans*(180.0/M_PI));
}