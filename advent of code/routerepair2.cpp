#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> nums(0);
    int x;
    while(cin >> x) {
        nums.push_back(x);
    }

    unordered_map<int,int> k;
    int i = 0;
    for (int x : nums) {
        k.insert({x,i});
        i++;
    }
    
    for (int u = 0; u < nums.size()-1; u++) {
        for (int v = u+1; v < nums.size(); v++) {
            int s = nums[u]+nums[v];
            auto f= k.find(2020-s);
            if (f != k.end() && f->second != u && f->second != v) {
                cout << nums[u]*nums[v]*nums[f->second];
                return 0;
            }
        }
    }
}