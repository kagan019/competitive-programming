class Solution {
public:
    
    unsigned int log_base(int b, int e) {
        return (unsigned int)(log((double)e)/log((double)b));
    }
    
    int rangeBitwiseAnd(int m, int n) {
        if (m == 0)
            return 0;
        unsigned int mask = 1 << log_base(2, n);
        unsigned int g = n & m;
        while (mask > 0 && ~(n ^ m) & mask) {
            mask >>= 1;
        }
        while (mask > 0) {
            g &= ~mask;
            mask >>= 1;
        } 
        return g;
        
    }
};
