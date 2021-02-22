#include <bits/stdc++.h>
using namespace std;

vector<bool> gen_primes() {
    vector<bool>primes(3000001,true);
    for (int i = 0; i < primes.size(); i++) {
        if (!(primes[i]))
            continue;
        for (int j = i*i; j < primes.size(); j += i) {
            primes[j] = false;
        }
    }
    return primes;
}

vector<pair<int,int>> pf(vector<bool> &primes, int i) {
    vector<pair<int,int>> ret;
    for (int p = 0; p < primes.size(); p++) {
        if (!(primes[p]))
            continue;
        if (p*p > i)
            break;
        int times = 0;
        while (i % p == 0) {
            i /= p;
            times++;
        }
        if (times == 0) continue;
        //cout << p << ": " << times << endl;
        ret.push_back(make_pair(p, times));
    }
    return ret;
}

int fac(int n, int stop) {
    int ret = 1;
    while(n > stop) {
        ret *= n;
        n--;
    }
    return ret;
}

int nCr(int n,int r) {
    if (r > n)
        return 0;
    return fac(n,n-r) / fac(r,0);
}

int NPF(vector<bool> &prm, int i) {
    vector<pair<int,int>> pf_ = pf(prm ,i);
    int ret = 1;
    for (int i = 0; i < pf_.size(); i++) {
        //cout << pf_[i].first << ":" << pf_[i].second << endl;
        ret *= (pf_[i].second+1);
    }
    return ret-pf_.size();
}

int main() {
    cin.sync_with_stdio(false);
    cin.tie(NULL);
    auto prm = gen_primes();
    int Q; cin >> Q;
    ostringstream ss;
    while (Q--) {
        int i; cin >> i;
        ss << NPF(prm, i) << endl;
    }
    cout << ss.str() << flush;
    return 0;
}