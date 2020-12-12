class Solution {
public:
    void explore(vector<vector<char>> &grid, int i, int j) {
        if (i < 0
         || j < 0
         || i >= grid.size()
         || j >= grid[0].size())
            return;
        if (grid[i][j] != '0' && grid[i][j] != '\0') {
            grid[i][j] = '\0';
            explore(grid, i + 1, j);
            explore(grid, i-1, j);
            explore(grid, i, j-1);
            explore(grid, i, j+1);
        }
    }
    
    int numIslands(vector<vector<char>>& grid) {
        int k = 0;
        for (int i = 0; i < grid.size(); i++) {
            for(int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == '1')
                    k++;
                explore(grid, i, j);
            }
        }
        return k;
    }
};
