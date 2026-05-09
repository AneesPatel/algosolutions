class Solution {
public:
    int ROW;
    int COL;
    int SIZE;
    vector<vector<int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    void dfs(int r, int c, int curdire, vector<int>& res, vector<vector<int>>& matrix){
        if(res.size() == SIZE){
            return;
        }
        res.push_back(matrix[r][c]);
        matrix[r][c] = INT_MIN;
        int nr = r + directions[curdire][0];
        int nc = c + directions[curdire][1];
        if(nr < 0 or nc < 0 or nr >= ROW or nc >= COL or matrix[nr][nc] == INT_MIN){
            curdire = (1 + curdire) % 4;
            nr = r + directions[curdire][0];
            nc = c + directions[curdire][1]; 
        }
        dfs(nr, nc, curdire, res, matrix);

    }

    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        ROW = matrix.size();
        COL = matrix[0].size();
        SIZE = ROW * COL;
        dfs(0, 0, 0, res, matrix);
        return res;
    }
};
