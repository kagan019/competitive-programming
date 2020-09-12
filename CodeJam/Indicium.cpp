#include <bits/stdc++.h>
using namespace std;

int main() {
    int T; cin >> T;
    for (int cn = 1; cn <= T; cn++){
        int N, K;
        cin >> N >> K;
        
        vector<int> trace;
        int liln = (int)(1 + sqrt(1+4*(K-N)));
        int s = 0;
        for (int i = 1; i <= liln; i++){
        	s += i;
            trace.push_back(i);
        }
        int saveind = trace.size();
        if (trace.size() < N) {
        	
        	for (int i = trace.size(); i <= N; i++) {
        		trace.push_back(1);
        		s++;
        	}

        }
        assert (s <= K);
        assert ((s == K) ? saveind == trace.size() : saveind < trace.size());
    	while(s < K) {
    		trace[saveind]++;
    		s++;
    	}
        assert(s == K);

        // so now we have a trace of the form 
        	//(1, 2, 3, 4... some num, some other num between 1 and some num inc, 1, 1, 1, .... N times)

        vector<unordered_set<int>> posinrow(N+1); // ignore 0, from 1-N to a list of numbers 1-N
        for (int i = 0; i < N; i++){
        	posinrow[trace[i]].insert(i+1);
        }
        bool impossible = false;
        for (int i = 1; i < N;i++){
        	while (posinrow[i].size() < N){

        		int trypos = 1;
        		while ( posinrow[i].count(trypos) > 0) {
        			if (trypos == N + 1) {
        				impossible == true;
        				goto AFTER;
        			}
        			trypos += 1;
        		}
        		posinrow[i].insert(trypos);
        		
        	}
        }
AFTER:
		if (impossible) {
			cout << "Case #" << cn << ": IMPOSSIBLE" << "\n";
		}
		else {
			cout << "Case #" << cn << ": POSSIBLE" << "\n";

			vector<int> posinrow();
			for (int i = 0;)
		}


    }
    
}