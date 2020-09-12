#include <bits/stdc++.h>
using namespace std;

int main() {
    string un; getline(cin, un);
    sort(un.begin(), un.end());
    auto last = unique(un.begin(), un.end());
    cout << (
        (last - un.begin()) % 2 == 0 
            ? "CHAT WITH HER!"
            : "IGNORE HIM!"
    );
}