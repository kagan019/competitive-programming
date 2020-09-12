#include <bits/stdc++.h>
using namespace std;

int main() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        string s; cin >> s;
        vector<int> sums;
        int sm = 0;
        
        for (int i = 0; i < n; i++) {
            char c = s[i];
            sm +=c-'0';
            sums.push_back(sm);
        }
        int ng = 0;
        for (int s = 0; s < n; s++) {
            if (s < fullsum) {
                bool found = false;
                if sum <= left 
                    ng += search left
                    found =true
                if (sum <= right)
                    ng += search right
                    found = true
                if (!found) {
                    (all of left, search s-left in right) ;
                    (search for left-(s-right) in left, all of right);
                }

            }
        }
        
        cout << ng << "\n";
        
        
    }
    
}
