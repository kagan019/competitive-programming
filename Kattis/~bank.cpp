#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, T;
    cin >> N >> T;
    vector<pair<int,int>> q(N, make_pair(0,0));
    for(auto &x : q){
        int a, b;
        cin >> a >> b;
        x = make_pair(a,b);
    }
    sort(q.begin(),q.end(),[](auto a, auto b){ return a.second < b.second;});
    long long sum = 0;
    int t = 0;
    for(auto &x : q){
        if (t > T) break;
        if (x.second >= t) {
            t++;
            sum += x.first;
        }
        
    }
    cout << sum;
}