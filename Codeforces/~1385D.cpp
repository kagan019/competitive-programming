#include <bits/stdc++.h>
using namespace std;

int allc(string &s, int start, int end, char c){
	int ret = 0;
	for (int i = start; i < end; i++) {
		if (s[i] != c)
			ret++;
	}
	return ret;	
}

pair<int, int> mostof(string &s, int start, int end) {
	char cs[26];
	for (char i = 'a'; i <= 'z'; i++) {
		cs[i-'a'] = 0;
	}
	int max = 0;
	int maxchar = '\0';
	for (int i = start; i < end; i++) {
		char cur = s[i] - 'a';
		cs[cur]++;
		if (cs[cur] > max) {
			max = cs[cur];
			maxchar = s[i];
		}
	}
	return make_pair(maxchar, max);
}

int recurse(string &s, int start, int end) {
	//viewest number of changes to make s good
	//only chars of s between start (inc) and end (exc)
	// are considered
	if (end-start <= 2) {
		return 0;
	}

	auto pr = mostof(s,(start+end)/2,end);
	auto pl = mostof(s,start,(start+end)/2);
	int ar = (end- start) / 2 - pr.second;
	int al = (end- start) / 2 - pl.second;
	int vv = 0;
	if (ar < al) {
		vv += ar;
		vv += recurse(s, start,(start+end)/2);
		return vv;
	}
	else {
		vv += al;
		vv += recurse(s, (start+end)/2,end);
		return vv;
	}
}

int main() {
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		string s;
		for (int i = 0; i < n; i++) {
			char x; cin >> x;
			s.push_back(x);
		}
		int la = allc(s, 0, s.size()/2, 'a');
		int ra = allc(s, s.size()/2, s.size(), 'a');
		int vv = 0;
		if (la < ra) {
			vv += la;
			vv += recurse(s, s.size()/2, s.size());
		}
		else {
			vv += ra;
			vv += recurse(s, 0, s.size()/2);
		}
		cout << vv << endl;
	}
}