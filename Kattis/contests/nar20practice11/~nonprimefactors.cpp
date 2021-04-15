#include <bits/stdc++.h>
using namespace std;

vector<bool> gen_primes() {
    vector<bool>primes(3000002,true); //ignore index 0,1
    for (long long i = 2; i < primes.size(); i++) {
        if (!primes[i])
            continue;
        for (long long j = i*i; j < primes.size(); j += i) {
            primes[j] = false;
        }
    }
    return primes;
}

vector<long long> count_nonprimes() {
    auto primes = gen_primes();
    vector<long long>nonprimes(3000002,1); //ignore index 0,1
    for (long long i = 2; i < nonprimes.size(); i++) {
        if (!primes[i])
            continue;
        for (long long j = i*i; j < nonprimes.size(); j += i) {
            nonprimes[j] += 1;
        }
    }
    return nonprimes;
}

vector<pair<long long,long long>> pf(vector<long long> &primes, long long i) {
    vector<pair<long long,long long>> ret;
    //set<long long> primes2(primes.begin(),primes.end());
    const long long i2 = i;
    for(auto p : primes) {
        if (2*p > i2) break;
        long long times = 0;
        while(i % p == 0) {
            long long exp = 1;
            long long divisor = p;
            
            while (i % divisor == 0) {
                i /= divisor;
                times += exp;
                exp *= 2;
                divisor *= divisor;
            }
        }

        if (times == 0) continue;
        ret.push_back(make_pair(p, times));
    }
    return ret;
}

long long NPF(vector<long long> &prm, long long i) {
    vector<pair<long long,long long>> p = pf(prm ,i);
    long long ret = 1;
    for (long long j = 0; j < p.size(); j++) {
        ret *= (p[j].second+1);
    }
    return ret-p.size();
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    //auto prm = gen_primes();
    auto nonprm = count_nonprimes();
    long long Q; scanf("%lld",&Q);
    ostringstream ss;
    while (Q--) {
        long long i; scanf("%lld",&i);
        ss << nonprm[i] << endl;
    }
    printf("%s", ss.str().c_str());
    return 0;
}