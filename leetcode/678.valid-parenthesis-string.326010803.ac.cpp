class Solution {
public:
    bool checkValidString(string s) {
        if(s.size()==0)
            return true;
        deque<int> unused_stars;
        int open = 0;
        for(int i = 0; i < s.size();i++){
            switch(s[i]) {
                case '(':
                    open++;
                    break;
                case ')':
                    open--;
                    break;
                default:
                    unused_stars.push_back(i);
            }
            
            if (open < 0) {
                if (unused_stars.size()) {
                    int pos = unused_stars.front();
                    unused_stars.pop_front();
                    s[pos] = '(';
                    open++;
                }
                else {
                    return false;
                }
            }
            
        }
        int closed = 0;
        for(int i = s.size()-1; i >= 0;i--){
            switch(s[i]) {
                case '(':
                    closed--;
                    break;
                case ')':
                    closed++;
                    break;
            }    
            
            if (closed < 0) {
                if (unused_stars.size() && i < unused_stars.back()) {
                    unused_stars.pop_back();
                    closed++;
                    open--;
                }
                else
                    return false;
            }
            
        }
        cout << open << endl;
        cout << closed;
        return open==closed;
        
    }
};
