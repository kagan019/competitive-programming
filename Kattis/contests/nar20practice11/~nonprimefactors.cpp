#include <bits/stdc++.h>
using namespace std;

vector<long long> gen_primes() {
    vector<bool>primes(3000000/2,true); //ignore index 0,1
    for (long long i = 2; i < primes.size(); i++) {
        if (!primes[i])
            continue;
        for (long long j = i*i; j < primes.size(); j += i) {
            primes[j] = false;
        }
    }
    vector<long long> prms;
    for (long long p = 2; p < primes.size(); p++) {
        if (!primes[p])
            continue;
        prms.push_back(p);
    }
    return prms;
}

vector<pair<long long,long long>> pf(vector<long long> &primes, long long i) {
    vector<pair<long long,long long>> ret;
    const long long i2 = i;
    for (long long p : primes) {
        if (p*2 > i2)
            break;
        long long times = 0;
        while (i % p == 0) {
            i /= p;
            times++;
        }
        if (times == 0) continue;
        ret.push_back(make_pair(p, times));
    }
    return ret;
}

long long NPF(vector<long long> &prm, long long i) {
    vector<pair<long long,long long>> p = pf(prm ,i);
    long long ret = 1;
    for (long long i = 0; i < p.size(); i++) {
        //cout << pf_[i].first << ":" << pf_[i].second << endl;
        ret *= (p[i].second+1);
    }
    return ret-p.size();
}

int main() {
    cin.sync_with_stdio(false);
    cin.tie(NULL);
    auto prm = gen_primes();
    long long Q; cin >> Q;
    ostringstream ss;
    while (Q--) {
        long long i; cin >> i;
        ss << NPF(prm, i) << endl;
    }
    cout << ss.str() << flush;
    return 0;
}