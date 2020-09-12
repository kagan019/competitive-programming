#include <bits/stdc++.h>
using namespace std;

int main() {
    int t; cin >> t;
    while (t) {
        int s; cin >> s;
        int spent = 0;
        while (s >= 10) {
            int k = s / 10;
            s += k;
            spent += 10 * k;
            s -= 10 * k;

        }
        cout << spent + s << "\n";
        t--;
    }
}