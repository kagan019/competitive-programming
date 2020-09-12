#include <bits/stdc++.h>
using namespace std;

long long nextt(long long &t, long long A, long long B, long long C){
    return (((A % C)*(t % C) % C) + (B % C)) % C + 1;
}

int main() {
    long long N, T;
    cin >> N >> T;
    long long A, B, C, t;
    cin >> A >> B >> C >> t;
    long long pen = 0;
    long long tsum = 0;
    vector<int> times(N);
    for (int i = 0; i<N; i++){
        times[i] = t;
        t = nextt(t, A, B, C);
    }
    sort(times.begin(),times.end());
    int n = 0;
    for (; n < N && tsum + times[n] <= T; n++){
        tsum += times[n] % 1000000007;
        tsum %= 1000000007;
        pen += tsum;
        pen %= 1000000007;
    }   
    cout << n << " " << pen;
    
}