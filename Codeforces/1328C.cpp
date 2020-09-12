#include <bits/stdc++.h>
using namespace std;

int main(){
    int t; cin >> t;
    while (t--){
        int n; cin >> n;
        bool still_equal = true;
        vector<int> z(n);
        for (int &k : z) {
            char c; cin >> c;
            k = c - '0';
        }
        vector<int>a,b;
        a.push_back(1); b.push_back(1);
        for (int i = 1; i < n; i++){
            if (z[i] == 1){
                if (still_equal){
                    a.push_back(1);
                    b.push_back(0);
                    still_equal = false;
                }
                else{
                    b.push_back(1);
                    a.push_back(0);
                }
            }
            else {
                if (still_equal) {
                    int push = (z[i]) ? 1 : 0;
                    a.push_back(push);
                    b.push_back(push);
                }
                else {
                    b.push_back(z[i]);
                    a.push_back(0);
                }
            }
        }
        for (int &k : a) cout << k;
        cout << "\n";
        for (int &k : b) cout << k;
        cout << "\n";
    }
}