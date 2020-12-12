class Solution {
public:
    int totenmod1337(int x){
        x %= 1337;
        int sq = x * x % 1337;
        int qrt = sq * sq % 1337;
        int oct = qrt * qrt % 1337;
        return oct * sq % 1337;
    }
    
    int superPow(int a, vector<int>& b) {
        int pows[10];
        a %= 1337;
        pows[0] = 1;
        for (int i = 1; i < 10; i++){
            pows[i] = pows[i-1] * a % 1337;
        }
        
        int c = 1;
        for (int i = 0; i < b.size(); i++) {
            c = totenmod1337(c);
            c = c * pows[b[i]] % 1337;
        }
        return c;
        
            
    }
};
