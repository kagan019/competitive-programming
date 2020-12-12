class Solution {
public:
    string text1_;
    string text2_;
    unordered_map<char,deque<int>> t1m;
    int recurse(int t1i, int t2i) {
        if (t1i == text1_.size() || t2i == text2_.size())
            return 0;
        if (t1m.count(text2_[t2i]) == 0) {
            return recurse(t1i,t2i+1);
        }
        int i = t1m[text2_[t2i]].front();
        while (i < t1i && t1m[text2_[t2i]].size()) {
            t1m[text2_[t2i]].pop_front();
            i = t1m[text2_[t2i]].front();
        }
        if (i < t1i) {
            return recurse(t1i,t2i+1);
        }
        
        return max(1 + recurse(t1i+i+1,t2i+1),
                   recurse(t1i, t2i+1));
    }
    
    int longestCommonSubsequence(string text1, string text2) {
        if (text1.size() < text2.size()) {
            return longestCommonSubsequence(text2, text1);
        }
        text1_ = string(text1.begin(), text1.end());
        text2_ = string(text2.begin(), text2.end());
        for (int i = 0; i < text1.size(); i++) {
            if (t1m.count(text1[i]) == 0) {
                t1m[text1[i]] = deque<int>();
            }
            t1m[text1[i]].push_back(i);
        }
        return recurse(0,0);
    }
};
