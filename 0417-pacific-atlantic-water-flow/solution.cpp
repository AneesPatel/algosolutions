class Solution {
public:
    int ROWS;
    int COLS;
    void dfs(int r, int c, int prev, vector<vector<bool>>& grid, vector<vector<int>>& heights){
        if(r < 0 or c < 0 or r >= ROWS or c >= COLS or grid[r][c] == true or heights[r][c] < prev){
            return;
        }
        grid[r][c] = true;
        prev = heights[r][c];
        dfs(r + 1, c, prev, grid, heights);
        dfs(r - 1, c, prev, grid, heights);
        dfs(r, c + 1, prev, grid, heights);
        dfs(r, c - 1, prev, grid, heights);

    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        vector<vector<int>> res;
        ROWS = heights.size();
        COLS = heights[0].size();
        vector<vector<bool>> pacGrid(ROWS, vector<bool>(COLS, false));
        vector<vector<bool>> atlGrid(ROWS, vector<bool>(COLS, false));
        for(int r = 0; r < ROWS; ++r){
            dfs(r, 0, heights[r][0], pacGrid, heights);
            dfs(r, COLS - 1, heights[r][COLS - 1], atlGrid, heights);
        }
        for(int c = 0; c < COLS; ++c){
            dfs(0, c, heights[0][c], pacGrid, heights);
            dfs(ROWS - 1, c, heights[ROWS - 1][c], atlGrid, heights);
        }
        for(int r = 0; r < ROWS; ++r){
            for(int c = 0; c < COLS; ++c){
                if(pacGrid[r][c] == true and atlGrid[r][c] == true){
                    res.push_back({r, c});
                }
            }
        }
        return res;
    }
};
