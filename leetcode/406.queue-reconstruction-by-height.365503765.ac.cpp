class Solution {
public:
    static bool ab4b(vector<int>& a, vector<int> &b) {
        if (a[0] == b[0])
            return a[1] < b[1];
        return a[0] > b[0];
    }
    
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(people.begin(), people.end(), ab4b);
        
        forward_list<int> fl;
        for (int i = 0; i < people.size(); i++) {
            int after = min(i-1, people[i][1]-1);
            if (after == -1) {
                fl.push_front(i);
            }
            else {
                fl.insert_after(next(fl.begin(), after), i);
            }
        }
            
            
        vector<vector<int>> a(people.size());
        auto g = fl.begin();
        for (auto &x : a) {
            x = people[*g];
            g++;
        }
        return a;
    }
};
