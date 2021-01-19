#include <bits/stdc++.h>
using namespace std;

typedef map<string,string> passport;

int stoi(string &s, string::size_type *sz) {
    *sz = 0;
    int ret = 0;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] - '0' <= 9) {
            *sz += 1;
            ret *= 10;
            ret += (s[i] - '0');
        } else {
            return ret;
        }

    }
    return ret;
}

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
        vector<string> keys = {"ecl", "pid", "eyr", "hcl", "byr", "iyr", "hgt"};
        
        vector<bool (*)(string&)> verify = {
            [](string& s) { // ecl
                set<string> ss = {
                    "amb","blu","brn","gry","grn","hzl","oth"
                };
                return ss.find(s) != ss.end();
            },
            [](string& s ) { // pid
                string::size_type sz;
                int v = stoi(s,&sz);
                return v >= 0 && sz == s.size() && sz == 9;
            },
            [](string& s) { // eyr
                string::size_type sz;
                int v = stoi(s,&sz);
                return 2020 <= v && v <= 2030 && sz == 4 && sz == s.size();
            },
            [](string& s) { // hcl
                bool sz = s.size() == 7;
                if (!sz) return false;
                bool one = s[0] == '#';
                set<char> a{
                    '0','1','2','3','4','5','6','7','8','9',
                    'a','b','c','d','e','f'
                };
                for(int i = 1; i < s.size(); i++) {
                    if (a.find(s[i]) == a.end())
                        return false;
                } 
                return one;
            },
            [](string& s) { // byr
                string::size_type sz;
                int v = stoi(s, &sz);
                return 1920 <= v && v <= 2002 && sz == 4 && sz == s.size();
            },
            [](string& s) { // iyr
                string::size_type sz;
                int v = stoi(s, &sz);
                return 2010  <= v && v <= 2020 && sz == 4 && sz == s.size();
            },
            [](string& s) { // hgt
                string::size_type sz;
                int v = stoi(s, &sz);
                string rem = s.substr(sz);
                if (rem.compare("cm") == 0) {
                    return 150 <= v && v <= 193;
                } else if (rem.compare("in") == 0) {
                    return 59 <= v && v <= 76;
                } else {
                    return false;
                }
            },
        };
        for (int i = 0; i < keys.size(); i++) {
            auto fnd = ppt.find(keys[i]);
            if (fnd == ppt.end() || !((verify[i])(fnd->second))) {
                invalid++;
                flg = true;
                break;
            }
        }
        cout << ((flg) ? "invalid" : "valid") << endl;
    }
    cout << pspts.size() - invalid;
}