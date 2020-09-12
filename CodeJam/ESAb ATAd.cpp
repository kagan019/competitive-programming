#include <bits/stdc++.h>
using namespace std;

int query(int bitpos){
    cout << bitpos << endl;
    int result; cin >> result;
    return result;
}

bool answer(bitset<100> bits){
    cout << bits << endl;
    char result; cin >> result;
    return result == 'Y';
}

int main() {
    int T; cin >> T;
    int B; cin >> B;
    cerr << query(1);
    bool correct = answer(bitset<100>(0b1001100110));
    return 0;
}