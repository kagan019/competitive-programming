#include <bits/stdc++.h>
using namespace std;

int main () {
    int n; cin >> n;
    int s = 0;
    vector<int> coins;
    while(n--) {
        int k; cin >> k;
        s += k;
        coins.push_back(k);
    }
    sort(coins.begin(), coins.end(), [](const int &a, const int &b){return a>b;});

    int toget = s / 2;
    int sofar = 0;
    int i;
    for (i = 0; sofar <= toget; i++) {
        sofar += coins[i];
    }

    cout << i;
}