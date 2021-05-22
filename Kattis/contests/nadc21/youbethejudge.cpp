#include <bits/stdc++.h>
using namespace std;

int parse(string &s) {
    int num = 0;
    for (int i = 0; i < s.size(); i++) {
        num *= 10;
        if (!(s[i] >= '0' && s[i] <= '9'))
            return -1;
        if (num == 0 && s[i]-'0' == 0)
            return -1; 
        num += s[i]-'0';

    }
    return num;
}

bool isPrime(int n)
{
    // Corner cases
    if (n <= 1)
        return false;
    if (n <= 3)
        return true;
  
    // This is checked so that we can skip
    // middle five numbers in below loop
    if (n % 2 == 0 || n % 3 == 0)
        return false;
  
    for (int i = 5; i * i <= n; i = i + 6)
        if (n % i == 0 || n % (i + 2) == 0)
            return false;
  
    return true;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); 
    string line;
    vector<string> tokens;
    while (!(getline(cin,line).eof())) {
        stringstream ll(line);
        
        while (ll.good()) { 
            string token; ll >> token;
            if (token.size())
                tokens.push_back(token);
        }


    }

    if (tokens.size() != 3) {
        cout << 0;
        return 0;
    }
   
    vector<int> nums;
    for (auto &t : tokens) {
        int parsed = parse(t);
        if (parsed < 0) {
            cout << 0;
            return 0;
        }
        nums.push_back(parsed);
        if (nums.size() > 3) {
            cout << 0;
            return 0;
        }
        
    }
    if (nums[0] <= 3 || nums[0] > 1000000000) {
        cout << 0; return 0;
    }
    if (nums[1] + nums[2] != nums[0]
      || nums[0] % 2 != 0) {
        cout << 0;
        return 0;
    }
    if (!isPrime(nums[1]) || !isPrime(nums[2])) {
        cout << 0;
        return 0;
    }
    cout << 1;
}