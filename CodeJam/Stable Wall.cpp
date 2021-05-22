#include <bits/stdc++.h>
using namespace std;

vector<bool> visited;
vector<bool> visiting; // for detecting cycles
vector<char> ordering;

bool dfs(char c, unordered_map<char,unordered_set<char>> &graph) {
    assert(visited[c-'A'] == false);
    if (visiting[c-'A']) {
        //cycle!
        return true;
    }
    visiting[c-'A'] = true;
    for (char nbr : graph[c]) {
        if (!visited[nbr-'A']) {
            bool cycles = dfs(nbr,graph);
            if (cycles)
                return true;
        } 
    }
    ordering.push_back(c);
    visiting[c-'A'] = false;
    visited[c-'A'] = true;
    return false;
}

vector<char> solve(vector<vector<char>> &wall) {
    unordered_map<char,unordered_set<char>> prior;
    for (int r = 0; r < wall.size(); r++) {
        for (int c = 0; c < wall[0].size(); c++) {
            if (prior.find(wall[r][c]) == prior.end()) {
                prior.emplace(wall[r][c],initializer_list<char>{});
            }
            if (r > 0 && wall[r-1][c] != wall[r][c]) {
                prior[wall[r][c]].insert(wall[r-1][c]);
            }
        } 
    }

    visited = vector<bool>(26, false);
    visiting = vector<bool>(26, false);
    ordering = vector<char>();
    for (auto &p : prior) {
        if (visited[p.first-'A']) 
            continue;
        bool cycles = dfs(p.first, prior);
        if (cycles)
            return vector<char>();
    }
    reverse(ordering.begin(),ordering.end());
    return ordering;


}

int main() {
    int T; cin >> T;
    for (int x = 0; x < T; x++) {
        int R; int C;
        cin >> R >> C;
        vector<vector<char>> wall(R,vector<char>(C));
        for (vector<char> &vv : wall) {
            for (char &c : vv) {
                cin >> c;
            }
        }
        vector<char> sol = solve(wall);
        string y(sol.begin(),sol.end());
        cout << "Case #" << (x+1) << ": " << ((y.size()) ? y : "-1") << endl;
    }
}
