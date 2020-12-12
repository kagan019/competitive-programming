 #include <bits/stdc++.h>
 using namespace std;

int gcf(int a,int b) {
    if (a > b) return gcf(a,b);
    if (b % a == 0) return a;
    return gcf(b% a, a);
}

vector<int> shortest(vector<vector<int>> &g, int s, int t) {
    if (s == t) {
        return vector<int>{s};
    } 
    deque<int> q;
    q.push_back(s);
    vector<int> path;
    vector<bool> visited(g.size());
    while(q.size()) {
        int vd = q.front();
        q.pop_front();
        path.push_back(vd);
        visited[vd] = true;
        vector<int> nbr;
        for (int i = 0; i < g[vd].size(); i++) {
            if (g[vd][i] > 0)
                nbr.push_back(i);
        }
        sort(nbr.begin(),nbr.end(), [&g, vd](int a, int b){ return g[vd][a] < g[vd][b]; });
        for (int &i : nbr) {
            q.push_back(i);
        }
    }

    return path;

}

int main() {
    int n; cin >> n;
    vector<vector<int>> g(n, vector<int>(n,0));
    vector<int> nums(n);
    int sk = 1001;
    int s = -1;
    int ek = 0;
    int e = -1;
    for (int i = 0; i < n; i++) {
        int k; cin >> k;
        if (k < sk) {
            s = i;
            sk = k;
        }
        if (k > ek) {
            e = i;
            ek = k;
        }
        nums.push_back(k);
    }
    
    //fill g with gcds
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i != j) {
                int c = gcf(nums[i],nums[j]);
                if (c == 1)
                    continue;
                g[i][j] = c;
                g[j][i] = c;
            }
        }
    }

    vector<int> p = shortest(g, s,e);
    int ss = 0;
    while(p.size()) {
        int f = 1000000001;
        for (int i = 0; i < p.size()-1; i++) {
            f = min(f,g[p[i]][p[i+1]]);
        }
        for (int i = 0; i < p.size()-1; i++) {
            g[p[i]][p[i+1]] -= f;
            g[p[i+1]][p[i]] += f;
        }
        ss += f;
        p = shortest(g,s,e);
    }
    cout << ss << endl;
}
