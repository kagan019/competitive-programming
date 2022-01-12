#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000000+7

int main() {
    int n; cin >> n;
    vector<int> s(n);
    for (int &x : s) {
        cin >> x;
    }
    vector<int> twosbythrees;
    int power = 0;
    int total = 0;
    int threes = 0;
    for (int i = s.size()-1; i>= 0; i--) {
        if (s[i] == 3) { /*twosbythrees.push_back(0);*/ power++; threes++;}
        if (s[i] == 2) {
//             for (int k = 0; k < twosbythrees.size(); k++) {
//                 twosbythrees[k]++;
//             }
            power <<= 1;
            power %= MOD;

        }
        if (s[i] == 1) {
//             for (int k = 0; k < twosbythrees.size(); k++) {
//                total += ((1 << twosbythrees[k]) - 1);
//             }
            total += power - threes;
            total %= MOD;
        }
    }

    //todo: modulo
    cout << total;
    cout << endl;
}
