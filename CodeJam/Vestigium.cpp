#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	ll T; cin >> T;
	for (ll casenum = 1; casenum <= T; casenum++){
		ll N; cin >> N;
		vector<vector<ll>> M(N, vector<ll>(N));
		for (vector<ll> &k : M) {
			for (ll &x : k) cin >> x;
		}

		ll trace = 0;
		for (ll i = 0; i < N; i++){
			trace += M[i][i];
		}

		ll rows_dup = 0;
		for (auto &x : M) {
			if (unordered_set<ll>(x.begin(), x.end()).size() != N)
				rows_dup++;
		}

		ll cols_dup = 0;
		for (ll col = 0; col < N; col++) {
			unordered_set<ll> colelems;
			for (auto &x : M) {
				colelems.insert(x[col]);
			}
			if (colelems.size() != N)
				cols_dup++;
		}

		cout << "Case #" << casenum << ": " << trace << " " << rows_dup << " " << cols_dup << "\n";
	}
}