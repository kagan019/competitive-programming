#include <stdio.h>
#include <string>
using namespace std;

short signm(int x) {
    return (x > 0) - (x < 0);
}

string solution(int r, int e, int c) {
    switch (signm(e - c - r)) {
        case 1: 
            return "advertise";
            break;
        case 0: 
            return "does not matter";
            break;
        case -1: 
            return "do not advertise";
            break;
    }
}

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        int r, e, c;
        scanf("%d", &r);
        scanf("%d", &e);
        scanf("%d", &c);
        printf("%s\n", solution(r, e, c).c_str());
    }
    
    return 0;
}