#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m; cin >> n >> m;
    int m_ = m;
    vector<int> puzzles;
    while(m_--) {
        int k; cin >> k;
        puzzles.push_back(k);
    }
    sort(puzzles.begin(), puzzles.end(), greater<int>());
    int biggest = 0;
    int md = puzzles[biggest] - puzzles[biggest + n - 1];
    for (biggest = 1; biggest + n - 1 < puzzles.size(); biggest++) {
        md = min(md, puzzles[biggest] - puzzles[biggest + n - 1]);
    }
    cout << md;
    
}