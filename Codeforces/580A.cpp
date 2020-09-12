#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    int longest = 0;
    int current = 0;
    int last = -1;
    while(n--) {
        int k; cin >> k;
        if (k >= last) {
            current++;
        }
        else
            current = 1;
        longest = max(longest,current);
        last = k;
    }
    cout << longest;
}