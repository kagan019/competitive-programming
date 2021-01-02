#include <bits/stdc++.h>
using namespace std;

int main() {
    string ln;
    int valid = 0;
    while(getline(cin,ln)) {
        int state = 0;
        string st, ed;
        char c;
        string pswd;
        for (int i = 0; i < ln.size(); i++) {
            if (ln[i] == ':') continue;
            if (ln[i] == '-' || ln[i] == ' ') {
                state++;
                continue;
            }
            switch(state){
                case 0:
                    st.push_back(ln[i]);
                break;
                case 1:
                    ed.push_back(ln[i]);
                break;
                case 2:
                    c = ln[i];
                break;
                default:
                    pswd.push_back(ln[i]);
            }
        }

        int spos = stoi(st) - 1;
        int epos = stoi(ed)-1;

        if ((pswd[spos] == c) ^ (pswd[epos] == c)) {
            cout << ln << " (valid)" << endl;
            valid++;
        } else
        cout << ln << " (invalid)" << endl;
    }
    cout << valid << endl;
}