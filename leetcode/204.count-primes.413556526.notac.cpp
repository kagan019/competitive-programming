class Solution {
public:
    int countPrimes(int n) {
        // 2 3 4 5 6 7 8 9 
        if (n <= 2)
            return 0;
        vector<int> primes{2};
        for (int x = 3; x < n; x += 2) {
            for (int p : primes) {
                if (x % p == 0)
                    goto Z; 
                
            }
            primes.push_back(x);  
            Z:;
        }
        return primes.size();
    }
};
