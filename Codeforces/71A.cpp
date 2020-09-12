#include <bits/stdc++.h>
using namespace std;

string abrv(string& w) {
    int t = w.size() - 2;
    string r = w[0] + to_string(t) + w[w.size() - 1];
    return r;
}

int main(){
    int n; cin >> n;
    while (n > 0) {
        string w; cin >> w;
        cout << ((w.size() <= 10) ? w : abrv(w))<< "\n";
        n--;
    }
}