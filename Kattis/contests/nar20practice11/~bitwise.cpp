#include <bits/stdc++.h>
using namespace std;

int vand(vector<int>::iterator begin, vector<int>::iterator end) {
    if (begin == end)
        return -1;
    int u = *begin;
    for (auto i = next(begin); i != end; i++) {
        u &= *i;
    }
    return u;
}

int vor(vector<int>::iterator begin, vector<int>::iterator end) {
    if (begin==end)
        return 0;
    int u = *begin;
    for (auto i = next(begin); i != end; i++) {
        u |= *i;
    }
    return u;
}

int compress(vector<vector<int>> &A) {
    int u = vor(A[0].begin(),A[0].end());
    for (int i = 1; i < A.size(); i++) {
        u &= vor(A[i].begin(), A[i].end());
    }
    return u;
}

void redux(vector<vector<int>> &A) {
    const int n = A.size();
    int minpos = 0; //0 -> n-1 (just behind index)
    for (int tryme = 0; tryme < A.size(); tryme++) {
        int rslt = A[tryme] | A[(tryme+n-1) % n] & andcache[tryme]
        if (rslt)
    }

    int t = A[minpos];
    A.erase(A.begin()+minpos,A.begin()+minpos+1);
    A[(minpos + n - 1) % n] |= t;
}

int main() {
    int N, K;
    vector<vector<int>> A(K,vector<int>(N));
    for (int &x : A[0])
        cin >> x;
    

    while (A.size() > K)
        redux(A);
    return compress(A);
}