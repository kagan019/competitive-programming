#include <bits/stdc++.h>
using namespace std;

int main() {
    string ln;
    int width = 0;
    int numlns = 0;
    vector<set<int>> ds;
    while (getline(cin,ln)) {
        numlns++;
        if (width == 0)
            width = ln.size();
        else
            assert(width == ln.size());
        
        set<int> k;
        for (int j = 0; j < width; j++) {
            if (ln[j] == '#') {
                k.insert(j);
            }
        }
        ds.push_back(k);
    }

    auto collide = [&ds](int i, int j) {
        return ds[i].find(j) != ds[i].end();
    };

    int dx = 3;
    int dy = 1;
    int i = 0;
    int j = 0;
    int count = 0;
    while(i < numlns) {
        j %= width;
        if (collide(i,j)) {
            count++;
        }

        i += dy;
        j += dx;

    }
    cout << count << endl;
}