#include <bits/stdc++.h>
using namespace std;

int main() {
    int a, b, c;
    cin >> a >> b >> c;
    if (a == 1 && c == 1) {
        cout << (a + b + c);
        return 0;
    }
    if (b == 1) {
        cout << ((b + min(a, c)) * max(a, c));
        return 0;
    }
    if (a == 1) {
        cout << ((a + b) * c);
        return 0;
    }
    if (c == 1) {
        cout << (a * (b + c));
        return 0;
    }
    cout << (a * b * c);
    
}