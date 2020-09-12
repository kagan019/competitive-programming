#include <bits/stdc++.h>
using namespace std;

int main() {
    int t = 25;
    int i = 0; int j = 0;
    int k;
    while (t--) {
        cin >> k;
        if (k) {
            break;
        }
        j += 1;
        if (j == 5) {
            j = 0; 
            i++;
        }
    }
    cout << abs(i-2) + abs(j-2);
}