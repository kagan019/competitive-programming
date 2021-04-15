#include <bits/stdc++.h>
using namespace std;

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
            vector<vector<int>> itb{torotate.a,torotate.b,torotate.c};
            for (int i : itb[v]) {
                vector<vector<int>> itb2{a,b,c};
                for (int j : itb2[v]) {
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
    vector<int> startingpos2(charpos &with, int woff, charpos &other) {
        int n = a.size() + b.size() + c.size();
        vector<bool> avail(n);
        for (int i = 0; i < avail.size();i++)
            avail[i]=true;
        int rem = n;
        for(int v : {0,1,2}) {
            vector<vector<int>*> itb{&other.a,&other.b,&other.c};
            for (int i : *itb[v]) {
                vector<vector<int>*> itb3{&a,&b,&c};
                for (int j : *itb3[v]) {
                    rem -= (int)(avail[(j+n-i)%n]);
                    avail[(j+n-i)%n] = false;
                }
                if (rem == 0)
                    return vector<int>();
                vector<vector<int>*> itb2{&with.a,&with.b,&with.c};
                for (int j : *itb2[v]) {
                    rem -= (int)(avail[((j+ woff)%n+n-i)%n]);
                    avail[((j+ woff)%n+n-i)%n] = false;
                }
                if (rem == 0)
                    return vector<int>();
            } 
        }
        vector<int> here;
        for (int i = 0; i < avail.size(); i++) {
            if (avail[i]) here.push_back(i);
        }
        return here;
    };
};

int score(vector<int> s, int len) {
    assert(s.size()==3);
    for (int i = 0; i < 3; i++) {
        s[i] = (s[i] > (len+1)/2) ? -(len-s[i]) : s[i];
        s[i] = (s[i] < -(len+1)/2) ? len+s[i] : s[i];
    }
    return 
        abs(s[0]) + abs(s[1]) + abs(s[2]);
}

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

    //find the legal rotations of w2 to be different than w1
    vector<int> legalrotsa2 = a1.startingpos(a2);
    int smallest = -1;
    for (int rot1 : legalrotsa2) {
        //cout << "?" << rot1 << endl;
        //we find we cant get any better?
        // if (smallest >= 0 && smallest < rot1 && smallest < n-rot1)
        //     break; 

        //for each legal rotation, find the legal rotations of w3
        vector<int> legalrotsa3 = a1.startingpos2(a2,rot1,a3);
        
        for (int rot2 : legalrotsa3) {
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
            smallest = (smallest < 0) ? candidate : min(smallest,candidate);
            
        }
    }

    

    //output sum of turns by wheel
    cout << smallest;
}