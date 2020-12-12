class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> s;
        s[0] = 1;
        int v = 0;
        int c = 0;
        for (int i =0; i < nums.size(); i++) {
            v += nums[i];
            if (s.find(v-k) != s.end()) {
                c += s[v-k];

            }
            if (s.find(v) == s.end())
                s[v] = 1;
            else
                s[v]++;
        }
        return c;
    }
};
