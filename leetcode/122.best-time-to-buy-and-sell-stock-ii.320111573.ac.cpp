class Solution {
public:
    int maxProfit(vector<int>& prices) {
        const int n = prices.size();
        if (n == 0) return 0;
        
        int s = 0;
        for(int i = 1; i < prices.size(); i++){
            int x = prices[i]-prices[i-1];
            if (x > 0) s += x;
        }
        

        return s;
    }
};
