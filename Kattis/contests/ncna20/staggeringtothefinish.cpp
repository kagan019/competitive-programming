#include <bits/stdc++.h>
using namespace std;

double mod(double a, double b) {
    while (a - b > 0.000001) {
        a -= b;
    }
    return a;
}

int main() {
    cout << setprecision(12);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string ln;
    getline(cin,ln);
    stringstream in(ln);
    int N; in >> N; 
    double R; in >> R; 
    double S; in >> S; 
    double W; in >> W; 
    double F; in >> F; 
    double L1; in >> L1; 
    double L2; in >> L2; 
    while (getline(cin,ln)) {
        stringstream in2(ln);
        double D; in2 >> D; 
        cout << D << " ";
        for (int n = 0; n < N; n++) {
            //compute starting pos of lane n
            double L = (n == 0) ? L1 : L2;
            double rad_innerline = R+W*n;
            double rad_running = rad_innerline+L;
            double lsend = S/2.+F;
            double lscend = lsend+M_PI*rad_running;
            double usend = lscend+S;
            double rscend = usend+M_PI*rad_running;
            double total_track_len =2.*M_PI*rad_running+2*S;
            double adj_D = mod(D, total_track_len);
            double x; double y;
            if (adj_D < lsend) {
                //on lower straightaway
                y = -rad_innerline;
                x = -adj_D + F;

            } else if (adj_D  < lscend) {
                //on left semicircle
                double rem = adj_D - lsend;
                double torad = rem / rad_running;
                x = -sin(torad)*rad_innerline - S/2.;
                y = -cos(torad)*rad_innerline;
            
            } else if (adj_D < usend) {
                //on upper straightaway
                double straight = adj_D - lscend;
                y = rad_innerline;
                x = straight - S/2.;
            }
            else if( adj_D < rscend) {
                //on right semicircle
                double rem = adj_D - usend;
                double torad = rem / rad_running;
                x = sin(torad)*rad_innerline + S/2.;
                y = cos(torad)*rad_innerline;
            } else {
                //lower straightaway, to the right of finish line
                double rem = adj_D - rscend;
                y = -rad_innerline;
                x = S/2.-rem;
            }
            cout << x << " " << y << " ";

        }
        cout << endl;
    }
}