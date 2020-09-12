#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    int t; cin >> t;
    while(t--){
        int n; int x; int y;
        cin >> n >> x >> y;
        ll m = 1000000001;
        int mi = 100;
        for (int i = 1; i <= y-x; i++) {
            if ((y-x) % i) continue;
            ll k = y - (n-1)*(y-x)/i;
            if (k > x) break;
            ll max_of_arr = y;
            if (k < 1) max_of_arr += (1-k+(y-x)/i - 1)/((y-x)/i)*(y-x)/i;
            if (max_of_arr < m) {
                m = max_of_arr;
                mi = i;
            } 
            
        }
        for (int j = 0; j < n; j++) {
            cout << m-j*(y-x)/mi << " ";
        }
        cout << endl;
        
            
    }
}
