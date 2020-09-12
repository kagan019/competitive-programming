#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    int t; cin >> t;
    vector<int> boys;
    int n_ = n;
    while(n_--) {
        char c; cin >> c;
        if (c == 'B')
            boys.push_back(n - n_ - 1);
    }
    while (t--) {
        for (int i = 0; i < boys.size(); i++) {
            if (i+1 < boys.size() && boys[i + 1] != boys[i] + 1)
                boys[i]++;
            else if (i + 1 == boys.size() && boys[i] + 1 < n)
                boys[i]++;
        }
    }

    string output;
    for (int &x : boys) {
        while (output.size() < x) {
            output.push_back('G');
        }
        output.push_back('B');
    }
    while(output.size() < n) {
        output.push_back('G');
    }
    cout << output;
}