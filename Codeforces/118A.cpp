#include <bits/stdc++.h>
using namespace std;


int main() {
    string s; cin >> s;
    string vowels = "aeiouy";
    string ret;
    for (auto &c : s) {
        c = tolower(c);
        if (vowels.find(c) == string::npos) {
            ret.push_back('.');
            ret.push_back(c);
        }
    }

    cout << ret;
}