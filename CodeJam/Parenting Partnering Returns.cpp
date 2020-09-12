#include <bits/stdc++.h>
using namespace std;

struct activity {
	int s, e;
	int origi;
	char color = '\0';

};

int main() {
	int T; cin >> T;

	for (int casenum = 1; casenum <= T; casenum++){
		
		vector<activity> sched;
		int n; cin >> n;
		for (int i = 0; i < n; i++){
			int si, ei;
			cin >> si >> ei;
			activity a({.s=si, .e=ei, .origi=i});
			sched.push_back(a);
		}
		sort(sched.begin(), sched.end(), [](activity &a, activity &b) {
			return a.e < b.e;
		});

		//color
		int lastCe = -1;
		int lastJe = -1;
		char curcol = 'C';
		bool fail = false;
		for (int i = 0; i < n; i++){
			if (curcol == 'C' && sched[i].s < lastCe) {
				curcol = (curcol == 'C') ? 'J' : 'C';
				if (sched[i].s < lastJe) {
					cout << "Case #" << casenum << ": " << "IMPOSSIBLE" << "\n";
					fail = true;
					break;
				}
			}
			if (curcol == 'J' && sched[i].s < lastJe) {
				curcol = (curcol == 'C') ? 'J' : 'C';
				if (sched[i].s < lastCe) {
					cout << "Case #" << casenum << ": " << "IMPOSSIBLE" << "\n";
					fail = true;
					break;
				}
			}

			if (curcol == 'C') {
				lastCe = sched[i].e;
			}
			else if (curcol == 'J') {
				lastJe = sched[i].e;
			}
			sched[i].color = curcol;
		}

		//build string
		if (fail) {
			continue;
		}
		vector<char> ans(n);
		for (activity &a : sched) {
			ans[a.origi] = a.color;
		}
		string ret(ans.begin(), ans.end());
		cout << "Case #" << casenum << ": " << ret << "\n";
	}
}