#include <bits/stdc++.h>
using namespace std;

int main() {
    string dubstep; cin >> dubstep;
    const string wub = "WUB";
    string original = "";
    int s = 0;
    int f;
    while((f = dubstep.find(wub, s)) != string::npos) {
        if (f > s) {
            string ss = dubstep.substr(s, f-s);
            if (ss != wub)
                original += ss + " ";
        }
        s = f + wub.size();
    }
    if (dubstep.size() > s) {
        string ss = dubstep.substr(s, dubstep.size());
        if (ss != wub)
            original += ss + " ";
    }
    cout << original;

}