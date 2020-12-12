class Solution {
public:
    uint64_t nthUglyNumber(int n) {
        if (n == 1)
            return 1;
        vector<uint64_t> ugly {1, 2, 3, 4, 5};
        for (int i=6; i <= n; i++){
            ugly.push_back(next_ugly(ugly));
        }
        return ugly[n-1];
    }
    
    uint64_t next_ugly(vector<uint64_t> &ugly) {
        uint64_t cap = ugly[ugly.size()-1];
        uint64_t min = cap*5;
        for (int p : {2, 3, 5}) {
            for (int i = ugly.size()-1; i>= 0; i--) {
                uint64_t test = ugly[i] * p;
                if (test <= cap)
                    break;
                if (test < min) 
                    min = test;
            }
        }
        return min;
    }
};
