#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> dp;
vector<int> m;
int solve(int T1, int T2) {
	if (T1 <= 0 || T2 <= 0)
		return 0;
	
	int tmin = min(T1,T2);
	int tmax = max(T1,T2);
	for (int i = 0; i < m.size(); i++) {
		int b = solve(tmax-m[i],tmin);
		dp[T1][T2] = max(dp[T1][T2],1+b);
	}
	return dp[T1][T2];
}

int main() {
	int T; int N;
	cin >> T >> N;
	dp = vector<vector<int>>(T,vector<int>(T, 0));
	dp[0][0] = 0;
	m = vector<int>(N);
	for (int &x : m) cin >> x;
	int k = solve(T,T);
	cout << k;

}