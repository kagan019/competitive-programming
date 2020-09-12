#include <stdio.h>
#include <iterator>
#include <map>
#include <math.h>

using namespace std;


 int lcm(int a, int b)  
 {  
    return (a*b)/memoized_gcd(a, b);  
 }  

bool relprime(int a, int b) {
    return __gcd(a,b) == 1;
}

void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

bool isPrime(int n) 
{ 
    // Corner case 
    if (n <= 1) 
        return false; 
  
    // Check from 2 to n-1 
    for (int i = 2; i < n; i++) 
        if (n % i == 0) 
            return false; 
  
    return true; 
} 

constexpr vector<int>& primes(){
    vector<int> primes {2};
    for (int i = 3; i <= pow(10, 7/2), i += 2) {
        if (isPrime(i))
            primes.push_back(i);
    }
    return primes;
}

int solve(int a, int b, int c, int d) {
    constexpr vector<int> p = primes();

    if (a > c) {
        swap(a, c);
        swap(b, d);
    }

    int total_pairs = (c - a + 1) * (d - b + 1);

    int non_rp_pairs = 0;
    set<int> explored_primes;
    for (int i = p.size() - 1; i > 0; i--) {
        non_rp_pairs(c / p[i] - a / p[i];

    }
    return total_pairs - non_rp_pairs;
}

int main() {
    int a, b, c, d;
    scanf("%d", &a);
    scanf("%d", &b);
    scanf("%d", &c);
    scanf("%d", &d);

    printf("%d", solve(a, b, c, d));
    return 0;
}