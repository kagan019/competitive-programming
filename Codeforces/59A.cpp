#include <bits/stdc++.h>
using namespace std;

int main() {
    string word; cin >> word;
    int u = 0;
    for (char &c : word) {
        if (isupper(c)) {
            u++;
        }
    }
    if (word.size() - u >= u) {
        for (char &c : word) {
            c = tolower(c);
        }
    }
    else {
        for (char &c : word) {
            c = toupper(c);
        }
    }
    cout << word;
}