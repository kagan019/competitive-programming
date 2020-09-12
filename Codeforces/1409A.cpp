#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;

int main() {
    int t;
    cin >> t;
    while (t--) {
        ull x; ull y; 
        cin >> x >> y;
        cout << ((ull)(max(x,y)-min(x,y))+9)/10 << "\n";
    }
}

