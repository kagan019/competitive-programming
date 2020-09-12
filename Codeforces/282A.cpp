#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    int x = 0;
    string stmt;
    getline(cin,stmt);
    while(n--) {
        getline(cin, stmt);
        if (stmt.front() == '+' || stmt.back() == '+')
            x++;
        else x--;
    }
    cout << x;
}