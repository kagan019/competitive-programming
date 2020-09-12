#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    bool hate = true;
    string feelings = "I hate ";
    n--;
    while(n--) {
        hate = !hate;
        feelings += "that I ";
        feelings.append(hate ? "hate " : "love "); 
        
    }
    feelings += "it";
    cout << feelings;
}