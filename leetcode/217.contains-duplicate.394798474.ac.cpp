class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        set<int> n(nums.begin(), nums.end());
        return n.size() != nums.size();
    }
};
