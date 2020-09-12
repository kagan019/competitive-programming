#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    int n_ = n;
    int cnt[] {0,0,0,0};
    while (n_--) {
        int k; cin >> k;
        cnt[k-1]++;
    }



    int match3and1 = min(cnt[0], cnt[2]);
    cnt[3] += match3and1;
    cnt[0] -= match3and1;
    cnt[2] -= match3and1;

    int match112 = min(cnt[0]/2, cnt[1]);
    cnt[3] += match112;
    cnt[0] -= 2*match112;
    cnt[1] -= match112;

    cnt[3] += cnt[0] / 4;
    cnt[0] = cnt[0] % 4;

    cnt[3] += cnt[1]/2;
    cnt[1] = cnt[1]%2;

    int cars = cnt[3] + max(min(1, cnt[0]), cnt[1]+cnt[2]);
    cout << cars;
}