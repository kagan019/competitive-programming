#include <bits/stdc++.h>
using namespace std;

int main() {
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        vector<int> a;
        bool pal_ss_of_lnth_al_3 = false;

        while(n--){
            int k; cin >> k;
            a.push_back(k);
        }
        unordered_set<int> us;
        for (int i = 2; i < a.size(); i++){
            us.insert(a[i-2]);
            if (us.find(a[i]) != us.end()){
                pal_ss_of_lnth_al_3 = true;
                break;
            }
        }
        if (pal_ss_of_lnth_al_3){
            cout << "YES\n";
        }
        else cout << "NO\n";
        
    }
}