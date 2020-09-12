#include <bits/stdc++.h>
using namespace std;

vector<int> luckynumsleqhalf(int n) {
    vector<int> ret;
    int h = n/2;
    int digits = (int)log10(h) + 1;
    for(int i = 2; i < (2 << digits); i++) {
        int c = i;
        int ln = 0;
        int p = 1;
        while (c > 1) {
            ln += p * ((c % 2) ? 7 : 4);
            c >>= 1;
            p *= 10;
        }
        
        if (ln <= h)
            ret.push_back(ln);
        else break;
    }
    return ret;
}

bool islucky(int n) {
    
    int n_ = n;
    while (n_ != 0) {
        int d = n_ % 10;
        if (d != 4 && d != 7) {
            return false;
        }
        n_ /= 10;
    }
    return n != 0;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int num; cin >> num;
    vector<int> possible_divisors = luckynumsleqhalf(num);
    if (islucky(num))
        possible_divisors.push_back(num);
    for (auto &v : possible_divisors) {
        if (num % v == 0) {
            cout << "YES";
            return 0;
        }
    }
    cout << "NO";
}