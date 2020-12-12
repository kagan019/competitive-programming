class Solution {
public:
    bool hourIsValid(vector<int>& arr) {
        if (arr[0] == 2) {
            if (arr[1] >= 4)
                return false;
            return true;
        } 
        if (arr[0] > 2) return false;
        return true;
    }
    bool minuteIsValid(vector<int>& arr) {
        return arr[2] < 6;
    }
    
    string tostr(vector<int>& arr) {
        string str = "00:00";
        int j = 0;
        for (int i =0; i< 4;i++) {
            if(i==2) {j++;}
            str[j] = '0' + arr[i];
            j++;
            
        }
        return str;
    }
    int tomin(vector<int>& arr) {
        return arr[0] * 600 + arr[1] * 60 + arr[2] * 10 + arr[3];
    }
    void mv(vector<int>& s, vector<int>&d) {
        for (int i = 0; i < 4; i++) {
            d[i] = s[i];
        }
    }
    
    string largestTimeFromDigits(vector<int>& arr) {
        int curbest = 0;
        vector<int> b{9,9,9,9};
        sort(arr.begin(), arr.end());
        do {
            for (int i = 0; i< 4; i++) {
                cout << arr[i];
            }
            cout << endl;
            if (!hourIsValid(arr) || !minuteIsValid(arr))
                continue;
            
            int myval = tomin(arr);
            cout << myval << endl;
            
            if (myval >= curbest) {
                mv(arr,b);
                curbest = myval;
            }
        } while(next_permutation(arr.begin(), arr.end()));
        
        if (!hourIsValid(b) && !minuteIsValid(b))
            return "";
        return tostr(b);
    }
};
