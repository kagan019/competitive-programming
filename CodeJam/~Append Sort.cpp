#include <bits/stdc++.h>
using namespace std;

long long digits(long long i){
    return (long long)(log(i)/log(10))+1;
}

long long solve(vector<long long> &X) {
    long long last = X[0];
    long long total = 0;
    for (long long i = 1; i < X.size(); i++) {
        long long cur = X[i];
        long long digdiff = digits(last)-digits(cur);
        if (cur > last) {
            last = cur;
            continue;
        }
        if (digdiff == 0) {
            last = cur * 10;
            total++;
            continue;
        }
        long long dupl = last;
        long long extra = 0;
        long long pow = 1;
        for (long long k = 0; k < digdiff; k++) {
            extra += pow * (dupl % 10);
            dupl /= 10;
            pow *= 10;
        }
        long long trylast = cur * pow;
        if (trylast > last) {
            last = trylast;
            total += digits(pow)-1;
            continue;
        }
        long long append = extra+1;
        if (digits(append) <= digits(pow)-1) {
            trylast = cur * pow + append;
            if (trylast > last) {
                last = trylast;
                total += digits(pow)-1;
                continue;
            }
        }
        
        last = cur * pow * 10;
        total += digits(pow);
    }
    return total;
}

int main() {
    long long T; cin >> T;
    for(long long cs = 1; cs <= T; cs++) {
        long long rst;
        long long N; cin >> N;
        vector<long long>X(N);
        for (long long &x : X) cin >> x;
        rst = solve(X);
        cout << "Case #" << cs << ": " << rst << endl;
    }
}