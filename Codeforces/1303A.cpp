#include <bits/stdc++.h>
using namespace std;

int main(){
    int t; cin>>t;
    while(t--){
        string s; cin>>s;
        int leadingzeros =0;
        bool foundone = false;
        int allzeros = 0;
        for(int i=0; i<s.size();i++){
            if(s[i]=='1') {
                foundone=true;
                continue;
            }
            if(!foundone){
                leadingzeros++;
            }
            allzeros++;

        }
        if(!foundone){
            cout << 0 << "\n";
            continue;
        }
        int trailing_zeros = 0;
        for(int i=s.size()-1; i>=0;i--){
            if(s[i]=='1') break;
            trailing_zeros++;
        }
        cout << (allzeros-leadingzeros-trailing_zeros) << "\n";
    }
}