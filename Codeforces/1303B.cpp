#include<bits/stdc++.h>
using namespace std;

int main() {
    int t; cin >> t;
    while(t--){
        long long n, g, b;
        cin >> n >> g >> b;
        long long ming = (n+1LL)/2LL;
        long long daysneededforming = (g+b)*((ming+g-1LL)/g -1LL);
        daysneededforming += ming && ming % g == 0 ? g : ming%g;
        long long daysneededtofinish = max(0LL,n-daysneededforming);
        cout << (daysneededforming+daysneededtofinish) << "\n"; 
    }
}