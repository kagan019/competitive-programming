#include <stdio.h>

const char* winner(int numStones) {
    return ((numStones % 2 == 0) ? "Bob" : "Alice");
}


int main() {
    int N;
    scanf("%d", &N);

    printf("%s", winner(N));
    return 0;
}