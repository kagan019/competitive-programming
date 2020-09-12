#include <bits/stdc++.h>
using namespace std;

int main() {
    int a, b;
    cin >> a >> b;
    cout << (int)ceil(log((double)b / (double)a)/log(3.0/2.0) + 0.001);

}