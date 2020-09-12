#include <bits/stdc++.h>
using namespace std;

int main() {
    string s; cin >> s;
    string t; cin >> t;
    if (t.size() != s.size()){
        cout << "NO";
        return 0;
    }
    for (int i = 0; i < (int)s.size(); i++) {
        if (s[i] != t[t.size() - i - 1]) {
            cout << "NO";
            return 0;
        }
    }
    cout << "YES";
}