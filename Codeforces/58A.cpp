#include <bits/stdc++.h>
using namespace std;

int main() {
    string hello = "hello";
    auto tofind = hello.begin();
    string word; cin >> word;
    auto lookingfrom = word.begin();
    while((lookingfrom = find(lookingfrom, word.end(), *tofind)) != word.end()) {
        lookingfrom++;
        tofind++;
        if (tofind == hello.end()) {
            cout << "YES";
            return 0;
        }
    }
    cout << "NO";
}