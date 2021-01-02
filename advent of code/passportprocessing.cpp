#include <bits/stdc++.h>
using namespace std;

typedef map<string,string> passport;

int main() {
    string ln;
    vector<passport> pspts;
    string curpspt = "";
    long failsafe = 0;
    while (failsafe++ < 10000l) {
        getline(cin,ln);
        cout << ln;
        if (ln.compare("") == 0 || cin.bad()) {
            stringstream ss(curpspt);
            string kv;
            passport mp;
            while (ss >> kv) {
                cout << "oop" << endl;
                cout << kv << endl;
                int colon = kv.find(':');
                string key = kv.substr(0,colon);
                string value = kv.substr(colon +1,string::npos);
                mp.insert({key,value});
            }
            pspts.push_back(mp);
            curpspt = "";
            if (cin.bad()) break;
        } else {
            curpspt += ln;
        }
        cout << "wut" << endl;
    }
    cout << "done";

}