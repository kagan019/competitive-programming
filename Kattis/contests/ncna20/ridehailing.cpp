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
        q.pop_back();
        if (visited[here])
            continue;
        mtx[st][here] = cost;
        visited[here] = true;
        
        for (int i = 0; i < mtx[here].size();i++) {
            if (i == here)
                continue;
            if (mtx[here][i] < 0)
                continue;
            if (visited[i])
                continue;
            
            q.push_back({i,cost+mtx[here][i]});
            push_heap(q.begin(),q.end(), cmp);
        }
    }
}

void closure(vector<vector<int>> &mtx) {
    for (int i = 0; i < mtx.size();i++)
        dijkstra(mtx,i);

}

//from geekesforgeeks.org/maximum-bipartite-matching
bool bpm(vector<vector<int>> &bpGraph, int u, 
         vector<bool> &seen, vector<int> &matchR) 
{ 
    // Try every job one by one 
    for (int v = 0; v < bpGraph[0].size(); v++) 
    { 
        // If applicant u is interested in  
        // job v and v is not visited 
        if (bpGraph[u][v] && !seen[v]) 
        { 
            // Mark v as visited 
            seen[v] = true;  
  
            // If job 'v' is not assigned to an  
            // applicant OR previously assigned  
            // applicant for job v (which is matchR[v])  
            // has an alternate job available.  
            // Since v is marked as visited in  
            // the above line, matchR[v] in the following  
            // recursive call will not get job 'v' again 
            if (matchR[v] < 0 || bpm(bpGraph, matchR[v], 
                                     seen, matchR)) 
            { 
                matchR[v] = u; 
                return true; 
            } 
        } 
    } 
    return false; 
} 
  
// Returns maximum number 
// of matching from M to N 
int maxBPM(vector<vector<int>> &bpGraph) 
{ 
    const int N = bpGraph[0].size();
    // An array to keep track of the  
    // applicants assigned to jobs.  
    // The value of matchR[i] is the  
    // applicant number assigned to job i, 
    // the value -1 indicates nobody is 
    // assigned. 
    vector<int> matchR(N,-1);
  
    // Count of jobs assigned to applicants 
    int result = 0;  
    for (int u = 0; u < bpGraph.size(); u++) 
    { 
        // Mark all jobs as not seen  
        // for next applicant. 
        vector<bool> seen(N,0);
  
        // Find if the applicant 'u' can get a job 
        if (bpm(bpGraph, u, seen, matchR)) 
            result++; 
    } 
    return result; 
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
    
    vector<vector<int>> tripg(k,vector<int>(k, 0)); // directed acyclic
    //-1 source trip, -2 sink trip
    auto setm = [&tripg](int trip1,int trip2) { //trip2 can be reached after trip1
        assert(trip1 != -2); // should be terminal
        assert(trip2 != -1); //should be initial
        tripg[trip1][trip2] = 1;
    };    

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

    int matches = maxBPM(tripg);
    
    //transitively 'unclosed'. Now, every path between two vertexes calls for a unique driver 
    cout << k-matches;

}
