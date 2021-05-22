#include <bits/stdc++.h>
using namespace std;


int solve(vector<vector<int>> &s, int P) {
    const int K = s[0].size();
    const int N = s.size();
    vector<vector<int>> dp(N+1,vector<int>(P+1,0));
    for (int n = 1; n <= N; n++) {
        for (int k = 1; k <= P; k++) {
            int taketopzfromstackn = 0;
            dp[n][k] = dp[n-1][k];
            for (int z = 1; z <= min(k,K); z++) {
                taketopzfromstackn += s[n-1][z-1];
                dp[n][k] = max(dp[n][k],taketopzfromstackn+dp[n-1][k-z]);

            }
        }
    }
    return dp[N][P];
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
        vector<vector<int>>s(N,vector<int>(K));
        for (vector<int> &vv : s) {
            for (int &a : vv) {
                cin >> a;
            }
        }
        int ans = solve(s,P);
        cout << "Case #" << i << ": " << ans << endl;
    }
    
    
}