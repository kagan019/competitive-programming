#include <bits/stdc++.h>
using namespace std;

int main() {
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        vector<int> a(n);
        for (int &x : a) cin >> x;
        int c = 0;
        for (int i = 1 ; i < a.size(); i++) {
            int u = max(a[i],a[i-1]);
            int v = min(a[i],a[i-1]);
            while(2*v < u) {
                v *= 2;
                c++;
            }
            

        }
        cout << c << endl;
    }
}