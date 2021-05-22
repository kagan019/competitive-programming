#include <bits/stdc++.h>
using namespace std;

int additional(int x, int y, vector<pair<bool,bool>> v) {

    int s= 0;
    for (auto &p : v) {
        if (p.first != p.second) {
            s += (p.first) ? x : y;
        }
            
    }

    return s;
}

int cost(int x, int y, string s) { 
    int cj = 0;
    int jc = 0;
    for (int i = 0; i < s.size()-1;i++) {
        if (s[i] == 'C' && s[i+1] == 'J')
            cj++;
        if (s[i] == 'J' && s[i+1] == 'C')
            jc++;
    }
    return cj*x + jc*y;
}

int main() {
    int T; cin >> T;
    for (int cs = 1; cs <= T; cs++) {
        int ans;

        int X; int Y; cin >> X >> Y;
        string s; cin >> s;
        vector<pair<bool,bool>> v; // true is c
        vector<bool>single;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '?') {
                continue;
            }
            
            if (single.size() && s[i-1] == '?') {
                v.push_back({single.back(),s[i]=='C'});
                single.pop_back();
            }
            if (single.size() == 0 && s[i+1] == '?')
                single.push_back(s[i]=='C');

        }

        int ad = additional(X,Y,v);
        int cjjc = cost(X,Y,s);  
        ans = ad+cjjc;
        cout << "Case #" << cs << ": " << ans << endl;
    }
}