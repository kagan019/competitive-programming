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
        if (ln.compare("") == 0 || cin.eof()) {
            curpspt += " ";
            curpspt += ln;
            stringstream ss(curpspt);
            string kv;
            passport mp;
            while (ss >> kv) {
                int colon = kv.find(':');
                string key = kv.substr(0,colon);
                string value = kv.substr(colon +1,string::npos);
                mp.insert({key,value});
            }
            pspts.push_back(mp);
            curpspt = "";
            if (cin.eof()) {
                cout << "done" << endl;
                break;
            }
        } else {
            curpspt += " ";
            curpspt += ln;
        }
    }
    
    int invalid = 0;
    for (auto& ppt : pspts) {
        for (auto&p : ppt) {
            cout << p.first << " ";
        }
        cout << ":: ";
        bool flg = false;
        for (auto& check : {"ecl", "pid", "eyr", "hcl", "byr", "iyr", "hgt"}) {
            if (ppt.find(check) == ppt.end()) {
                invalid++;
                flg = true;
                break;
            }
        }
        cout << ((flg) ? "invalid" : "valid") << endl;
    }
    cout << pspts.size() - invalid;
}