class Solution {
public:
    int islandsize(int row, int col, vector<vector<int>> &grid){
        if (row < 0 || row >= grid.size() || col < 0 || col >= grid[0].size()){
            return 0;
        }
        
        if (grid[row][col] > 0){
            grid[row][col] = -1;
            return 1 
                + islandsize(row+1, col, grid) 
                + islandsize(row-1, col, grid)
                + islandsize(row,col+1, grid)
                + islandsize(row,col-1, grid);
        }
        return 0;
    }
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = 0;
        for(int i = 0; i < grid.size(); i++){
            for (int j = 0; j < grid[0].size(); j++){
                if (grid[i][j] > 0){
                    m = max(islandsize(i, j, grid), m);
                }
            }
        }
        return m;
    }
};
