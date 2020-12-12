#include <bits/stdc++.h>
using namespace std;

int main (){
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        string s(51, 'a');
        while (n--) {
            int k; cin >> k;
            cout << s << endl;
            
            char alt = (s[k] == 'a') ? 'b' : 'a';
            s = s.substr(0,k);
            
            s.append(string(51-s.size(),alt));
        }
        cout << s << endl;
    } 
}