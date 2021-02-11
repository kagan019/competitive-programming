#include <bits/stdc++.h>
using namespace std;

bitset<366> make_bitset(pair<int,int> &p, int s) {
    bitset<366> ret;
    for (int i = p.first - s; i <= p.second-s; i++)
        ret.set(i);
    return ret;
}

int main() {
    int N;
    cin >> N;
    vector<pair<int,int>> ev(N);
    int minstart = 99999;
    for (int i = 0; i < ev.size(); i++) {
        int s,t; cin >> s >>t;
        ev[i] = make_pair(s,t);
        minstart = min(minstart,s);
    }
    bitset<366> a = make_bitset(ev[0],minstart);
    for (int i = 1 ;i < ev.size(); i++) {
        a |= make_bitset(ev[i],minstart);
    }
    cout << a.count();
}