#include <bits/stdc++.h>
using namespace std;

void swapind(int i, int j, vector<int> &v){
    int temp = v[j];
    v[j] = v[i];
    v[i] = temp;
}

int main(){
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        if (n == 1){
            int k; cin >> k;
            cout << k << "\n";
            continue;
        }
        vector<int> arr(n);
        for(int i = 0; i < n; i++){
            int k; cin >> k;
            arr[i] = k;
        }
        sort(arr.begin(), arr.end(), [](int a, int b){return a > b;});
        for (int j = 1; j < arr.size(); j++){
            for (int i = 0; i < j; i++){
                if (i-arr[i] == j-arr[j]){
                    swapind(i, j, arr);
                    j = 1; i = 0;
                }
            }
        }
        for (int i = 0; i < arr.size(); i++){
            cout << arr[i] << " ";
        }
        cout << "\n";

    }
}