#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

int v(char x) {
    if (x == ' ')
        return 26;
    else if (x == '\'')
        return 27;
    else 
        return x - 'A';
}

int shortestd(char a, char b) {
    int va = v(a);
    int vb = v(b);
    int smaller = (va < vb) ? va : vb;
    int larger = (va == smaller) ? vb : va;
    int ccw = larger - smaller;
    int cw = 28 - larger + smaller;
    return (cw < ccw) ? cw : ccw;
}

long double time(char from, char to) {
    return shortestd(from, to) / 28.0 * 60 * 3.14159265359 / 15.0;
}

int main() {
    int n;
    cin >> n;
    string e;
    getline(cin, e);
    int k = n - 1;  
    long double result[n];

    while (n--) {
        long double sum = 1;
        string ln;
        getline(cin, ln);
        int i = 1; 
        while(ln[i] != '\0') {
            sum += time(ln[i-1], ln[i]) + 1;
            ++i;
        }
        result[k-n] = sum;
    }
    for (int g = 0; g <= k; g++) {
        cout << setprecision(12) << result[g] << endl;
    }
}