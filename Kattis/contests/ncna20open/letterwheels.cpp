#include <bits/stdc++.h>
using namespace std;

int score(vector<int> s, int len) {
    assert(s.size()==3);
    for (int i = 0; i < 3; i++) {
        s[i] = (s[i] > (len+1)/2) ? -(len-s[i]) : s[i];
        s[i] = (s[i] < -(len+1)/2) ? len+s[i] : s[i];
    }
    return 
        abs(s[0]) + abs(s[1]) + abs(s[2]);
}

int newsml(int smallest, int rot1, int rot2, int n) {
    //find the best origin for the rotations. this step
    // also converts right turns to left turns when optimal
    //printf("%d %d \n", rot1,rot2);
    int candidate = min(
        score(initializer_list<int>{0,rot1,rot2},n),
        min(
            score(initializer_list<int>{-rot1,0,rot2-rot1},n),
            score(initializer_list<int>{-rot2,rot1-rot2,0},n)
        )
    );
    return (smallest < 0) ? candidate : min(smallest,candidate);
}


struct charpos {
    vector<int> a;
    vector<int> b;
    vector<int> c;
    charpos(string &s) {
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == 'A') {
                a.push_back(i);
            } else if (s[i] == 'B') {
                b.push_back(i);
            } else if (s[i] == 'C') {
                c.push_back(i);
            }
        }
    };
    vector<int> startingpos(charpos &torotate){
        int n = a.size() + b.size() + c.size();
        vector<bool> avail(n); //places the first position cant go
        for (int i = 0; i < avail.size();i++)
            avail[i]=true;
        int rem = n;
        for (auto v : {0,1,2}) {
            vector<vector<int>*> itb{&torotate.a,&torotate.b,&torotate.c};
            for (int i : *itb[v]) {
                vector<vector<int>*> itb2{&a,&b,&c};
                for (int j : *itb2[v]) {
                    rem -= (int)(avail[(n+j-i)%n]);
                    avail[(n+j-i)%n] = false;
                    if (rem == 0)
                        return vector<int>();
                }
            }
        }
        vector<int> here;
        for (int i = 0; i < avail.size(); i++) {
            if (avail[i]) here.push_back(i);
        }
        return here;
    };
  
};



int main() {
    string w1; cin >> w1;
    string w2; cin >> w2;
    string w3; cin >> w3;
    const int n = w1.size();
    
    
    
    //preprocess so the positions of each character can be 
    // found in both strings
    auto a1 = charpos(w1);
    auto a2 = charpos(w2);
    auto a3 = charpos(w3);

    //find the legal rotations of w2,w3 
    vector<int> legalrotsa2 = a1.startingpos(a2);
    vector<int> legalrotsa3 = a1.startingpos(a3);
    vector<int> legalrotsa23 = a2.startingpos(a3);
    unordered_set<int>legal23(legalrotsa23.begin(),legalrotsa23.end());
    int smallest = -1;
    for (int rot1 : legalrotsa2) {
        for (int rot2 : legalrotsa3) {
            bool ok = legal23.find((rot2+n-rot1)%n) != legal23.end(); 
            if (ok)
                smallest = newsml(smallest,rot1,rot2,n);
        }
    }

    //output sum of turns by wheel
    cout << smallest;
}