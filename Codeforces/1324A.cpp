#include <bits/stdc++.h>
using namespace std;

int main() {
    int t; cin >> t;
    while(t--) {  
        int n; cin >> n;
        bool possible = true;
        int parity = -1;
        while (n--) {
            int ai; cin >> ai;
            if (parity < 0){
                parity = ai % 2;
            }
            else {
                if (ai % 2 != parity) {
                    
                    possible = false;
                }
            }
        }
        if (possible)
            cout << "YES\n";
        else
            cout << "NO\n";
    }

}