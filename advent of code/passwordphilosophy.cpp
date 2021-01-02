#include <bits/stdc++.h>
using namespace std;

bool valid(int l, int h, char c, vector<char> &p) {
    int count = 0;
    for (char x : p) {
        if (c == x) {
            count += 1;
            if (count > h) {
                return false;
            }
        }
    }
    return l <= count;
}

int main() {
    int numval = 0;
    string ln;
    while (getline(cin, ln)) {
        vector<char> low;
        vector<char> high;
        char cond;
        vector<char> pswd;
        int sel = 0;
        for(char next : ln) {
            if (next == ':')
                continue;
            if (next == '-' || next == ' ') {
                sel++;
                continue;
            }
            switch(sel) {
                case 0:
                    low.push_back(next);
                break;
                case 1:
                    high.push_back(next);
                break;
                case 2:
                    cond = next;
                break;
                case 3:
                    pswd.push_back(next);
                default:
                break;
            }
        }
        string low2(low.begin(),low.end());
        int l = stoi(low2);
        string high2(high.begin(),high.end());
        int h = stoi(high2);

        if (valid(l, h, cond, pswd))
            numval++;
    }
    cout << numval;
}