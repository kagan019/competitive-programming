#include <bits/stdc++.h>
using namespace std;

int main(){
    int t; cin >> t;
    string s;
    getline(cin, s); // to capture the end of the very first line
    
    while(t--){
        
        getline(cin, s);
        int maxlsinarow = 0;
        string::size_type nextL = 0;
        nextL = s.find('L', nextL);
        while(nextL != string::npos && nextL != s.size()){
            int curcount = 1;
            nextL++;
            while(nextL != s.size() && s[nextL] == 'L') {
                curcount++;
                nextL++;
            }
            maxlsinarow = max(curcount, maxlsinarow);
            nextL = s.find('L', nextL);

        }
        cout << (maxlsinarow + 1) << "\n";
    }

}