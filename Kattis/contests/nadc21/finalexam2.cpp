#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    string k;
    k.resize(n);
    for (auto &c : k) {
        cin >> c;
    }
    string k2(k.begin(),k.end());
    rotate(k2.begin(),k2.begin()+1,k2.end());
    int cnt = 0;
    for (int i = 0; i < k2.size()-1; i++) {
        cnt += (int)(k2[i] == k[i]);
    } 
    cout << cnt;
}