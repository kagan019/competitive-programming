#include <stdio.h>

int solve(int r1, int avg) {
    return 2 * avg - r1;
}






int main() {
    int r1, s;
    scanf("%d", &r1);
    scanf("%d", &s);

    printf("%d", solve(r1, s));
    return 0;
}