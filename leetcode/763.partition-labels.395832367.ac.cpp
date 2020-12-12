class Solution {
public:
    vector<int> x;
    void su(unordered_set<int> &s, unordered_set<int> &d) {
        d.merge(unordered_set<int>(s.begin(),s.end()));
    }
    vector<int> sofp(vector<unordered_set<int>>& vs) {
        for (int i = 0; i< vs.size(); i++) {
            x.push_back(vs[i].size());
        }
        return x;
        
    }
    vector<int> partitionLabels(string S) {
        vector<unordered_set<int>> vs;
        vector<int> sz;
        for(int i = 0; i < S.size(); i++){
            int j;
            for (j = 0; j<vs.size(); j++)  {
                if (vs[j].find(S[i]) != vs[j].end()) {
                    for (int k = vs.size()-1; k >j; k--) {
                        su(vs[k],vs[k-1]);
                        sz[k-1]+=sz[k];
                        vs.pop_back();
                        sz.pop_back();
                    }
                    sz[j]++;
                    break;
                }
            }
            if (j == vs.size()) {
                unordered_set<int> g{S[i]};
                vs.push_back(g);
                sz.push_back(1);
            }
        }
        return sz;
    }
};
