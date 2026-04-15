class Solution {
public:
    int ROW; int COL;
    const vector<vector<int>> dire = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    int dp(int i, int j, vector<vector<int>>& memo, vector<vector<int>>& matrix){
        if(memo[i][j] != -1){
            return memo[i][j];
        }
        int temp = 1;
        for(auto cur : dire){
            int nr = i + cur[0];
            int nc = j + cur[1];
            if(nr < 0 or nc < 0 or nr >= ROW or nc >= COL){
                continue;
            }
            if(matrix[i][j] < matrix[nr][nc]){
                temp = max(temp, dp(nr, nc, memo, matrix) + 1);
            }
        }
        memo[i][j] = temp;
        return memo[i][j];
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        ROW = matrix.size(); COL = matrix[0].size();
        vector<vector<int>> memo(ROW + 1, vector<int>(COL + 1, -1));
        int temp = 0;
        for(int i = 0; i < ROW; ++i){
            for(int j = 0; j < COL; ++j){
                temp = max(dp(i, j, memo, matrix), temp);
            }
        }
        return temp;
        
    }
};
