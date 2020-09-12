#include <stdio.h>

const char quadrant(int x, int y) {
    const char bits = ((y < 0) << 1) | (x < 0);
    return (y > 0) * bits + (y < 0) * (5 - bits) +  1;
} 

const char* tests() {
    const int testParams[][2] = {
        {1, 2},
        {3, -4},
        {-8, 9},
        {4, 4},
        {-1, -2}
    };
    char* ret = new char[(sizeof(testParams)/(sizeof(*testParams)))];

    for (int i = 0; i < (sizeof(testParams)/(sizeof(*testParams))); i++) {
        ret[i] = quadrant(testParams[i][0], testParams[i][1]);
    }

    return ret;
}

int main() {
    int x;
    scanf("%d", &x);
    int y;
    scanf("%d", &y);

    printf("%d", quadrant(x, y));
    return 0;
}