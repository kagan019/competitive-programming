#include <bits/stdc++.h>
using namespace std;

int main() {
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        vector<int> a(n);
        for (int &x : a) cin >> x;
        int zero = 0;
        int one = 0;
        int two = 0;
        vector<int*> rem{&zero,&one,&two};
        for (int x : a) {
            *(rem[x%3])++;
        }
        for (int from = 0; from < 3; from++) {
            if(from)
        }
        
    }
}