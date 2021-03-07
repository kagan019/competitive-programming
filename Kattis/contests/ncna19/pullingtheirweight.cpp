#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> anm(20001,0);
    int m; cin >> m;
    int total = 0;
    while(m--) {
        int x; cin >> x;
        anm[x]++;
        total += x;
    }
    int s =0;
    for (int w = 1; w < 20001; w++) {
        s += w*anm[w];
        if (s == total/2) 
        {
            cout << w+1;
            return 0;
        } else if (s > total/2) {
            cout << w;
            return 0;
        }
    }
}