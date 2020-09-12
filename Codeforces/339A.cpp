#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> unsorted;
    string k; getline(cin, k);
    for (int i = 0; i < k.size(); i += 2) {
        unsorted.push_back((int)(k[i] - '0'));
    }
    // counting sort
    int cnt[] {0, 0, 0, 0};
    for (int &i : unsorted) {
        cnt[(int)i]++;
    }
    vector<int> sorted;
    for (int i = 1; i < 4; i++) {
        int t = cnt[i];
        while(t--) {
            sorted.push_back((int)i);
        }
    }
    for (int i = 0; i < sorted.size() - 1; i++) {
        cout.put((char)sorted[i] + '0');
        cout.put('+');
    }
    cout.put((char)(sorted.back()) + '0');
}