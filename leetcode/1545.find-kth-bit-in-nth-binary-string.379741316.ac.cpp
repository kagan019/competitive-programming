class Solution {
public:
    char recurse(int n, int k) {
        if (n == 1)
            return '0';
        int len = (1 << n) - 1;
        if (k-1 == len/2)
            return '1';
        if (k-1 > len/2)
            return recurse(n-1, len-k+1) == '0' ? '1' : '0';
        return recurse(n-1, k);
    }
    
    char findKthBit(int n, int k) {
        return recurse(n,k);
    }
};
