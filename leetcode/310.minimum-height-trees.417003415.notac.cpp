class Solution {
public:

    
    
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if (edges.size() == 0)
            return vector<int>{0};
        vector<int> longestpathfrom(n,0);
        for (int i = 0; i < edges.size(); i++) {
            longestpathfrom[edges[i][0]] = max(longestpathfrom[edges[i][1]] + 1, longestpathfrom[edges[i][0]]);
            longestpathfrom[edges[i][1]] = max(longestpathfrom[edges[i][0]] + 1, longestpathfrom[edges[i][1]]);
        }

        
        auto mne = min_element(longestpathfrom.begin(), longestpathfrom.end());
        assert(mne != longestpathfrom.end());
        vector<int> mhts;
        for (int i = 0; i < n; i++) {
            if (longestpathfrom[i] == *mne) {
                mhts.push_back(i);
            }
        }
        return mhts;

    }
};
