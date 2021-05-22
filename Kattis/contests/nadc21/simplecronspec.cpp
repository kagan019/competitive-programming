#include <bits/stdc++.h>
using namespace std;

struct cronjob{
    unordered_map<int, unordered_map<int, unordered_set<int>>> t;
    cronjob() {
        t = unordered_map<int,unordered_map<int, unordered_set<int>>>();
    }
};

int starts(vector<cronjob> &js) { 
    int ss = 0;
    for (auto j : js) {
        for (auto s : j.t) {
            for (auto m : s.second) {
                ss += m.second.size();
            }
        }
    }
    return ss;
}
int seconds(vector<cronjob> &js) {
    
    unordered_set<int> ms;
    for (auto j : js) {
        for (auto s : j.t){
            ms.insert(s.first);
        }
    }

    return ms.size();
}

vector<int> times(string &te, int alli) {
    vector<int> all;
    if (te[0] == '*') {
        for (int i = 0; i < alli; i++) {
            all.push_back(i);
        }
        return all;
    }
    stringstream ss(te);
    string holder;
    while(getline(ss,holder,',')) {
        auto f = holder.find("-");
        if (f != string::npos) {
            int a1 = atoi(holder.substr(0,f).c_str());
            int a2 = atoi(holder.substr(holder.find("-")+1).c_str());
            for (int i = a1; i <= a2; i++) {
                all.push_back(i);
            }
        } else {
            all.push_back(atoi(holder.c_str()));
        }

    }
    return all;
}

unordered_set<int> parse(string &s) {
    stringstream ss(s);
    vector<string> timeexpr(3);
    for (string &t : timeexpr) {
        ss >> t;
    }

    //cronjob tt;
    unordered_set<int> timeset;
    for (int s : times(timeexpr[2], 60)) {
        for (int m : times(timeexpr[1], 60)) {
            for (int h : times(timeexpr[0], 24)) { 
                timeset.insert(s+m*60+h*60*60);

            }
        }
    }
    return timeset;

}

void union_(unordered_set<int> &me, unordered_set<int> &other) {
    for (int x : other) {
        me.insert(x);
    }
}

int main() {
    int n; cin>>n;
    string s0;
    getline(cin,s0);
    unordered_set<int> uniquetimes;
    int count = 0;
    while(n--) {
        string s; getline(cin, s);
        unordered_set<int> a =parse(s);
        union_(uniquetimes,a);
        count += a.size();
    }

     cout << uniquetimes.size() << " " << count;
}