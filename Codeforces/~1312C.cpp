#include<bits/stdc++.h>
using namespace std;

int main() {
    int T; cin >> T;
    
LOOP:    
    while (T--){
        long n, k;
        cin >> n >> k;
        unordered_set<long> powers_in_sum;
        while (n--){
            long x; cin >> x;
            
            long i = 0;
            while(x != 0){
                if (x % k){
                    if (powers_in_sum.find(i) == powers_in_sum.end())
                        powers_in_sum.insert(i);
                    else{
                        cout << "NO\n";
                        if (n) {
                            while(n--) cin >> x;
                        }
                        goto LOOP;
                    }
                    x -= x % k;
                }
                x /= k;
                i++;
            }
        }
        
            
        cout << "YES\n";

    }
}