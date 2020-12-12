#include <bits/stdc++.h>
using namespace std;

void showedges(int N, vector<vector<bool>> &horz, vector<vector<bool>> &ver) {
    //show
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N-1; j++) {
            cout << horz[i][j] << " ";
        }
        cout << endl;
        if (i == N-1) break;
        for (int j = 0; j < N; j++) {
            cout << ver[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int N; cin >> N;
    //true if edge between [i,j] and [i,j+1]
    vector<vector<bool>> horz(N,vector<bool>(N-1,false));
    //true if edge between [i,j] and [i+1,j]
    vector<vector<bool>> ver(N-1,vector<bool>(N,false));
    for (int i = 0; i < N-1; i++) {
        char c;
        for (int j = 0; j < N-1; j++) {
            //*- or *.
            cin >> c;
            assert(c == '*');
            cin >> c;
            if (c == '-') {
                horz[i][j] = true;
            }
        }
        //one more star
        cin >> c;
        assert(c == '*');
        for (int j = 0; j < N-1; j++) {
            //|. or ..
            cin >> c;
            if (c == '|') {
                ver[i][j] = true;
            }
            cin >> c;
            assert(c == '.');
        }
        //one more | or .
        cin >> c;
        if (c == '|') {
            ver[i][N-1] = true;
        }
    }
    char c;
    //one more horizontal
    for (int j = 0; j < N-1; j++) {
        //*- or *.
        cin >> c;
        assert(c == '*');
        cin >> c;
        if (c == '-') {
            horz[N-1][j] = true;
        }
    }

    
}