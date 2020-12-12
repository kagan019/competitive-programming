class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        queue<int> fw;
        forward_list<int> bw;
        int fi = 1, bi = 1;
        fw.push(-1);
        for (int i = 0; i < nums.size(); i++) {
            fi *= nums[i];
            fw.push(fi);
        }
        for (int i = nums.size() - 1; i >= 0; i--) {
            bi *= nums[i];
            bw.push_front(bi);
        }
        
        vector<int> ret(nums.size());
        for (int i = 0; i< ret.size(); i++) {
            int l = (i > 0) ? fw.front() : 1;
            fw.pop();
            bw.pop_front();  
            int r = (i < ret.size() -1) ? bw.front() : 1;
            ret[i] = l * r;
                
        }
        return ret;
      
    }
};
