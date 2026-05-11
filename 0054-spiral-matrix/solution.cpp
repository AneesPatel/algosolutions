class Solution {
public:
    const std::vector<std::vector<int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    int ROW; int COL;
    int SIZE;
    void dfs(int r, int c, int curDire, std::vector<int>& res, vector<vector<int>>& matrix){
        if(res.size() == SIZE){
            return;
        }
        res.push_back(matrix[r][c]);
        matrix[r][c] = INT_MIN;
        int nr = r + directions[curDire][0];
        int nc = c + directions[curDire][1];
        if(nr < 0 or nr >= ROW or nc < 0 or nc >= COL or matrix[nr][nc] == INT_MIN){
            curDire = (curDire + 1) % 4;
            nr = r + directions[curDire][0];
            nc = c + directions[curDire][1];
        }
        dfs(nr, nc, curDire, res, matrix);
         
    }
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        std::vector<int> res;
        ROW = matrix.size();
        COL = matrix[0].size();
        SIZE = ROW * COL;
        dfs(0, 0, 0, res, matrix);
        return res;
    }
};
