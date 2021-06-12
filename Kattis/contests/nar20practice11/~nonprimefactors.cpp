#include <bits/stdc++.h>
using namespace std;


vector<vector<long long>> pfactors() {
    vector<vector<long long>> pfacs(3000002,vector<long long>()); //ignore index 0,1
    vector<long long> todo(3000002, -1);
    vector<bool> primes(3000002,true);
    for (long long i = 2; i < pfacs.size(); i++) {
        if (!primes[i])
            continue; //not prime; has factors other than itself
        pfacs[i].push_back(i);
        for (long long j = i*i; j < pfacs.size(); j += i) {
            /* want to do
                pfacs[j] = pfacs[j/i];
                pfacs[j].push_back(i);
            but first we gotta make sure pfacs[j/i] is reached
            */
            todo[j] = i;
            primes[j] = false;
        }
    }
    for (long long j = 2; j < pfacs.size(); j++) {
        if (todo[j] == -1) continue;
        long long i = todo[j];
        pfacs[j] = pfacs[j/i];
        pfacs[j].push_back(i);
    }
    return pfacs;
}

map<long long,long long> count(vector<long long> &countme) {
    map<long long,long long> ret;
    for (long long i = 0; i < countme.size(); i++) {
        auto f = ret.find(countme[i]);
        if (f == ret.end()) {
            ret.insert({countme[i],1});
        } else {
            ret[countme[i]]++;
        }
    }
    return ret;
}

long NPF(vector<long long> pflist) {
    map<long long,long long> p = count(pflist);

    long long num_facs = 1;
    for (auto c = p.begin(); c != p.end(); c++) {
        num_facs *= (c->second+1);
    }
    return num_facs - p.size();

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    //auto prm = gen_primes();
    auto pf = pfactors();

    long long Q; scanf("%lld",&Q);
    ostringstream ss;
    while (Q--) {
        long long i; scanf("%lld",&i);
        ss << NPF(pf[i]) << endl;
    }
    printf("%s", ss.str().c_str());
    return 0;
}