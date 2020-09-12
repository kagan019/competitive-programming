#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;

ull east;
ull east_n;
ull north;
ull north_n;

string path(bool sign_ns, bool sign_ew) {
	string s;
	ull bit = 1;
	ull i = 0;
	while (i <= 32) {
		if (bit & east) {
			char x = (((bit & east_n) && !sign_ew) || (!(bit & east_n) && sign_ew)) ? 'W' : 'E';
			s.push_back(x);
		}
		if (bit & north) {
			char x = (((bit & north_n) && !sign_ns) || (!(bit & north_n) && sign_ns)) ? 'S' : 'N';
			s.push_back(x);
		}
		i++;
		bit *= 2;
	}
	return s;
}


int main() {
	int T; cin >> T;
	for (int casenum = 1; casenum <= T; casenum++) {
		east = 0;
		east_n = 0;
		north = 0;
		north_n = 0;

		long long X, Y;
		cin >> X >> Y;
		east = (unsigned long long)(abs(X));
		north = (unsigned long long)(abs(Y));

		ull bit = 1;
		ull laste = 0;
		ull lastn = 0;
		ull start1_e = 0;
		ull start1_n = 0;
		ull end1_e = 0;
		ull end1_n = 0;
		bool invert = false;
		bool fail = false;
		ull i = 0;
		while(i <= 32) {
			if ((east & north) == 0) {
				fail = false;
				break;
			}
			if ((north & bit) && (east & bit)) {
				invert = true;
			}
			if (east & bit && !laste) {
				start1_e = bit;
			}
			if (!(east & bit) && laste) {
				end1_e = bit;
			}
			if (north & bit && !lastn) {
				start1_n = bit;
			}
			if (!(north & bit) && lastn) {
				end1_n = bit;
			}


			if (end1_e > start1_e && end1_n > start1_n) {
				if (start1_n == start1_e) {
					fail = true;
					break;
				}
				if (invert) {
					
					if (end1_n >= end1_e) {
						if (east & end1_n) {
							fail = true;
							break;
						}
						north += start1_n;
						north |= start1_n;
						north_n |= start1_n; // 'negative bit'
					}
					else if (end1_e > end1_n) {
						if (north & end1_e) {
							fail = true;
							break;
						}
						east += start1_e;
						east |= start1_e;
						east_n |= start1_e;
					}
					invert = false;
				}
			}

			laste = east & bit;
			lastn = north & bit;
			bit *= 2;
			i++;
		}
		bool zero = false;
		ull combined = north | east;
		while (combined) {
			if (!(combined & 1))
				zero = true;
			if (zero && combined & 1) {
				fail = true;
				break;
			}
			combined >>= 1;
		}

		if (!fail)
			cout << "Case #" << casenum << ": " << path(Y < 0, X < 0) << endl;
		else
			cout << "Case #" << casenum << ": IMPOSSIBLE" << endl;
	}
}