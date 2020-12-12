class Solution {
public:
    int arrangeCoins(int n) {
        return (int)((-1+sqrt(1.0+4.0*2*n))/2.0);
    }
};
