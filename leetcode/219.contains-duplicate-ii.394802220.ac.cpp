class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        if (nums.size() <= k) {
            set<int> s(nums.begin(),nums.end());
            return s.size() != nums.size();
        }
        unordered_set<int> s(k+1);
        for (int i = 0; i <= k; i++) {
            s.insert(nums[i]);
        }
        if (s.size() != k+1)
            return true;
        for(int i = k+1; i < nums.size();i++) {
            s.erase(nums[i-k-1]);
            s.insert(nums[i]);
            if (s.size() != k+1){
                return true;
            }
        }
        return false;
    }
};
