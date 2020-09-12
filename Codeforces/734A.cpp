#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    int a = 0;
    int d = 0;
    string s; cin >> s;
    for (char &c : s) {
        if (c == 'A')
            a++;
        else
            d++;
    }
    if (a == d) {
        cout << "Friendship";
        return 0;
    }
    cout << (a > d ? "Anton" : "Danik"); 
}