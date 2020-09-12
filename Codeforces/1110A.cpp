#include <bits/stdc++.h>
using namespace std;

int main() {
    int b, k;
    cin >> b >> k;
    vector<int> digs(k);
    for (int &x : digs) cin >> x;
    
    if (b % 2) {
       if (accumulate(digs.begin(), digs.end(), 0) % 2 == 0) {
            cout << "even";
            return 0;
       }
       else {
           cout << "odd";
           return 0;
       }
        
    }
    else {
        if (digs[digs.size()-1] % 2) {
            cout << "odd";
            return 0;
        }
        else {
            cout << "even";
            return 0;
        }
    }
    
}