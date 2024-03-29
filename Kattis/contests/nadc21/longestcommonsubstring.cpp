// CODE FROM https://www.geeksforgeeks.org/longest-common-substring-array-strings/

// C++ program to find the stem of given list of
// words
#include <bits/stdc++.h>
using namespace std;
 
// function to find the stem (longest common
// substring) from the string array
int findstem(vector<string> &arr)
{
    // Determine size of the array
    int n = arr.size();
 
    // Take first word from array as reference
    string s = arr[0];
    int len = s.length();
 
    int res = 0;
 
    for (int i = 0; i < len; i++) {
        for (int j = i + 1; j <= len; j++) {
            // generating all possible substrings
            // of our reference string arr[0] i.e s
            string stem = s.substr(i, j);
            int k = 1;
            for (k = 1; k < n; k++) {
                // Check if the generated stem is
                // common to all words
                if (arr[k].find(stem) == string::npos)
                    break;
            }
 
            // If current substring is present in
            // all strings and its length is greater
            // than current result
            if (k == n && res < stem.length())
                res = stem.length();
        }
    }
 
    return res;
}
 
// Driver code
int main()
{
    int n; cin >> n;
    vector<string> arr(n);
    for (string &s : arr)
        cin >> s;
 
    // Function call
    cout << findstem(arr);
}
 
// This code is contributed by
// sanjeev2552