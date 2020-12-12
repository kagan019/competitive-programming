class Solution {
public:

    string makeGood(string s) {
        int n = s.size();
        for (int i = 0; i < n; i++){
            while (s[i] == s[i+1] + 97-65 || s[i] == s[i+1] +65-97) {
                s.replace(i,2,"");
                if (i)
                    i--;
            }
        }
        return s;
    }
};
