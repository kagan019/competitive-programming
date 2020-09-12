#include <bits/stdc++.h>
using namespace std;

int main() {
	int T; cin >> T;
	for (int cn = 1; cn <= T; cn++) {
		int N; cin >> N;
		vector<string> in(N);
		for (string &x : in) cin >> x;

		int maxlen = -1;
		int maxnumstars = -1;
		vector<string> firsts;
		vector<string> mids;
		vector<string> lasts;
		for (string &s : in) {
			maxlen = max(maxlen, s.size());
			string f = "", m = "", l = "";
			int fi = -1;
			int li = -1;
			for(int i = 0; i < s.size(); i++) {
				if (s[i] == '*') {
					fi = i;
					break;
				}
				f.push_back(s[i]);
			}
			for(int i = s.size() - 1; i > fi && i >= 0; i--) {
				if (s[i] == '*') {
					li = i;
					break;
				}
				l.push_back(s[i]);
			}
			reverse(l.begin(), l.end());
			for (int i = fi + 1; i < li; i++) {
				if (s[i] != '*')
					m.push_back(s[i]);
			}
			firsts.push_back(f);
			mids.push_back(m);
			lasts.push_back(l);
		}
		string maxfirst;
		for (string &k lasts) {
			if (k.size() > maxlast.size()) {
				maxlast = k;
			}
		}

		string mystr;
		bool fail = false;
		bool validchar = true;
		for (int c = 0; validchar && !fail; c++) {
			bool validchar = false;
			char check = '*'
			for (int i = 0; i<firsts.size(); i++) {
				if (i < firsts[i].size()) {
					validchar = true;
					if (check == '*') {
						check = firsts[i][c];
					}
					else {
						if (check != firsts[i][c]) {
							fail = true;
							mystr = "*";
							break;
						}
					}
				}
			}
		}
		if (!fail) {
			string maxlast;
			for (string &k lasts) {
				if (k.size() > maxlast.size()) {
					maxlast = k;
				}
			}

			validchar = true;

			for (int c = 0; validchar && !fail; c++) {
				bool validchar = false;
				char check = '*'
				for (int i = 0; i<lasts.size(); i++) {
					if (i < lasts[i].size()) {
						validchar = true;
						if (check == '*') {
							check = lasts[i][c];
						}
						else {
							if (check != lasts[i][c]) {
								fail = true;
								mystr = "*";
								break;
							}
						}
					}
				}
			}
			if (!fail) {

			}
		}
			
		cout << "Case #" << cn << ": " << mystr;	
		
	}
}