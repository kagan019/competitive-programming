#include <bits/stdc++.h>
using namespace std;

long long subfours(long long n){
    long long ret = 0;
    long long powof10 = 1;
    while(n){
        if (n% 10 == 4) {
            ret += 3 * powof10;
        }
        else 
            ret += (n % 10) * powof10;
        n /= 10;
        powof10 *= 10;
    }
    return ret;
}

int main() {
    long long T; cin >> T;
    for (long long casenum = 0; casenum < T; casenum++){
        long long n; cin >> n;
        long long B = subfours(n);
        long long A = n-B;
        if (A== 0){
            A = 1;
            B--;
        }
        cout << "Case #" << (casenum+1) << ": " << A << " " << B << "\n";
    }
}