#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<bool> s;
    while (char k = cin.get()) {
        if (k == '\n')
            break;
        s.push_back(k == '1');
    }
    int y = 0;
    int n = 0;
    for (const auto &i : s) {
        if (i) {
            y++;
            n = 0;
        }
        else {
            n++;
            y = 0;
        }
        if (y >= 7 || n >= 7) {
            cout << "YES";
            return 0;
        }
    }
    cout << "NO";
}