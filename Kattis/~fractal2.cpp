#include <bits/stdc++.h>
using namespace std;

float sdist(int dx, int dy) {
    return dx*dx + dy*dy;
}

pair<float,float> interpolate(float dist, pair<int,int> &a, pair<int,int> &b) {
    //a + dist/|b-a| * (b-a)
    float len = sqrt(sdist(b.first-a.first,b.second-a.second));
    pair<float,float> unit = {(b.first-a.first) / len, (b.second-a.second)/len};
    return {a.first + unit.first * dist, a.second + unit.second * dist};
}

int main() {
    int c; cin >> c;
    while(c--) {
        int n; cin >> n;
        vector<pair<int,int>> points(n);
        vector<float> distances;
        int i = 0;
        for (auto &p : points) {
            float x; float y;
            cin >> x >> y;
            p = make_pair(x,y);
            if (i > 0) {
                int dx = x - points[i-1].first;
                int dy = y - points[i-1].second;
                dis3tances.push_back(sqrt(sdist(dx,dy)));
            }
            i++;
        }
        int d; cin >> d;
        int f; cin >> f;
        vector<float> distsums;
        float totald = 0;
        for (float dd : distances) {
            totald += dd;
            distsums.push_back(totald);
        }

        double partialdist = f * totald;
        int part = 0;
        pair<float,float> origin = make_pair(0,0);
        float theta = 0;
        
        while(n--) {
            part = upper_bound(distsums.begin(),distsums.end(), partialdist) - distsums.begin();
            f = (partialdist - distsums[part]) / distances[part];
            partialdist = f * totald;
            auto q = points[part];
            auto p = points[part+1];
            auto qt = transf(q,origin,theta);
            auto pt = transf(p,origin,theta);
            theta += atan2(p.second-q.second,p.first-q.first);
        }
        pair<float,float> itp = interpolate(partialdist,points[part],points[part+1]);
        cout << itp.first << " " << itp.second << endl;

    }
}