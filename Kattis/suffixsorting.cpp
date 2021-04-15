#include <bits/stdc++.h>
using namespace std;

struct srank{
    int first; int second;
    int original_index;

};


int main() {
    auto rankcmp = [](srank &a, srank &b) {
        if (a.first == b.first)
            return a.second < b.second;
        return a.first < b.first;
    };

    string s;

    while (!(getline(cin,s).eof())) {
        
        s.push_back('\0');
        const int N = s.size();
        string numbers;
        getline(cin,numbers);
        stringstream ns (numbers);
        int n; ns >> n;
        vector<int> qi(n);
        for (int &x : qi) {ns >> x;}

        vector<int> rankofsuffixi(N);
        for (int i = 0; i < N; i++) {
            rankofsuffixi[i] = (int)(s[i]);
        }
        vector<int> nextrankofsuffixi(N);
        vector<srank> ranksinorder(N);
        for (int offs = 1; offs < N; offs <<= 1) {
            for (int i = 0; i < N; i++) {
                ranksinorder[i] =  {
                    rankofsuffixi[i],
                    ((i+offs < N) 
                        ? rankofsuffixi[i+offs]
                        : -1),
                    i
                };
            }
            sort(ranksinorder.begin(),ranksinorder.end(), rankcmp);
            int nextrank = 0;
            nextrankofsuffixi[ranksinorder[0].original_index] = 0;
            for (int i =1; i < N; i++) {
                if (rankcmp(ranksinorder[i-1], ranksinorder[i])) //ascending, not equal
                    nextrank++;
                nextrankofsuffixi[ranksinorder[i].original_index] = nextrank;
            }

            rankofsuffixi = vector<int>(nextrankofsuffixi.begin(),nextrankofsuffixi.end()); //optimize later

            if (nextrank >= N-1) //every suffix is ranked already
                break;
        }

        for (int &j : qi) {
            cout << ranksinorder[j+1].original_index << " " /*<< string(s.begin()+ranksinorder[j].original_index, s.end()) << " "*/;
        }
        cout << endl;
    }
}


// #include <bits/stdc++.h>
// using namespace std;

// int main() {
//     string s;
//     while (!(getline(cin,s).eof())) {
//         string numbers;
//         getline(cin,numbers);
//         stringstream ns (numbers);
//         int n; ns >> n;
//         vector<int> qi(n);
//         for (int &x : qi) {ns >> x;}

//         vector<pair<string,int>> suffixes;
//         for (int i = 0; i < s.size()-1; i++) {
//             suffixes.push_back({string(s.begin()+i,s.end()),i});
//         }
//         sort(suffixes.begin(),suffixes.end(), [](auto &a, auto &b){
//             return a.first.compare(b.first) <= 0;
//         });
//         for (int &j : qi) {
//             cout << suffixes[j].second << " ";
//         }
//         cout << endl;
//     }
// }