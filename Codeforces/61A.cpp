#include <bits/stdc++.h>
using namespace std;

int main() {
    string a, b;
    cin >> a >> b;
    string o = (bitset<100>(a) ^ bitset<100>(b)).to_string();
    o = o.substr(o.size() - a.size());
    cout << o;

}