class Solution {
public:
    int longestValidParentheses(string s) {
        if (s.size() == 0)
            return 0;
        
        bool invalid[s.size()];
        for (int i = 0; i < s.size(); i++) {
            invalid[i] = false;
        }
        int rdepth = 0; // 'reverse depth'
        for (int i = s.size() - 1; i >=0; i--) {
            if (s[i] == ')')
                rdepth++;
            else
                rdepth--;
            if (rdepth < 0) {
                invalid[i] = true;
                rdepth = 0;
            }
        }
        
        
        int longest = 0;
        int current = 0;
        int depth = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(')
                depth++;
            else {
                depth--;
                current += 2;
            }
            if (depth < 0 || invalid[i]) { // depth < 0 or rdepth < 0
                current = 0;
                depth = 0;
            }
            longest = max(longest,current);
        }
        
        return longest;
    }
};