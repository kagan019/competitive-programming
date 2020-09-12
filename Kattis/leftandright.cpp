#include <iostream>
#include <vector>
#include <string>

using namespace std;

int len_of_next_run(int i, int n, string &d) {
    int j = 0;
    while (i + j < n-1 && d[i + j] == d[i])
        j++;
    return j;
}

vector<int> solution(int n, string &d) {
    vector<int> houses;
    int i = 0;
    int nr = len_of_next_run(i, n, d);
    int curhouse = (d[0] == 'L') ? 1 + nr : 1; // set starting house
    int lhv = curhouse;
    houses.push_back(curhouse);
    while(houses.size() < n) {
        int nr_ = nr;
        while (nr_ > 1) {          
            if (d[i] == 'L') curhouse--;
            else { curhouse++; }
            houses.push_back(curhouse);
            nr_--;
        }
        
        i += nr;
        nr = len_of_next_run(i, n, d);
        if (d[i - 1] == 'L') {
            curhouse--;
            houses.push_back(curhouse);
            curhouse = lhv;
        }
        else {
            curhouse += nr + 1;
            houses.push_back(curhouse);
            lhv = curhouse;
        }
        
    }

    return houses;
}



int main() {
    int n;
    string d;
    cin >> n >> d;
    for (int &k : solution(n, d))
        cout << k << "\n";
    return 0;
}