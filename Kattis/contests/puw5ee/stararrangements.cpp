//#include <bits/stdc++.h>
#include <iostream>
#include <string>
using namespace std;

int main() {
    int S;
    cin >> S;
    cout << S << ":" << endl;
    
    int c = 2;
    int m = 1;
    while (c + c - m <= S) {
        if (S % (c + c - m) == 0 or (S - c) % (c + c - m) == 0) {
            cout << to_string(c) << "," << to_string(c-m) << endl;
        }
        if (m == 0) {
            c += 1;
            m = 1;
        }
        else {
            m = 0;
        }
    }

    return 0;
}