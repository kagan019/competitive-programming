#include <bits/stdc++.h>
using namespace std;

int main() {
    char c; cin >> c;
    set<char> letters;
    cin >> c;
    while (c != '}') {
        letters.insert(c);
        cin >> c; // ,
        cin >> c;
    }
    cout << letters.size();
}