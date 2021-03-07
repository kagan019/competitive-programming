#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    vector<vector<int>>cb(n,vector<int>(n));
    for (vector<int> &vv : cb) {
        for (int &x : vv) {
            char c; cin >> c;
            x = (c == 'B') ? 1 : 0;
        }
    }

    vector<int> rowc(n,0);
    vector<int> colc(n,0);
    
    vector<int> colt(n,0);
    for (int r = 0; r < n; r++) {
        int rowt = 0;
        for (int c = 0; c < n; c++) {
            rowc[r] += cb[r][c];
            colc[c] += cb[r][c];
            if (cb[r][c]) {
                if (rowt > 0) {
                    rowt++;
                }
                else {
                    rowt = 1;
                }
            } else {
                if (rowt < 0) {
                    rowt--;
                }
                else {
                    rowt = -1;
                }
            }
            if (rowt >= 3 || rowt <= -3) {
                cout << 0;
                return 0;
            }

            if (cb[r][c]) {
                if (colt[c] > 0) {
                    colt[c]++;
                }
                else {
                    colt[c] = 1;
                }
            } else {
                if (colt[c] < 0) {
                    colt[c]--;
                }
                else {
                    colt[c] = -1;
                }
            }
            if (colt[c] >= 3 || colt[c] <= -3) {
                cout << 0;
                return 0;
            }
            
        }
        if (rowc[r] != n/2) {
            cout << 0;
            return 0;
        }
    }
    for (int c = 0; c < n; c++) {
        if (colc[c] != n/2) {
            cout << 0;
            return 0;
        }
    }
    cout << 1;
}