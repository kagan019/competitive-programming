#include <bits/stdc++.h>
using namespace std;


int main() {
    int t; cin >> t;
    while(t--){
        uint64_t n; uint64_t k; 
        cin >> n >> k;
        uint64_t p = 0; uint64_t i = 1;
        while (p < k){
            
            p += i;
            i++;
        }
        uint64_t l, r;
        l = n - i;
        r = l+1+p-k;
         
        string s;
        for (uint64_t i=0;i< n;i++){
            if (i == l || i == r){
                s.push_back('b');
            }
            else s.push_back('a');
        }
        cout << s << endl;
    }
}
/*slower
int main() {
    int t; cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        
        int pos1 = 1, pos2 = 0;
        k--;
        while (k--) {
            if (pos2 == pos1-1) {
                pos1++;
                pos2 = 0;
            }
            else
                pos2++;
        }
        string o = "";
        for (int i = n; i > 0; i--) {
            char push = 'a';
            if (i == pos2+1 || i == pos1+1)
                push = 'b';
            o.push_back(push);
        }
        cout << o << "\n";
    }
}*/