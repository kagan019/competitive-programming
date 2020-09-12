#include <bits/stdc++.h>
using namespace std;


int distinct;
void color(int anim_ind, unordered_map<int,unordered_set<int>> &assoc, unordered_map<int,int> &c){
    if (c.find(anim_ind) != c.end()) {
        return;
    } 

    int mex = 1;
    vector<int> s;
    unordered_set<int>::iterator b;
    const auto e = assoc[anim_ind].end();
    bool changed = true;
    while (changed) { //lazy slow mex function (faster with a set nlogn)
        b = assoc[anim_ind].begin();   
        changed = false;
        while (b != e) {
            if (c.find(*b) == c.end()) {
                s.push_back(*b);
            } else if (c[*b] == mex) {
                mex++;
                changed = true;
            } 
            b++;
        }
    }
    distinct = max(distinct, mex);
    c[anim_ind] = mex;

    for (int &i : s) {
        color(i, assoc, c);
    }
}

void assoc_insert(unordered_map<int,unordered_set<int>> &assoc, int k, int val) {
    auto f = assoc.find(k);
    if (f == assoc.end()) {
        unordered_set<int> g({val});
        assoc.insert(make_pair(k, g));
    }
    else {
        f->second.insert(val);
    }
}



int main() {
    int q; cin >> q;
    while (q--){
        distinct = 0;
        int n; cin >> n;
        vector<int> t(n);
        for (int &k : t) cin >> k;
        
        //assoc: animal -> set of animals adj to it
        unordered_map<int,set<int>> assoc;
        for (int i = 0; i < t.size(); i++) {
            int downidx = (t.size() + i - 1) % t.size();
            int upidx = (t.size() + i + 1) % t.size();
            if (t[downidx] != t[i]) {
                assoc_insert(assoc, t[i], t[downidx]);
                assoc_insert(assoc, t[downidx], t[i]);
            }
            if (t[upidx] != t[i]) {
                assoc_insert(assoc, t[i], t[upidx]);
                assoc_insert( assoc, t[upidx], t[i]);
            }
        }

        vector<set<int>> ls; //anims fw all anim in a set touch all other anims in the set
        unordered_map<int, int> c; //anim->color
        distinct = 0;
        //color(t[0], assoc, c);
        for (int i = 0; i < t.size(); i++) {
            int curan = t[i];
            queue<set<int>> q; //queue of animals whose `assoc` sets have relationship to curan
            for (auto &p : assoc) {
                set<int> su(assoc(p->first).begin());
                set_union(p->first.begin(), p->first.end(), assoc[p->second].begin(), assoc[p->second].end(), su.begin());
                if (su.size())
                    q.push_back(su);
            }
        }

        cout << distinct << "\n";
        for (auto &anim : t)
            cout << c[anim] << " ";
        cout << endl;
    }
}