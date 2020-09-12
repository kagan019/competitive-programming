#include <stdio.h>
#include <algorithm>


int reverse(int threeDigitNum) {
    const int firstDigit = threeDigitNum % 10;
    threeDigitNum /= 10;
    const int secondDigit = threeDigitNum % 10;
    threeDigitNum /= 10;
    const int thirdDigit = threeDigitNum % 10;
    threeDigitNum /= 10;

    return firstDigit * 100 + secondDigit * 10 + thirdDigit;
}

int compare_mostSigDigLast(int a, int b) {
    return std::max(reverse(a), reverse(b));
}


int main() {
    int A, B;
    scanf("%d", &A);
    scanf("%d", &B);

    printf("%d", compare_mostSigDigLast(A, B));
    return 0;
}

