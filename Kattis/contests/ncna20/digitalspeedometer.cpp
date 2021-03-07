#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    stringstream ss;
    string ln;
    
    double tf; double tr;
    getline(cin, ln); ss << ln;
    ss >> tf; ss.clear();
    getline(cin, ln); ss << ln;
    ss >> tr; ss.clear();
    double s; 
    getline(cin, ln); ss << ln;
    ss >> s; ss.clear();
    assert(s < 0.001);
    vector<double> prec{0.};
    cout << 0 << endl;
    while(getline(cin,ln)) {
        ss << ln;
        ss >> s; ss.clear();
        int base = (int)s;
        double fall = (double)base + tf;  
        double rise = (double)base + tr;
        if (s < 0.001) {
            //s is essentially 0
            cout << 0 << endl;
        }
        else if (1 - s > 0.001) {
            // s is less than one (but greater than 0)
            cout << 1 << endl;
        }
        else if (fall - s > 0.001) {
            //s falls between i and i+tf
            cout << base << endl;
        }
        else if (s - rise > 0.001) {
            //s falls between i+tr and j
            cout << base+1 << endl;
        }
        else  {
            int i = prec.size()-1;
            while(prec[i] - fall >= 0 && rise - prec[i] >= 0) {
                i--;
            }
            if (rise - prec[i] > 0) {
                //the most recent preceding value for s 
                //outside of range [i+tf,i+tr] is less than i+tr
                cout << base << endl;
            }
            else {
                //the most recent preceding value for s 
                //outside of range [i+tf,i+tr] is greater than i+tr
                cout << base+1 << endl;
            }
        }
        prec.push_back(s);
    }
}