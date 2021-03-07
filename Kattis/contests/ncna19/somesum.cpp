#include <bits/stdc++.h>
using namespace std;

int main() {
    int N; cin >> N;

    switch(N % 4) {
        case 0:
            cout << "Even";
        break;
        case 1:
            cout << "Either";
        break;
        case 2:
            cout << "Odd";
        break;
        case 3: default:
            cout << "Either";
    }
}