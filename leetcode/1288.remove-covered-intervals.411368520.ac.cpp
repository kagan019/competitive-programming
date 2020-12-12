
int ab4b(vector<int> &a, vector<int> &b) {
    if (a[0] == b[0]) {
        return a[1] > b[1];
    }    
    return a[0] < b[0];
}
class Solution {
public:
    int overlap(vector<int> &a, vector<int> &b) {
        if (a[0] <= b[0] && a[1] >= b[1])
            return -1; //left
        if (b[0] <= a[0] && b[1] >= a[1])
            return 1; //right
        return 0;
    }
    int intvlsz(vector<int> &dim) {
        return dim[1]-dim[0];
    }
    
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), ab4b);
        set<int> skip;
        for (auto i = 0; i < intervals.size(); i++) {
            if (skip.find(i) != skip.end())
                continue;
            int j = i+1;
            while(j < intervals.size()) {
                if (skip.find(j) != skip.end()) {
                    j++;
                    continue;
                }
                if ((intervals[j])[0] > (intervals[i])[1])
                    break;
                int verdict = overlap(intervals[i],intervals[j]);
                assert(verdict != 1);
                if(verdict == -1) {//left superset of right
                    skip.insert(j);
                }
                j++;
            }
        }
        return intervals.size() - skip.size();
    }
};
