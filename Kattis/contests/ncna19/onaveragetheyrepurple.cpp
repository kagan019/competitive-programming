#include <bits/stdc++.h>
using namespace std;

int main() {
    int N,M;
    cin >> N >> M;
    vector<vector<int>>adj(N+1,vector<int>());
    while(M--) {
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    deque<pair<int,int>> frontier;
    vector<int> visited(N+1,INT_MAX);
    frontier.push_front({1,0});
    while(frontier.size()) {
        auto b = frontier.back();
        int v = b.first;
        int dist = b.second;
        frontier.pop_back();
        if (dist >= visited[v])
            continue;
        visited[v] = dist;
        if (v == N)
            break;
        for(int nbr : adj[v]) {
            if (dist + 1 < visited[nbr])
                frontier.push_front({nbr,dist+1});
        }
    }

    cout << visited[N]-1;
}