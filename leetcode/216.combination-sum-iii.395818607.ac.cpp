class Solution {
public:
    vector<unordered_set<int>> vv;
    void recurse(unordered_set<int> used, int k, int n, int s) {
        if (n <= 0) return;
        for (int i = s; i <= 9; i++) {
            if (used.find(i) != used.end()) {
                continue;
            }
            if (k == 1) {
                if (i == n) {
                    cout << i << endl;
                    used.insert(i);
                    vv.push_back(unordered_set<int>(used.begin(),used.end()));
                    used.erase(i);
                }
            } else {
                cout << i << " ";
                used.insert(i);
                recurse(used, k-1,n-i,i+1);
                used.erase(i);
            }
        }
    }
    
    vector<vector<int>> combinationSum3(int k, int n) {
        unordered_set<int> used;
        recurse(used,k,n,1);
        vector<vector<int>> combs;
        for (int i = 0; i < vv.size(); i++) {
            vector<int> xx(vv[i].begin(),vv[i].end());
            combs.push_back(xx);
            for (int x : xx) {
                cout << x << " " << endl;
            } cout << endl;
        }
        return combs;
    }
};
