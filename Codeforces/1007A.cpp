#include <bits/stdc++.h>
using namespace std;

int main() {
    unordered_map<int,int> m;
    int x; cin >> x;
    for (int q =0; q < x; q++) {
        int z; cin >> z;
        auto f = m.find(z);
        if (f != m.end())
            m[z]++;
        else
            m[z] = 1;
    }

    int mm = -1;
    for (auto &p : m) {
        if (p.second > mm)
            mm = p.second;
    }
    cout << (x - mm);
}