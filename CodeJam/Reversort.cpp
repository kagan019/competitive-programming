#include <bits/stdc++.h>
using namespace std;

int reversortcost(vector<int> &L) {
    int s = 0;
    for (int i = 0; i < L.size()-1; i++) {
        auto findmin = min_element(L.begin()+i,L.end());
        s += findmin - (L.begin() + i)+1;
        reverse(L.begin()+i,findmin+1);
    }
    return s;
}

int main() {
    int T; cin >> T;
    for(int cs = 0; cs < T; cs++) {
        int N; cin >> N;
        vector<int> L(N);
        for (int &x : L) cin >> x;
        int cost = reversortcost(L);
        cout << "Case #" << (cs+1) << ": " << cost << endl; 
    }

}