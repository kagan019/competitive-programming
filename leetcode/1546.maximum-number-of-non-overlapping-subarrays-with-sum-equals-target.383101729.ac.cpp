class Solution {
public:
    int maxNonOverlapping(vector<int>& nums, int target) {
        unordered_set<int> store{target};
        int s = 0;
        int ans = 0;
        for (int i = 0; i <nums.size();i++){
           
            s += nums[i];
             auto found = store.find(s);
            if (found != store.end()) {
                ans++;
                store.clear();
                store.insert(target);
                s=0;
            } else {
                store.insert(target+s);
            }
        }
        return ans;
        /*
        int lastend = -1;
        int ans = 0;
        for(int i = 0; i< nums.size(); i++) {
           int s = 0;
           for(int j = i; j > lastend; j--) {
               s += nums[j];
               if (s == target) {
                   ans++;
                   lastend = i;
               }
           }
        }
        return ans;
        */
    }
};
