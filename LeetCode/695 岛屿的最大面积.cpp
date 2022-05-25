class Solution {
public:
    int row;
    int col;
    int count;
    void dfs(vector<vector<int>>& grid, int i, int j){
        grid[i][j] = 0;
        count++;
        // up
        if (i-1>=0 && grid[i-1][j] == 1){
            dfs (grid, i-1, j);
        }
        // left
        if (j-1>=0 && grid[i][j-1] == 1){
            dfs (grid, i, j-1);
        }
        // down
        if (i+1<row && grid[i+1][j] == 1){
            dfs (grid, i+1, j);
        }
        // right
        if (j+1<col && grid[i][j+1] == 1){
            dfs (grid, i, j+1);
        }
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int ans = 0;
        row = grid.size();
        col = grid[0].size();
        
        for (int i=0; i<row; i++){
            for(int j=0; j<col; j++){
                if(grid[i][j] == 1){
                    count = 0;
                    dfs (grid, i, j);
                    ans = max(ans, count);
                }
            }
        }
        return ans;
    }
};