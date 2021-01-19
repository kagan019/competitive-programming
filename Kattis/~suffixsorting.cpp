#include <bits/stdc++.h>
using namespace std;

typedef int ind;
int main() {
    string s;
    while (!(getline(cin,s).eof())) {
        string numbers;
        getline(cin,numbers);
        stringstream ns (numbers);
        int n; ns >> n;
        vector<int> qi(n);
        for (int &x : qi) {ns >> x;}
    
        vector<vector<ind>> si(256,vector<ind>());
        for (int i = s.size()-1;i >= 0; i--) {
            char c = s[i];
            si[(int)c].push_back(i);
        }
        unordered_map<int,ind> q2p;
        vector<int> q2(qi.begin(),qi.end());
        sort(q2.begin(),q2.end());
        ind i = 0, j = 0;
        ind nextq = 0;
        int ctr = 0;
        while(i < 256) {
            if (nextq >= q2.size())
                break;
            if (j >= si[i].size()) {
                j = 0; i++;
            } else {
                if (ctr == q2[nextq]) {
                    q2p[ctr] = si[i][si[i].size() - j-1];
                    nextq++;
                }
                j++;
                ctr++;
            }
        }

        for (int u = 0; u < qi.size(); u++) {
            cout << q2p[qi[u]] << " ";
        }
        cout << endl;
    }
}

// int main() {
//     string s;
//     while (!(getline(cin,s).eof())) {
//         string numbers;
//         getline(cin,numbers);
//         stringstream ns (numbers);
//         int n; ns >> n;
//         vector<int> qi(n);
//         for (int &x : qi) {ns >> x;}

//         vector<pair<string,int>> suffixes;
//         for (int i = 0; i < s.size()-1; i++) {
//             suffixes.push_back({string(s.begin()+i,s.end()),i});
//         }
//         sort(suffixes.begin(),suffixes.end(), [](auto &a, auto &b){
//             return a.first.compare(b.first) < 0;
//         });
//         for (int &j : qi) {
//             cout << suffixes[j].second << " ";
//         }
//         cout << endl;
//     }
// }