#include <bits/stdc++.h>
using namespace std;

int main () {
    string a, b;
    getline(cin, a);
    getline(cin, b);
    for(char &c : a) {
        c = tolower(c);
    }
    for(char &c : b) {
        c = tolower(c);
    }
    cout << a.compare(b);
}