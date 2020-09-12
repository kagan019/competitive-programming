#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int tawy = 0;
    int n; cin >> n;
    char last; cin >> last;
    while (--n) {
        char next; cin >> next;
        if (next == last) {
            tawy++;
        }
        else {
            last = next;
        }
    }
    cout << tawy;
}