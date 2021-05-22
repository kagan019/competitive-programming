#include <bits/stdc++.h>
using namespace std;

pair<int,int> takebest2(vector<int> ss) { 
    make_heap(ss.begin(),ss.end());
    pop_heap(ss.begin(),ss.end());
    int one = ss.back();
    ss.pop_back();
    pop_heap(ss.begin(),ss.end());
    int two = ss.back();
    ss.pop_back();
    return {one,two};
}

int main() {
    cout << setprecision(2) << std::fixed;
    int T; cin >> T;
    for (int c = 1; c <= T; c++) {
        int N; int K;
        cin >> N >> K;
        vector<int> P(N);
        for (int &x : P) {
            cin >> x;
        }
        sort(P.begin(), P.end());
        int last = -1;
        vector<int> rr;

        for (int p : P){
            if (last != -1) {
                rr.push_back(p-last-1);
                push_heap(rr.begin(), rr.end());
            }
            last = p;

        }
        
        int back1 = -1;
        int back2 = -1;
        pop_heap(rr.begin(),rr.end());
        back1 = rr.back();
        rr.pop_back();

        if (rr.size()) {
            pop_heap(rr.begin(),rr.end());
            back2 = rr.back();
        }

        auto pr = takebest2({P.front()-1,K-P.back(),(back1+1)/2,(back2+1)/2});

        int W = max(back1, pr.first + pr.second );
        
        cout << "Case #" << c << ": " << (double)(W)/K << endl;
        
    }
}