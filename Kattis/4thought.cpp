#include <bits/stdc++.h>
using namespace std;



char ops[] = {'+','-','*','/'};

string atos(vector<int> &a, int n) {
    stringstream ss; ss << "4";
    for (int op : a) {
        ss << " " << ops[op] << " 4";
    }
    ss << " = " << n;
    return ss.str();
}

int op(int ak, int a, int b) {
    if (ak == 0) {
        return a+b;
    }
    if (ak == 1) {
        return a-b;
    }
    if (ak == 2) {
        return a*b;
    }
    if (ak == 3) {
        return a/b;
    }
    return 0;
}

int eval(vector<int> a) {
    vector<int> s{4,4,4,4};
    bool ff = true;
    while(s.size() > 1) {
        int i = 0;
        if (ff) {
            for (int k : a) {
                if (k >= 2) {
                    s[i] = op(k,s[i],s[i+1]);
                    s.erase(s.begin() + i+1);
                    a.erase(a.begin()+i);
                    break;
                }
                i++;
            }
            if(i == a.size())
                ff = false;
        }
        else {
            s[0] = op(a[0],s[0],s[0+1]);
            s.erase(s.begin() + 0+1);
            a.erase(a.begin()+0);
        }
    }
    
    return s[0];
    
}

void ctoa(unsigned long c, vector<int> &a) {
    a.clear(); a.resize(0);
    for (int i = 0; i < 3; i++) {
        a.push_back(c & 3); 
        c >>= 2;
    }
}

bool filla(vector<int> &a, int n) {
    int c = 0;
    
    while (c < (1 << 6)) {
        ctoa(c,a);
        int k = eval(a);
        if (k == n) {
            return true;
        }
        c++;        
    }
    return false;
}

unordered_map<int, int> mm; 
void fillmap(vector<int> &a) {
    int c = 0;
    
    while (c < (1 << 6)) {
        ctoa(c,a);
        int k = eval(a);
        mm[k] = c;
        c++;        
    }
}

int main() {

    int m; cin >> m;
    vector<int> aa; fillmap(aa);
    while(m--) {
        int n; cin >> n;
        auto k = mm.find(n);
        if (k == mm.end()) { //not found
            cout << "no solution";
        } else {
            // output string rep
            vector<int> a; ctoa(k->second, a);
            cout << atos(a, n);
        }
        cout << endl;
    }
    return 0;
}

// int main2() {

//     int m; cin >> m;
//     while(m--) {
//         int n; cin >> n;
//         vector<int> a;
//         if (!filla(a,n)) {
//             cout << "no solution";
//         } else {
//             stringstream ss; ss << "4";
//             for (int op : a) {
//                 ss << " " << ops[op] << " 4";
//             }
//             ss << " = " << n;
//             cout << ss.str();
//         }
        
//         cout << endl;
//     }
//     return 0;
// }