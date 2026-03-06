class Solution {
public:
    int ROWS;
    int COLS;
    int maxcount;
    void dfs(int r, int c, int& curcount, vector<vector<int>>& grid){
        if(r < 0 or c < 0 or r >= ROWS or c >= COLS or grid[r][c] == 0){
            return;
        }
        curcount += 1;
        grid[r][c] = 0;
        if(curcount > maxcount){
            maxcount = curcount;
        }
        dfs(r + 1, c, curcount, grid);
        dfs(r - 1, c, curcount, grid);
        dfs(r, c + 1, curcount, grid);
        dfs(r, c - 1, curcount, grid);
        

        return;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        maxcount = 0;
        ROWS = grid.size();
        COLS = grid[0].size();
        int curcount = 0;
        for(int r = 0; r < ROWS; ++r){
            for(int c = 0; c < COLS; ++c){
                if(grid[r][c] == 1){
                    curcount = 0;
                    dfs(r, c, curcount, grid);
                }
                
            }
        }
        return maxcount;
    }
};
