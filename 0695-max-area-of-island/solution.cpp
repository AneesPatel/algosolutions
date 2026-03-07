class Solution {
public:
    int maxarea;
    int ROWS;
    int COLS;
    void dfs(int r, int c, int& count, vector<vector<int>>& grid){
        if(r < 0 or c < 0 or r >= ROWS or c >= COLS or grid[r][c] == 0){
            return;
        }
        count += 1;
        grid[r][c] = 0;
        if(count > maxarea){
            maxarea = count;
        }
        dfs(r + 1, c, count, grid);
        dfs(r, c + 1, count, grid);
        dfs(r, c - 1, count, grid);
        dfs(r - 1, c, count, grid);
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        ROWS = grid.size();
        COLS = grid[0].size();
        int count;
        maxarea = 0;
        for(int r = 0; r < ROWS; ++r){
            for(int c = 0; c < COLS; ++c){
                if(grid[r][c] == 1){
                    count = 0;
                    dfs(r, c, count, grid);
                }
            }
        }
        return maxarea;
    }
};
