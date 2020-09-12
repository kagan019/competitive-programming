#include <bits/stdc++.h>
using namespace std;

bool islucky(int n) {
    int n_ = n;
    while (n_) {
        int d = n_ % 10;
        if (d != 4 && d != 7) {
            return false;
        }
        n_ /= 10;
    }
    return n != 0;
}

bool isnearlylucky(long long n) {
    int luckydigits = 0;
    long long n_ = n;
    while(n_) {
        int d = n_ % 10;
        if (d == 4 || d == 7)
            luckydigits++;
        n_ /= 10;
    }
    return islucky(luckydigits);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long num; cin >> num;
    cout << (isnearlylucky(num) ? "YES" : "NO");
}