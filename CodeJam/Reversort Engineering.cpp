#include <bits/stdc++.h>
using namespace std;

int reversortcost(vector<int> &L) {
    int s = 0;
    for (int i = 0; i < L.size()-1; i++) {
        auto findmin = min_element(L.begin()+i,L.end());
        s += findmin - (L.begin() + i)+1;
        reverse(L.begin()+i,findmin+1);
    }
    return s;
}

vector<int> engineer(int N, int C) {
    vector<int> s;
    for (int i = 1; i <= N; i++) {
        s.push_back(i);
    }

    C -= N-1;
    int i = N-1;
    int j = 0;
    bool forward = true;
    while(i != j) {
        if (C >= i-j) {
            C -= i-j;
            reverse(s.begin()+j,s.begin()+i+1);
            forward = !forward;
        }
        if (forward)
            j++;
        else
            i--;
    }
    return (C == 0) ? s : vector<int>();
}
void test();

int main() {
    int T; cin >> T;
    for(int cs = 0; cs < T; cs++) {
        int N; cin >> N;
        int C; cin >> C;
        // if (N-1 > C || N*(N+1)/2-1 < C) {
        //     cout << "Case #" << (cs+1) << ": IMPOSSIBLE" << endl;
        //     continue;
        // }
        vector<int> rev = engineer(N,C);
        if (rev.size() != N) {
            cout << "Case #" << (cs+1) << ": IMPOSSIBLE" << endl;
            continue;
        }
        cout << "Case #" << (cs+1) << ": ";
        for (int y : rev) {
            cout << y << " ";
        }
        //cout << "(" << reversortcost(rev) << ")";
        cout << endl;
       
    }
    test();
}

void test() {
    for(int C = 1; C <= 1000; C++) {
        for (int N = 2; N <= 7; N++) {
            if (N-1 > C || N*(N+1)/2-1 < C) {
                //cout << "Case #" << (cs+1) << ": IMPOSSIBLE" << endl;
                continue;
            }
            vector<int> rev = engineer(N,C);
            if (rev.size() != N) {
                //cout << "Case #" << (cs+1) << ": IMPOSSIBLE" << endl;
                continue;
            }
            //cout << "Case #" << (cs+1) << ": ";
            // for (int y : rev) {
            //     cout << y << " ";
            // }
            vector<int> rev2(rev.begin(),rev.end());
            if ( reversortcost(rev2) != C) {
                cout << N << " " << C << endl;
                for (int y : rev) {
                    cout << y << " ";
                } 
                cout << endl;
            }
            
        }
       
    }
}