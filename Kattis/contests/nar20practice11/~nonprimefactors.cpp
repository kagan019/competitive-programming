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

vector<int> count_pfactors() {
    vector<int>pfacs(3000002,0); //ignore index 0,1
    for (long long i = 2; i < pfacs.size(); i++) {
        if (pfacs[i] != 0)
            continue;
        for (long long j = i+i; j < pfacs.size(); j += i) {
            pfacs[j]++;
        }
    }
    return pfacs;
}

vector<int> count_factors() {
    vector<map<int,int>> facs(3000002,map<int,int>()); //ignore index 0,1
    vector<bool>primes(3000002,true); //ignore index 0,1
    vector<vector<int>> treeadj(3000002, vector<int>());
    for (long long i = 2; i < facs.size(); i++) {
        if (!primes[i])
            continue;
        for (long long j = i*i; j < facs.size(); j += i) {
            primes[j] = false;
            treeadj[j/i].push_back(j);
        }
    }

    vector<bool> seen(3000002, false);
    for (int i = 0; i < treeadj.size(); i++) {
        if (!primes[i]) continue;
        vector<int> stack{i};
        
        while (stack.size()) {
            int v = stack.back(); stack.pop_back();            
            for (int nbr : treeadj[v]) {
                if (seen[nbr]) continue;
                seen[nbr] = true;
                facs[nbr] = facs[v];
                auto f = facs[nbr].find(nbr/v);
                if(f == facs[nbr].end()) {
                    facs[nbr].insert({nbr/v,1});
                } else {
                    facs[nbr][nbr/v]++;
                }
                stack.push_back(nbr);
            }
        }
    }


    auto cpf = count_pfactors();
    vector<int> ret(3000002);
    for (int i = 0; i < facs.size(); i++) {
        int prod = 1;
        for (auto &p : facs[i]) {
            prod *= (p.second+1);
        }
        ret[i] = prod - cpf[i];
    }
    return ret;
}

vector<vector<int>> pfactors() {
    vector<vector<int>>pfacs(3000002,vector<int>()); //ignore index 0,1
    vector<int> todo(3000002);
    vector<bool> primes(3000002,true);
    for (long long i = 2; i < pfacs.size(); i++) {
        if (!primes[i])
            continue; //not prime; has factors other than itself
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
    for (int i = 2; i < pfacs.size(); i++) {
        int j = todo[i];
        pfacs[j] = pfacs[j/i];
        pfacs[j].push_back(i);
    }

    return pfacs;
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

map<int,int> count(vector<int> &per) {
    map<int,int> ret;
    for (int i = 0; i < per.size(); i++) {
        auto f = ret.find(per[i]);
        if (f == ret.end()) {
            ret.insert({per[i],1});
        } else {
            ret[per[i]]++;
        }
    }
}

vector<int> NPF2(vector<vector<int>> primefactorsofeverynumber) {
    vector<int> ret(primefactorsofeverynumber.size());
    for (int i = 2; i < primefactorsofeverynumber.size(); i++) {
        map<int,int> p = count(primefactorsofeverynumber[i]);
        long long num_facs = 1;
        for (auto c = p.begin(); c != p.end(); c++) {
            num_facs *= (c->second+1);
        }
        ret[i] = num_facs-p.size();
    }
    return ret;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    //auto prm = gen_primes();
    auto nonprm = NPF2(pfactors());
    long long Q; scanf("%lld",&Q);
    ostringstream ss;
    while (Q--) {
        long long i; scanf("%lld",&i);
        ss << nonprm[i] << endl;
    }
    printf("%s", ss.str().c_str());
    return 0;
}