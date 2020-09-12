#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;
    vector<int> a(n), b(n);
    for (int&v : a) cin >> v;
    for (int&v : b) cin >> v;

    vector<int> diff;
    for (long long i=0; i < n; i++) {
        diff.push_back(a[i]-b[i]);
    }
    sort(diff.begin(), diff.end());

    const vector<int>::iterator zeropos = lower_bound(diff.begin(), diff.end(), 0);
    long long zeros = 0;
    auto look = zeropos;
    while(look != diff.end() && *look == 0){
        zeros++;
        look++;
    }
    
    long long pos = diff.end() - look;
    long long poscombs = pos*(pos-1)/2 + zeros * pos;

    long long negcombs = 0;
    auto negit = zeropos-1;
    auto posit = look;
    while(bool cond = negit >= diff.begin() && posit < diff.end()){
        while (*negit + *posit <= 0){
            posit++;
        }
        negcombs += diff.end() - posit; 
        negit--;
    }

    cout << (poscombs+negcombs) << "\n";
}