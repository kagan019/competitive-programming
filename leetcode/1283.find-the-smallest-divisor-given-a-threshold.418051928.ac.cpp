/* you search deep, before searching breadthfully
  get a better mastery of your fundamentals & composables
  not everything needs to be the best, most precise way the first time your write it
*/


class Solution {
public:
    long cdiv(int a, int b) {
        return (a + b-1) / b;
    }
    
    long computeSum(vector<int> &nums, long x) {
        long s = 0;
        for (int i = 0; i < nums.size(); i++) {
            s += cdiv(nums[i],x);
        }
        return s;
    }
    
    long smallestDivisor(vector<int>& nums, int threshold) {
        int left = 1;
        int right = 2;
        
        while(computeSum(nums, right) > threshold) {
            left = right;
            right <<= 2;
        }
        //target between left & right boundaries
        while(left <= right) {
            int pivot = (left + right) / 2l;
            long num = computeSum(nums, pivot);
            if (num > threshold) {
                left = pivot + 1;
            } 
            else {
                right = pivot -1;
            }
        }
        //left > right
        // computeSum(left) <= threshold
        // computeSum(right) > threshold
        return left;
    }
};
