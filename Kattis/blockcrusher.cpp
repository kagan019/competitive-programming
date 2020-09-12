#include <bits/stdc++.h>
using namespace std;

struct Pos {
	int r, c;
	int ss;
	int last;
};


pair<int,int> dirs[8] = {{-1,-1},{-1,0},{-1,1},
                         {0,-1},        {0,1},
                         {1,-1}, {1,0}, {1,1}};

int main() {
	int t = 200;
	while(t--) {
		int h, w;
		cin >> h >> w;
		if (h == 0 )
			break;
		vector<vector<int>> block(h+1,vector<int>(w));
		for (int i =0; i < h; i++) {	
			string s; cin >> s;
			for (int j = 0; j < w; j++) {
				block[i][j] = s[j]-'0';
			}
		}
		for (int j = 0; j < w; j++) {
			block[h][j] = 0;
		}
		
		vector<vector<int>> visited(h+1,vector<int>(w));
		for (int i = 0; i < h+1; i++) {
			for (int j = 0; j < w; j++) {
				visited[i][j] = INT_MAX;
			}
		}
		
		vector<Pos> store;
		vector<int> hh;
		for (int i = 0; i < w; i++) {
			store.push_back({0,i,block[0][i],-1});
			hh.push_back(store.size()-1);
		}

		make_heap(hh.begin(),hh.end(), 
			[&store](const int &a, const int &b){ 
				return store[a].ss > store[b].ss; 
			});
		int last;
		while(true) {
			pop_heap(hh.begin(),hh.end());
			last = hh.back();
			hh.pop_back();
			if (store[last].r == h) break;
			visited[store[last].r][store[last].c] = store[last].ss;
			
			for(auto &dir : dirs) {
				int newr = store[last].r + dir.first;
				int newc = store[last].c + dir.second;
				int newss = store[last].ss + block[newr][newc];
				bool ibx = 0 <= newr && newr < h+1;
				bool iby = 0 <= newc && newc < w;
				if (ibx && iby && newss < visited[newr][newc]) {
					store.push_back({
						newr,newc,newss,last
					});
					hh.push_back(store.size()-1);
					push_heap(hh.begin(),hh.end());
				}
			}
		}
		
		for(last = store[last].last; last != -1; last = store[last].last) {
			block[store[last].r][store[last].c] = ' ' - '0';
		} 
		for (int i = 0; i < h; i++ ){
			for (int j = 0; j < w; j++) {
				char c = block[i][j]+'0';
				cout << c;
			}

			cout << "\n";
		}
	}
}