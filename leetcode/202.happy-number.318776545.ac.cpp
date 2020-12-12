class Solution {
public:
    int ssqdigs(int x){
        int s = 0;
        while(x){
            s += (x%10)*(x%10);
            x /= 10;
        }
        return s;
    }
    bool isHappy(int n) {
        set<int> cycle;
        while (n != 1 && cycle.find(n) == cycle.end()){
            cycle.insert(n);
            n = ssqdigs(n);
        }
        if (n == 1){
            return true;
        }
        return false;
        
    }
};
