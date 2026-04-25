class Solution {
public:
    int ROWS; int COLS;
    int dfs(int r, int c, vector<vector<char>>& grid){
        if(r < 0 or c < 0 or r >= ROWS or c >= COLS or grid[r][c] == '0'){
            return 0;
        }
        grid[r][c] = '0';
        dfs(r + 1, c, grid);
        dfs(r, c + 1, grid);
        dfs(r - 1, c, grid);
        dfs(r, c - 1, grid);
        return 0;
    }
    int numIslands(vector<vector<char>>& grid) {
        int res = 0;
        ROWS = grid.size();
        COLS = grid[0].size();
        for(int r = 0; r < ROWS; ++r){
            for(int c = 0; c < COLS; ++c){
                if(grid[r][c] == '1'){
                    dfs(r, c, grid);
                    res++;
                }
            }
        }
        return res;
    }
};
