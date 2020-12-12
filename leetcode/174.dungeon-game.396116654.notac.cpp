class Solution {
public:
    int max(int a, int b) {return (a<b) ? b : a;}
    int min(int a, int b) {return (a>b) ? b : a;}
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        const int R = dungeon.size();
        const int C = dungeon[0].size();
        vector<vector<int>> curhp(R,vector<int>(C));
        vector<vector<int>> minhp(R,vector<int>(C));
        //^ the minhp at a position if you chose the best path to that square
        curhp[0][0] = dungeon[0][0];
        minhp[0][0] = min(0,curhp[0][0]);
        for (int k = 1; k < R; k++) {
            curhp[k][0] = curhp[k-1][0] + dungeon[k][0];
            minhp[k][0] = minhp[k-1][0];
            if (curhp[k][0] < minhp[k][0])
                minhp[k][0] = curhp[k][0];
        }
        for (int k = 1; k < C; k++) {
            curhp[0][k] = curhp[0][k-1] + dungeon[0][k];
            minhp[0][k] = minhp[0][k-1];
            if (curhp[0][k] < minhp[0][k])
                minhp[0][k] = curhp[0][k];
        }
        
        for (int r = 1; r < R; r++) {
            for (int c = 1; c < C; c++) {
                int nexthpup = curhp[r-1][c] + dungeon[r][c];
                int nexthpleft = curhp[r][c-1] + dungeon[r][c];
                int nextminhpfromup = min(minhp[r-1][c],nexthpup);
                int nextminhpfromleft = min(minhp[r][c-1],nexthpleft);
                if (nextminhpfromup > nextminhpfromleft) {
                    minhp[r][c] = nextminhpfromup;
                    curhp[r][c] = nexthpup;
                } else {
                    minhp[r][c] = nextminhpfromleft;
                    curhp[r][c] = nexthpleft;
                }
            }
        }
        for(int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {
                cout << curhp[i][j] << " ";
                
            }
            cout << endl;
        }
        return max(0,-minhp[R-1][C-1])+1;
    }
};
