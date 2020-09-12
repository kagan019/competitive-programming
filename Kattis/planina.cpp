#include <stdio.h>
#include <cmath>

int numberOfEdgesInAMatrixOfSquares(int numOfSquares) {
    const int numOfSquaresInASide = (int)(std::sqrt(numOfSquares));
    return (1 + numOfSquaresInASide) * numOfSquaresInASide * 2;
}

int newDots(int startingNumOfSquares) {
    return startingNumOfSquares + numberOfEdgesInAMatrixOfSquares(startingNumOfSquares);
}

int numSquaresAfterIterations(int iterations) {
    return (int)std::pow(4, iterations);
}

int successiveIterations(int numOfIterations) {
    const int numSquares = numSquaresAfterIterations(numOfIterations - 1);

    if (numOfIterations == 0)
        return 4;
    else
        return newDots(numSquares) + successiveIterations(numOfIterations - 1);
}


int main() {
    int N;
    scanf("%d", &N);

    printf("%d", successiveIterations(N));
    return 0;
}