class Solution {
public:
    int search(vector<int>& nums, int target) {
        if (nums.size() == 0)
            return -1;
        int last = 0;
        int l = 0;
        int r = nums.size() - 1;
        cout << l << " " << r << endl;
        while (r > l) {
            
            int mid = (r + l) / 2;
            if (nums[l] == target)
                return l;
            if (nums[r] == target)
                return r;
            if (nums[mid] == target)
                return mid;
            if (l == mid) {
                return -1;
            }
            if (nums[r] > nums[l]) {
                //basically the same as binary search
                if (nums[mid] < target) {
                    l = mid;
                    continue;
                }
                if (nums[mid] > target) {
                    r = mid;
                    continue;
                }
            }
            if (nums[r] < nums[l]) { // pivot is between l and r
                if(target < nums[l] && target > nums[r]) {
                    cout << "?";
                    return -1;
                }
                if (target > nums[l]) { //target before pivot
                    if (nums[mid] >= nums[l]) {//mid before pivot
                        if (target > nums[mid]) {
                            l = mid;
                            continue;
                        }
                        if (target < nums[mid]) {
                            r = mid;
                            continue;
                        }
                    }
                    if (nums[mid] <= nums[r]) { // mid after pivot
                        r = mid;
                        continue;
                    }
                }
                if (target < nums[r]) { //target after pivot
                    if (nums[mid] >= nums[l]) { //mid before pivot 
                        l = mid;
                        continue;
                    }
                    if (nums[mid] <= nums[r]) {
                        if (target > nums[mid]) {
                            l = mid;
                            continue;
                        }
                        if (target < nums[mid]) {
                            r = mid;
                            continue;
                        }
                    }
                }
            }
        }
        if (nums[l] == target)
            return l;
        return -1;
       
    }
};
