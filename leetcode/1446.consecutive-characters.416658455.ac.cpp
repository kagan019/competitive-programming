class Solution {
public:
    int maxPower(string s) {
        if (s.size() == 0)
            return 0;
        char last = s[0];
        int m = 1;
        int cur = 1;
        for (int i = 1; i < s.size(); i++) {
            if (s[i] == last) {
                cur++;
                
            }
            else {
                cur = 1;
                last = s[i];
            }
            m = max(m,cur);
        }
        return m;
    }
};
