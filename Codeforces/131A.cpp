#include <bits/stdc++.h>
using namespace std;

bool capslock(const string &n) {
    for (int i = 0; i < n.size(); i++) {
        if (!(i == 0 || isupper(n[i])))
            return false;
    }
    return true;
}

int main() {
    string n; cin >> n;
    bool c = capslock(n);
    
    if (c) {
        for (int i = 0; i < n.size(); i++) {
            if (i == 0 && islower(n[i])) {
                n[i] = toupper(n[i]);
            }
            else {
                n[i] = tolower(n[i]);
            }
        }
    }
    cout << n;
}