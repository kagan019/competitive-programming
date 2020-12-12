class Solution {
public:
    
    bool backspaceCompare(string S, string T) {
        int s = S.size() - 1;
        int t = T.size() - 1;
        int scnt = 0;
        int tcnt = 0;
        while (true) {
            while (true) {    
                while (s >= 0 && S[s] == '#') {
                    scnt++;
                    s--;
                }           
                if (scnt) {
                    s--;
                    scnt--;
                    continue;
                }
                break;
            }
            while (true) {    
                while (t >= 0 && T[t] == '#') {
                    tcnt++;
                    t--;
                }           
                if (tcnt) {
                    t--;
                    tcnt--;
                    continue;
                }
                break;
            }
            if (s < 0 || t < 0)
                break;
            cout << S[s] << " " ;
            cout << T[t] << endl;
            if (S[s] != T[t])
                return false;
            s--;
            t--;
        }
        if (t >= 0 || s >= 0)
            return false;
        return true;
      
    }
};
