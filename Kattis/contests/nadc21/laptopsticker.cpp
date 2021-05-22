#include <bits/stdc++.h>

using namespace std;

int main () {
    double wc; double hc;
    cin >> wc >> hc;
    double ws; double hs;
    cin >> ws >> hs;

    cout << (int)(ws <= wc-2 && hs <= hc -2);
}