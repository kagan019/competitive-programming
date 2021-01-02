#include <bits/stdc++.h>
using namespace std;

int main() {
    unordered_set<int> rems;
    int x;
    while (cin >> x) {
        auto f = rems.find(x);
        if (f != rems.end()) {
            cout << (2020-x) * x;
        }
        else {
            rems.insert(2020-x);
        }
    }
}