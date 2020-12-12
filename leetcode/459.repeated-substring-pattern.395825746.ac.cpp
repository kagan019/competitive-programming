class Solution {
public:
    bool isValid(int i, string s){ 
        if (i == s.size()) return false;
        int j;
        for (j = 0; i+j < s.size(); j++) {
            if (s[j%i] != s[i+j])
                return false;
        }
        return (j-1)%i == i - 1;
    }   
    
    bool repeatedSubstringPattern(string s) {
        int i = 0;
        while (i < s.size()){
            i++;
            if (s[i] == s[0]){
                if (isValid(i, s)) {
                    return true;
                }
            }
        }
        return false;
    }
};
