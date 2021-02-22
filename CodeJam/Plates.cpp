#include <bits/stdc++.h>
using namespace std;


int solve(vector<vector<int>> &s, int P) {
    vector<vector<int>> dp(P+1,vector<int>(s.size(),0));
    dp[0][0] = 0;
    int q = 0;
    for (int p = 1; p <= P; p++) {
        q += s[0][p-1];
        dp[p][0] = q;
    }

    for (int i = 1; i < s.size(); i++) {
        dp[0][i] = dp[P][i-1];
        int bt = 0;
        for (int p = 1; p <= P; p++) {
            bt += s[i][p-1];
            for(z) {
                dp[p][i] = max(dp[p][i-1],bt[z]+dp[P-z][i-1]);
            }
        }
    }
    return dp[P][s.size()-1];
}

int main() {
    
    int T;
    cin >> T;
    int i = 0;
    while (T--) {
        i++;
        int N, K;
        int P;
        cin >> N >> K >> P;
        vector<vector<int>>s(N,vector<int>(min(K,P)));
        for (vector<int> &vv : s) {
            for (int &a : vv) {
                cin >> a;
            }
        }
        int ans = solve(s,max(K,P));
        cout << "Case #" << i << ": " << ans << endl;
    }
    
    
}