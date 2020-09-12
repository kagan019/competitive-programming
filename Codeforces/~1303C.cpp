// #include <bits/stdc++.h>
// using namespace std;


// int main() {
//     int T; cin >> T;
//     const string alphabet = "abcdefghijklmnopqrxtuvwxyz";
// LOOP: 
//     while(T--){
//         string s; cin >> s;
//         vector<set<char>> adj(26, set<char>());
//         auto fi = [&adj](char x) {return &(adj[x -'a']);};

//         for (int i = 0; i < s.size() - 1; i++){
//             if (i > 0){
//                 fi(s[i])->insert(s[i-1]);
//                 fi(s[i-1])->insert(s[i]);
//             } if (i < s.size() - 1) {
//                 fi(s[i])->insert(s[i+1]);
//                 fi(s[i+1])->insert(s[i]);
//             }
//         }
//         int oneindex = -1; //start
//         int oneindex2 = -1; //end
//         for (int i =0; i<adj.size(); i++){
//             auto cs = adj[i];
//             if (cs.size() > 2){
//                 cout << "NO\n";
//                 goto LOOP;
//             }
//             else if (cs.size() == 1){
//                 if (oneindex == -1)
//                     oneindex = i;
//                 else if (oneindex2 ==-1)
//                     oneindex2 = i;
//                 else {
//                     cout << "NO\n";
//                     goto LOOP;
//                 }
//             }
//         }
//         set<char> used;
//         string buildme;
//         char k = s[oneindex];
//         while(used.size() < s.size()){
//             used.insert(k);
//             buildme.push_back(k);

//             set<char>::iterator adj_to_k = fi(k)->begin();
//             if(*adj_to_k == s[oneindex2] || *(adj_to_k+1) == s[oneindex`]
//             if (used.find(*adj_to_k) != used.end()){ 
//                 adj_to_k++;
//             } if(used.find(*adj_to_k) != used.end()) {
//                 cout << "NO\n";
//                 goto LOOP;
//             }

//             k = *adj_to_k;
//         }
//         if (used.size() != s.size()){
//             cout << "NO\n";
//             goto LOOP;
//         }

//         string diff;
//         string::iterator b = diff.begin();
//         string::iterator e = set_difference(alphabet.begin(), alphabet.end(), 
//             used.begin(), used.end(), b);
//         diff.assign(b, e);
//         buildme.append(diff);
//         cout << "YES\n" << buildme << "\n";
//     }
    
// }