#include <bits/stdc++.h>
using namespace std;

int main(){
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        int m; cin >> m;
        if (((n- m) % m == 0)){
            cout << "YES\n";
        }
        else{
            cout << "NO\n";
        }
    }
}