 
#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;
    while (cin >> s) {
        vector<vector<int>> b(128, vector<int>(0)); //char -> list of its indexes in string   
        for (int i = 0; i < s.size(); i++) {
            b[s[i]].push_back(i);
        }
        vector<int> sums(b.size());
        int tots = 0;
        for (int i = 0; i < b.size(); i++) {
            tots += b[i].size();
            sums[i] = tots;
        }

        int n; cin >> n;
        for (int i = 0; i < n; i++) {
            int qi;
            cin >> qi;
            //figure out what positions can be the qith
            int chari = lower_bound(sums.begin(), sums.end(), qi) - sums.begin();

            vector<pair<string,int>> tosort;
            for (int idx : b[chari]) {
                string sfx = s.substr(idx);
                tosort.push_back({sfx,idx});
            }
            sort(tosort.begin(), tosort.end(), [](auto &a, auto &b) {
                return a.first < b.first;
            });

            cout << tosort[qi].second << " ";
        }
    }
}