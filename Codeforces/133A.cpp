#include <bits/stdc++.h>
using namespace std;

int main() {
    string l; getline(cin, l);
    for (char &c : l) {
        if (c == 'H' || c == 'Q' || c == '9') {
            cout << "YES";
            return 0;
        }
    }
    cout << "NO";

}