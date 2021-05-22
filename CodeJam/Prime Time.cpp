#include <bits/stdc++.h>
using namespace std;

int maxscore(vector<int> &h) {
    //sort(h.begin(),h.end());
    vector<int> sums{0};
    for(int pick = 2; pick < h.size(); pick++) {
        vector<int> sel(pick);
        for (int x = 0; x < sel.size(); x++) {
            sel[x] = x;
        }
        while(true) {
            int s = 0;
            int p = 1;
            unordered_set<int> selset(sel.begin(),sel.end());
            for (int j = 0; j < h.size(); j++) {
                if (selset.find(j) != selset.end()) {
                    p *= h[j];
                } else {
                    s += h[j];
                }
            }
            if (s == p) {
                sums.push_back(s);
                push_heap(sums.begin(), sums.end());
            }
            int see = sel.size()-1;
            while(sel[see] > h.size()-(sel.size()-see)) {
                see--;
                if (see < 0)
                    goto LABEL;
            }
            sel[see]++;
            while(see < sel.size()) {
                see++;
                sel[see] = sel[see-1]+1;
            }
        }
LABEL:;
    }
    return sums.front();
}

int main() {
    int T; cin >> T;
    for (int cs = 1; cs <= T; cs++) {
        int ans;
        int M; cin >> M;
        vector<int> hand(M);
        for (auto &p : hand) {
            int a; int b;
            cin >> a >> b;
            for (int i = 0; i < b; i++) {
                hand.push_back(a);
            }
        }
        ans = maxscore(hand);

        cout << "Case #" << cs << ": " << ans << endl;
    }
}