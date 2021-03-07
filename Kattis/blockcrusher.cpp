#include <bits/stdc++.h>
using namespace std;

struct Pos {
	int r, c;
	int cost;
	Pos *last;
};


pair<int,int> dirs[8] = {{-1,-1},{-1,0},{-1,1},
                         {0,-1},        {0,1},
                         {1,-1}, {1,0}, {1,1}};

int main() {
	int t = 200;
	while(t--) {
		int h, w;
		cin >> h >> w;
		if (h == 0)
			break;
		vector<vector<int>> block(h,vector<int>(w));
		for (int i =0; i < h; i++) {	
			string s; cin >> s;
			for (int j = 0; j < w; j++) {
				block[i][j] = s[j]-'0';
			}
		}
		
		vector<vector<int>> visited(h,vector<int>(w,INT_MAX));
		
		vector<Pos> heap;
		//init heap
		auto poscmp = [](Pos &a, Pos &b) {
				return a.cost > b.cost;
			};
		for (int c = 0; c < w; c++) {
			heap.push_back(Pos{0,c,block[0][c],NULL});
		}

		make_heap(heap.begin(),heap.end(),poscmp);
		Pos store[1201]; int sts = 0;
		Pos exp;
		while(heap.size()) {
			pop_heap(heap.begin(),heap.end(),poscmp);
			exp = heap.back();
			heap.pop_back();
			if (exp.r == h-1)
				break;
			if (visited[exp.r][exp.c] <= exp.cost)
				continue;
			visited[exp.r][exp.c] = exp.cost;
			store[sts] = exp; sts++;
			//explore neighbors
			for (auto &dir : dirs) {
				int newr = dir.first+exp.r;
				int newc = dir.second+exp.c;
				bool by = 0 <= newr && newr < h;
				bool bx = 0 <= newc && newc < w;
				if (!(by && bx))
					continue;
				int newcst = exp.cost+block[newr][newc];
				bool bc = newcst < visited[newr][newc];
				if (!bc)
					continue;
				Pos newp{newr,newc,newcst,store+sts-1};
				heap.push_back(newp);
				push_heap(heap.begin(),heap.end(),poscmp);
			}
		}
		for(Pos *ll = &exp; ll != NULL; ll = ll->last) {
			block[ll->r][ll->c] = ' ' - '0';
		} 
		for (int i = 0; i < h; i++ ){
			for (int j = 0; j < w; j++) {
				char c = block[i][j]+'0';
				cout << c;
			}
			cout << "\n";
		}
		cout << "\n";
	}
}