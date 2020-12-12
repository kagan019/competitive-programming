class Solution {
public:
    unordered_map<int,int> effective_caching;
    int startedfromthebottomnowwerehere(int n) {
        auto f = effective_caching.find(n);
        if (f != effective_caching.end()) {
            return f->second;
        }
        int ans;
        if (n == 0)
            ans = 0;
        else if (n == 1)
            ans = 1;
        else if (n == 2)
            ans = 2;
        else {
            ans = startedfromthebottomnowwerehere(n-1) + startedfromthebottomnowwerehere(n-2);
        }
        effective_caching[n] = ans;
        return ans;
    }
    int climbStairs(int n) {
        //unordered_map<int,int> effective_caching;
        for (int i = 0; i <= n; i++)
            startedfromthebottomnowwerehere(i);
        return effective_caching[n];
        
    }  
};
