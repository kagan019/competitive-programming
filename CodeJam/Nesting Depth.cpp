#include <bits/stdc++.h>
using namespace std;

void open(int deldepth, string &out){
	//postpend opening parens and a digit
	if (deldepth > 0) {
		for (int i = 0; i < deldepth; i++){
			out.push_back('(');
		}
	}
	

}

void close(int deldepth, string &out) {
  //postpend necessary closing parens
  
	if (deldepth < 0) {
		for( int i = 0; i > deldepth; i--){
			out.push_back(')');
		}
	}
}


int main() {
	int T; cin >> T;
	
	for (int i = 0; i < T; i++)
{		int lastd = 0;
		string s; cin >> s;
		string out = "";
		int d;
		for (char c : s) {
			d = c-'0';
			close(d-lastd, out);
			open(d-lastd, out);
			out.push_back(c);
			lastd = d;
		}
		close(-lastd, out);

		cout << "Case #" << (i+1) << ": " << out << "\n";
	}
	
}