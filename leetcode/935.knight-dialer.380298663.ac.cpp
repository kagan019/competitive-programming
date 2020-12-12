class Solution {
public:
    
    const int MOD = 1e9 + 7;
    
    vector<vector<int>> moves;
    vector<vector<int>> dp;
    
    int recurse(int N, int key) {
        if (dp[N][key] != -1) {
            return dp[N][key];
        }
        int ans = 0;
        for (int nk : moves[key]) {
            ans += recurse(N-1,nk);
            ans %= MOD;
        }
        dp[N][key] = ans;
        return ans;
    }
    
    int knightDialer(int N) {
        moves = {
                  {4,6},
            {6,8},{7,9},{4,8},
            {3,9,0},{},{1,7,0},
            {2,6},{1,3},{2,4}
        };
        
        dp = vector<vector<int>>(N+1,vector<int>(10,-1));
        for (int &x : dp[1]) x = 1;
        int s = 0; 
        for (int key = 0; key < 10; key++) {
            s += recurse(N,key);
            s %= MOD;
        }
    
        
        return s;
    }
};
