#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    int T = 0;
    while (T < 10) {
        cin >> n;
        if (n < 0)
            break;
        long sum = 0;
        int last = 0;
        for (int i = 0; i < n; i++) {
            int s; int t;
            cin >> s >> t;
            sum += (long)s * ((long)t-(long)last);
            last = t;
        }
        cout << sum << " miles" << endl;

        T++;
    }
}