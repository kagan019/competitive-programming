class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int zeros = 0;
        int i = 0;
        for (; i + zeros < nums.size(); i++) {
            while (i+zeros<nums.size() && nums[i+zeros] == 0) {
                zeros++; 
            }
            if (i+zeros >= nums.size()) break;
            nums[i] = nums[i+zeros];
        }
        for (; i < nums.size(); i++){
            nums[i] = 0;
        }
    }
};
