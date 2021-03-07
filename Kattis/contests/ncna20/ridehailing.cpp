#include <bits/stdc++.h>
using namespace std;

void dijkstra(vector<vector<int>> &mtx, int st) {
    //shortest path from st to each other node
    vector<pair<int,int>> q{{st,0}};
    auto cmp = [&mtx](pair<int,int> &a, pair<int,int> &b) {
        return a.second > b.second; //min heap
    };
    vector<bool> visited(mtx.size(),false);
    while(q.size()) {
        pop_heap(q.begin(),q.end(),cmp);
        auto at = q.back();
        int here = at.first;
        int cost = at.second;
        mtx[st][here] = cost;
        q.pop_back();
        visited[here] = true;
        
        for (int i = 0; i < mtx[here].size();i++) {
            if (i == here)
                continue;
            if (mtx[here][i] < 0)
                continue;
            if (visited[i])
                continue;
            
            q.push_back({i,mtx[i][here]+mtx[here][i]});
            push_heap(q.begin(),q.end(), cmp);
        }
    }
}

void closure(vector<vector<int>> &mtx) {
    for (int i = 0; i < mtx.size();i++)
        dijkstra(mtx,i);

}

void merge_subpaths(vector<unordered_set<int>> &sp) {
    
}

unordered_map<int,int> cache;
int drivers(vector<unordered_set<int>> &tripg, int v) {
    if (v == -2)
        return 1;
    auto f = cache.find(v);
    if (f != cache.end())
        return f->second;
    int ss = 0;
    for (int nbr : tripg[v+2])
        ss += drivers(tripg,nbr);
    cache[v] = ss;
    return ss;
}

struct Trip{
    int s; int e;
    int t;
    int id;
};

int main() {
    int n; int m; int k;
    cin >> n >> m >> k;
    vector<vector<int>> adj(n, vector<int>(n,-1));
    for (int i = 0; i < m; i++) {
        int u; int v; int w;
        cin >> u >> v >> w;
        adj[u-1][v-1] = w;
    }
    vector<vector<Trip>> trips(480,vector<Trip>());
    for (int i = 0; i < k; i++) {
        int u; int v; int t;
        cin >> u >> v >> t;
        trips[t].push_back({u-1,v-1,t,i});
    }
    closure(adj);
    
    vector<unordered_set<int>> tripg(k+2,unordered_set<int>()); // directed acyclic
    //-1 source trip, -2 sink trip
    auto dropm = [&tripg](int trip1, int trip2) {
        tripg[trip1+2].erase(trip2);
    };
    auto setm = [&tripg](int trip1,int trip2) { //trip2 can be reached after trip1
        assert(trip1 != -2); // should be terminal
        assert(trip2 != -1); //should be initial
        tripg[trip1+2].insert(trip2);
    };    
    for (int i = 0; i < k; i++) {
        setm(-1,i);
        setm(i,-2);
    }

    for (int t1 = 0; t1 < trips.size()-1; t1++) {
        for (const auto &p : trips[t1]) {
            for (int t2  = t1+1; t2 < trips.size();t2++) {
                for (const auto &p2 : trips[t2]) {
                    int endt = t1+adj[p.s][p.e];
                    int ETA = endt+adj[p.e][p2.s];
                    if (ETA <= t2)
                        setm(p.id,p2.id);
                }
            } 
        }
    }
    // the graph is a strict order (no cycles, every vertex has a 
    // path to it from the source and from it to the sink)

    merge_subpaths(tripg);
    
    //transitively 'unclosed'. Now, every path between two vertexes calls for a unique driver 
    cout << drivers(tripg,-1);

}
