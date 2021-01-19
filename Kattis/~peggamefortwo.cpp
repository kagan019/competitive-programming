#include <iostream>
using namespace std;


/*

original -> matrix
up and to the right -> up
nothing -> up and to the right
nothing -> down and to the left
up and to the left -> up and to the left
left/right -> left/right
down and to the left -> down
down and to the right -> down and to the right

*/

int main() {
    int board[9][9]; // pretend every second row is shifted right slightly
    for (int i=0; i<9;++){
        for(int j=0; j<9; j++) {
            board[i][j] = -1;
        }
    }
    for(int i=0; i<5; i++) {
        for (int j=0; j<=i;j++){
            int n;
            cin >> n;
            board[4 - i/2]
        }
    }
}